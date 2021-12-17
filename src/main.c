#include "../includes/main.h"
#include "../includes/graphic.h"
#include "../includes/logic.h"
#include "../includes/misc.h"
#include <SDL2/SDL.h>

int main()
{
    // initials
    if(load_file() != 1 || initialize() != 1){
        return 0;
    }

    // program 
    while(game_state != quit)
    {
        // events
        poll_event();

        // reshape 
        if(game_state == running){
            reshape_grid();
            SDL_Delay(sleep_time/rate);
        }

        // displaying 
        get_population();   
        display_grid();
    }

    // final 
    closing();
    cleanup();
    return 1;
}