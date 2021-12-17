#include "../includes/main.h"
#include "../includes/logic.h"
#include <stdio.h>
#include <stdlib.h>

// variables
Cell *grid[max_dim][max_dim];
int row; 
int col; 
int pop; 
int alive;
int dead; 
float rate; 
int pixels; 
float base_rate;
int base_pixels;
int cell_x;
int cell_y;
int counter; // counter for alive_cells

// storing previous alive cells 
typedef struct{
    // coordinates of alive cells
    int coordinates[max_dim*max_dim][2];
    // length of array
    int length;
}AliveCells;
AliveCells *alive_cells[max_dim*max_dim];

void reset_alive_cells(int index){
    for(int i = 0; i < row*col; i++){
        alive_cells[index]->coordinates[i][0] = -1;
        alive_cells[index]->coordinates[i][1] = -1;
    }
    alive_cells[index]->length = 0;
}

void reset_all_alive_cells(){
    for(int i = 0; i < max_dim+row+col; i++){
        reset_alive_cells(i);
    }
    counter = 0;
}

void reset_grid(){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            grid[i][j]->current_state = 0;
            grid[i][j]->next_state = 0;
        }
    }

    alive = 0;
    pop = col*row;
    dead = pop;
}

int load_file(){
    FILE* file;
    file = fopen("res/initial.txt", "r");

    if(file == NULL){
        printf("Error: file \'initial.txt\' was not found \n");
        return 0;
    }

    fscanf(file, "%*[^\n]"); // ignores first line
    fscanf(file, "%i \t %i \t %f \t %i", &row, &col, &rate, &pixels);

    // rows and cols
    if(row > max_dim || col > max_dim){
        printf("Error: given dimenstions are too large \n");
        return 0;
    }

    // checking pixels
    if(pixels < 1){
        printf("Error: pixels must be positive integer value \n");
        return 0;
    }

    // default cells
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            grid[i][j] = (Cell*)malloc(sizeof(Cell));
            grid[i][j]->current_state = 0;
            grid[i][j]->next_state = 0;
        }
    }

    // alive cells 
    for(int i = 0; i < max_dim+row+col; i++){
        alive_cells[i] = (AliveCells*)malloc(sizeof(AliveCells));
        reset_alive_cells(i);
    }
    counter = 0;

    // population count 
    alive = 0;
    pop = col*row;
    dead = pop;

    // pixels and rate 
    base_rate = rate;
    base_pixels = pixels;

    // cursor positions 
    cell_x = 0;
    cell_y = 0;

    fclose(file);
    return 1;
}

int store_file(){
    FILE* file; 
    file = fopen("res/final.txt", "w");

    if(file == NULL){
        printf("Error: file \'final.txt\' could not be open \n");
        return 0;
    }


    fprintf(file, "# alive dead row col \n");
    fprintf(file, "%i %i %i %i \n", alive, dead, row, col);

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            fprintf(file, "%i \t", grid[i][j]->current_state);
        }
        fprintf(file, "\n");
    }

    fclose(file);
    return 1;
}

int restore_stored_file(){
    FILE* file; 
    file = fopen("res/final.txt", "r");

    if(file == NULL){
        printf("Error: file \'final.txt\' was not found \n");
        return 0;
    }

    int check_row = 0;
    int check_col = 0;

    fscanf(file, "%*[^\n]"); // ignores first line
    fscanf(file, "%i %i %i %i \n", &alive, &dead, &check_row, &check_col);

    // file similarity checking 
    if(alive+dead != pop || check_row != row || check_col != col){
        printf("Error: files \'initial.txt\' and \'final.txt\' don\'t match in details \n");
        return 0;
    }

    // assigning the values 
    reset_all_alive_cells();
    reset_grid();

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            fscanf(file, "%i", &grid[i][j]->current_state);
        }
    }

    get_population();

    fclose(file);
    return 1;
}

int get_neighbours(int x, int y){
    int neighbours = 0;

    int min_x = MAX(x-1, 0); // min i
    int min_y = MAX(y-1, 0); // min j
    int max_x = MIN(x+1, row-1); // max i 
    int max_y = MIN(y+1, col-1); // max j

    for(int i = min_x; i <= max_x; i++){
        for(int j = min_y; j <= max_y; j++){
            if(!(i == x && j == y) && grid[i][j]->current_state){
                neighbours++;
            }      
        }
    }

    return neighbours;
}

void get_population(){
    alive = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            // counting the alive
            grid[i][j]->current_state?alive++: alive;
        }
    }
    dead = pop-alive;
}

void reshape_grid(){
    // storing previous state
    if(counter < max_dim+row+col && counter >= 0){
        int k = 0;
        reset_alive_cells(counter);
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j]->current_state){
                    alive_cells[counter]->coordinates[k][0] = i;
                    alive_cells[counter]->coordinates[k][1] = j;
                    alive_cells[counter]->length++;
                    k++;
                }
            }
        }
        counter++;
    }
    // if we exceed the max we reset the counter 
    else{
        counter = 0;
    }

    // going through rules
    int neighbours = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            neighbours = get_neighbours(i, j);
            // rule-1
            if(grid[i][j]->current_state && (neighbours == 0 || neighbours == 1)){
                grid[i][j]->next_state = 0;
            }
            // rule-2 
            if(grid[i][j]->current_state && (neighbours == 2 || neighbours == 3)){
                grid[i][j]->next_state = 1;
            }
            // rule-3
            if(grid[i][j]->current_state && neighbours > 3){
                grid[i][j]->next_state = 0;
            }
            // rule-4
            if(!grid[i][j]->current_state && neighbours == 3){
                grid[i][j]->next_state = 1;
            }
        }
    }

    // assigning for next_state iteration 
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            grid[i][j]->current_state = grid[i][j]->next_state;
            grid[i][j]->next_state = 0;
        }
    }

    get_population();
}

void undo_reshape(){
    counter--;
    if(counter < max_dim+row+col && counter >= 0){
        reset_grid();
        for(int i = 0; i < alive_cells[counter]->length; i++){
            grid[alive_cells[counter]->coordinates[i][0]]
            [alive_cells[counter]->coordinates[i][1]]->current_state = 1;
        }
        get_population();
    }
    else{
        counter = 0;
    }

}

void cleanup(){
    // default cells
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            free(grid[i][j]);
        }
    }

    // alive cells 
    for(int i = 0; i < max_dim+row+col; i++){
        free(alive_cells[i]);
    }
}