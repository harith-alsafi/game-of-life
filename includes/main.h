#ifndef MAIN_GUARD__H
#define MAIN_GUARD__H

// constants
#define max_dim 500 // max dimension 
#define sleep_time 100 // base rate for SDL_DELAY 
#define MAX(a, b) (a>b)?a:b // min between a,b
#define MIN(a, b) (a<b)?a:b // max between a,b

/**
* - current_state = 1 -> cell is alive
* - current_state = 0 -> cell is dead
* - next_state = 1 -> cell will become alive
* - next_state = 0 -> cell will become dead
*/
typedef struct{
    int current_state;
    int next_state; // cell state on next iteration  
} Cell;

// program state 
typedef enum{
    start,
    running,
    pause,
    quit
} State;

// extern variables 
extern State game_state; // program state 
extern Cell *grid[max_dim][max_dim]; // all cells grid[x][y] 
extern int row; // number of cells in rows (x) -> y-cord in SDL
extern int col; // number of cells in colums (y) -> x-cord in SDL
extern int pop; // total number of cells 
extern int alive; // number of alive cells  
extern int dead; // number of dead cells 
extern int pixels; // pixels per cell (default = 10)
extern float rate; // rate > 1 faster, rate < 1 slower (default = 1)
extern float base_rate; // stores base_rate from file
extern int base_pixels; // stores base pixels from file
extern int cell_x; // cursor at x
extern int cell_y; // cursor at y

#endif