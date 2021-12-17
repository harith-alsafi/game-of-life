#include "../includes/graphic.h"
#include "../includes/main.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>

#define font_size 24
#define text_height 40
#define min_width 750

// SDL variables
SDL_Window* window= NULL; // window 
SDL_Renderer* renderer = NULL; // rendering 
TTF_Font* font = NULL; // font
SDL_Color alivecolor = {255, 255, 255}; //alive cell color
SDL_Color deadcolor = {23, 23, 23}; // dead cell color 
SDL_Color textbox = {0, 230, 255}; // text rectangle color
SDL_Color fontcolor = {255, 255, 255}; // font color
SDL_DisplayMode mode; // to get screen size

// variables
int width;
int height;

int initialize(){
    // font 
    if(TTF_Init() != 0){
        printf ("Error: initializing SDL_ttf failed:  %s\n", TTF_GetError());
        return 0;
    }

    font = TTF_OpenFont("res/arial.ttf", font_size);

    if(font == NULL){
        printf("Error: font \'arial.ttf \' was not found \n");
        return 0;
    }

    // window size realtive to screen size 
    if (SDL_Init(SDL_INIT_VIDEO) != 0)  {
        printf ("Error: initializing SDL failed:  %s\n", SDL_GetError());
        return 0;
    }
    
    SDL_GetDesktopDisplayMode(0, &mode);
    width = MIN(MAX(col*base_pixels, min_width), mode.w);
    height = mode.h-text_height;

    // window 
    window = SDL_CreateWindow("Game of life", 
    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
    width , MIN(height, row*base_pixels+text_height), 
    SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_ShowWindow(window);

    if(window == NULL){
        printf("Could not load window \n");
        return 0;
    }

    return 1;
}

void mouse_press(int x, int y, int val){
    // inverted y with x so SDL shows row+cols correctly
    int i = y/pixels;
    int j = x/pixels;

    // checking 
    if(i < row && j < col){
        grid[i][j]->current_state = val;
    }
}

void display_grid(){
    // pixel adjustable height and width
    int width_grid;
    int height_grid;

    // dead cells 
    SDL_SetRenderDrawColor(renderer, deadcolor.r, deadcolor.g, deadcolor.b, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    
    // changing height as we zoom
    height_grid = MIN(row*pixels, height)-text_height;

    // text rectangle 
    width_grid = MIN(MAX(col*pixels,min_width), mode.w); // change width as we zoom
    SDL_SetRenderDrawColor(renderer, textbox.r, textbox.g, textbox.b, SDL_ALPHA_OPAQUE);
    SDL_Rect text_rect = {0, height_grid, width_grid, text_height};
    SDL_RenderFillRect(renderer, &text_rect);

    // main rectangle 
    width_grid = MIN(col*pixels, mode.w); // change width as we zoom 
    SDL_SetRenderDrawColor(renderer, alivecolor.r, alivecolor.g, alivecolor.b, SDL_ALPHA_OPAQUE);
    SDL_Rect main_rect = {0, 0, width_grid, height_grid};
    SDL_RenderDrawRect(renderer, &main_rect);

    // alive cells
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){

            // protects from overdrawing while zooming
            if(i*pixels+pixels <= height-text_height*0.9){
                // only alive cells
                if(grid[i][j]->current_state){
                    SDL_Rect cell = {j*pixels, i*pixels, pixels,pixels};
                    SDL_RenderFillRect(renderer, &cell);
                }

            }
        }
    }

    // text box for alive and dead cells
    char str[100];
    sprintf(str, " Alive: %i    Dead: %i    Rate: %.1f    Zoom: %.1f    Cell: [%i, %i] ", alive, dead, rate, (float)pixels/base_pixels*100, cell_x, cell_y);

    SDL_Surface* fontsurface = TTF_RenderText_Solid(font, str, fontcolor);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, fontsurface);
    
    int textW = 0; // width
    int textH = 0; // height
    SDL_QueryTexture(texture, NULL, NULL, &textW, &textH);

    SDL_Rect fontdim = {0, height_grid, textW, textH};
    SDL_RenderCopy(renderer, texture, NULL, &fontdim);

    // displaying everything
    SDL_RenderPresent(renderer);

    // freeing texture and surface for next iteration 
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(fontsurface);
}

void closing(){
    // render and window
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    // font
    TTF_CloseFont(font);
    TTF_Quit();
}