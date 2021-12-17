#ifndef MISC_GUARD__H
#define MISC_GUARD__H

/**
* - Processes all key and mouse presses 
* - Quit button -> game_state = quit
* -------------------------------------
* GENERAL STATE SHORTCUTS
* - Enter key -> game_state = running
* - R key -> game_state = start
* calls reset_alive_cells()
* calls reset_grid() 
* - Q key -> resets pixels and rate
* - up-arrow -> increments rate by 0.1
* - down-arrow -> decrements rate by 0.1
* -------------------------------------
* PAUSED SHORTCUTS
* - space -> game_state = running -> game_state = pause
* - space -> game_state = pause -> game_state = running
* - right-arrow -> calls reshape_grid()
* - left-arrow -> calls undo_reshap()
* -------------------------------------
* START STATE SHORTCUTS
* - S key -> calls store_file()
* - O key -> calls restore_stored_file()
* -------------------------------------
* MOUSE SHORTCUTS 
* - wheelp-up -> incements pixels by 1
* - wheel-down -> decrements pixels by 1
* - left-click -> alive cell
* - right-click -> dead cell
*/
void poll_event();
#endif