#ifndef LOGIC_GUARD__H
#define LOGIC_GUARD__H

/**
* - Loads the initial configurations from a file "initial.txt"
* - The file will have the following format:
* # row col rate pixels
* - return 1 if loading the file went correctly
* - return 0 if loading the file failed
* - return 0 if initial.txt rows are more than max dimension
*/
int load_file(); 

/**
* - Saves the final state to a file "final.txt"
* - The file will have the following format:
* # alive dead pop
* shape of the world 
* calls reset_grid()
* calls reset_alive_cells()
* - return 1 if loading the file went correctly
* - return 0 if loading the file failed
*/
int store_file(); // stores last state to file 

/**
* - Calculates the number of neighbouring alive cell
* - param x is the x-coordinate of the cell
* - param y is the y-coordinate of the cell
* - returns > 0 if there are cells that are alive
* - return 0 if there are no alive cells
*/
int get_neighbours(int x, int y); 

/**
* - stores the coordinates of alive cells before updating
* - updates the next state of the cells based on conways rules
* - updates the current cell states 
* - calls get_population()
*/
void reshape_grid();

/**
* - counts the number of alive and dead cells
*/
void get_population();

/**
* - resets alive_cells in logic.c by assigning:
* coordinates -> -1
* length -> 0
* - takes index of alive_cells to reset it
*/
void reset_alive_cells(int index);

/**
* - resets the grid by assiging everything to 0
*/
void reset_grid();

/**
* - restores the previous state of the grid by:
* calling reset_grid()
* assigning the grid values to coordinates in alive_cells
* calling get_population()
*/
void undo_reshape();

/**
* - restores final state of store_file() if requested by the user
* - return 1 if all is fine 
* - return 0 if file was not found 
* - return 0 if final.txt doesnt match initial.txt
*/
int restore_stored_file();

/**
* - resets all alive_cells 
*/
void reset_all_alive_cells();

/**
* - frees memory of grid
* - frees memory of alive_cells
*/
void cleanup();

#endif