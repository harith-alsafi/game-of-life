#include "../unity/src/unity.h"
#include "../includes/main.h"
#include "../includes/graphic.h"
#include "../includes/logic.h"
#include <SDL2/SDL.h>

void test_initialize(){
	load_file();
	int a = initialize();
	closing();
	TEST_ASSERT_EQUAL_INT(1, a);
}

void test_display_grid(){
	load_file();
	if(initialize() == 0){return;}
	grid[0][0]->current_state = 1;
	grid[0][col-1]->current_state = 1;
	grid[row-1][0]->current_state = 1;
	grid[1][0]->current_state = 1;
	grid[2][0]->current_state = 1;
	grid[3][0]->current_state = 1;
	// shows grid for 5 seconds
	for(int i = 0; i < 5; i++)
	{
		display_grid();
		SDL_Delay(sleep_time*10);
	}
	closing();
}

void setUp() {
	 //this function is called before each test, it can be empty
}

void tearDown() {
	 //this function is called after each test, it can be empty
}

int main() {
	UNITY_BEGIN();


	RUN_TEST(test_initialize);
	RUN_TEST(test_display_grid);

	return UNITY_END();
}
