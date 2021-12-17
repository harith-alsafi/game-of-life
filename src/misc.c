#include "../includes/main.h"
#include "../includes/logic.h"
#include "../includes/misc.h"
#include "../includes/graphic.h"
#include <SDL2/SDL.h>

State game_state = start;

void poll_event(){
    SDL_Event event;

    while(SDL_PollEvent(&event))
    {
        // exit 
        if(event.type == SDL_QUIT){
            game_state = quit;
            // break;
        }

        // keys 
        if(event.type == SDL_KEYDOWN){

            // enter-run
            if(event.key.keysym.sym == SDLK_RETURN){
                game_state = running;
                break;
            }

            // r-reset
            if(event.key.keysym.sym == SDLK_r){
                game_state = start;
                reset_grid();
                reset_all_alive_cells();
                break;
            }

            // pausing
            if(game_state == running || game_state == pause){
                
                // space-pause
                if(event.key.keysym.sym == SDLK_SPACE){

                    if(game_state == running){
                        game_state = pause;
                    }
                    else{
                        game_state = running;
                    }
                    break;
                }

                // paused shortcuts
                if(game_state == pause){

                    // right-arrow
                    if(event.key.keysym.sym == SDLK_RIGHT){
                        reshape_grid();
                        break;
                    }

                    // left arrow 
                    if(event.key.keysym.sym == SDLK_LEFT){
                        undo_reshape();
                        break;
                    }
                }
            }

            // o-opening file
            if(game_state == start){
                if(event.key.keysym.sym == SDLK_o){
                    int check = restore_stored_file();

                    //  error checking 
                    if(check == 0 || check == -1){
                        break;
                    }
                    game_state = start;
                    break;
                }
            }

            // s-save 
            if(game_state == start || game_state == pause){
                if(event.key.keysym.sym == SDLK_s){
                    store_file();
                    break;
                }
            }

            // q-resets pixels and rate
            if(event.key.keysym.sym == SDLK_q){
                pixels = base_pixels;
                rate = base_rate;
            }

            // up-arrow 
            if(event.key.keysym.sym == SDLK_UP){
                rate += 0.1;
            }

            // down-arrow
            if(event.key.keysym.sym == SDLK_DOWN){
                rate -= 0.1;
            }
        }

        // normal drawing
        if(event.type == SDL_MOUSEBUTTONDOWN){

            if(game_state == start || game_state == pause){
                if (event.button.button == SDL_BUTTON_LEFT){
                    mouse_press(event.button.x, event.button.y, 1);
                    break;
                }

                // right-dead
                if (event.button.button == SDL_BUTTON_RIGHT){
                    mouse_press(event.button.x, event.button.y, 0);
                    break;
                }
            }
        }


        // wheel 
        if(event.type == SDL_MOUSEWHEEL){

            // scroll up
            if(event.wheel.y > 0){
                if(pixels+1 < max_dim/5){
                    pixels++;
                }
            }

            // scroll down
            if(event.wheel.y < 0){
                if(pixels-1 > 1){
                    pixels--;
                }
            }
        }

        // motion drawing
        if(event.type == SDL_MOUSEMOTION){
            // location
            cell_x = event.motion.y/pixels;
            cell_y = event.motion.x/pixels;

            // hold drawing
            if(game_state == start || game_state == pause){
                if (event.button.button == SDL_BUTTON_LEFT){
                    mouse_press(event.button.x, event.button.y, 1);
                    break;
                }
            }
        }
    }
}