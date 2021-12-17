#ifndef GRAPHIC_GUARD__H
#define GRAPHIC_GUARD__H

/**
* Initializes SDL
* Initializes SDL_ttf
* Initializes the window 
* Initializes the font
* returns 1 if everything goes right
* returns 0 if something goes wrong
* Will print a message about what went wrong
*/
int initialize(); // initial commands 

/**
* Displays the cells
* Displays the text (alive, dead, rate, zoom, cell-coord)
* Adjusts the main box and text box while zooming
*/ 
void display_grid();

/**
* Converts the window coordinates into cell coordinates
* Assigne the cell coordinate with given val
*/
void mouse_press(int x, int y, int val);

/**
* Closes all SDL components
*/
void closing();
#endif