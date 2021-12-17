#include "../unity/src/unity.h"
#include "../includes/main.h"
#include "../includes/misc.h"
#include "../includes/graphic.h"
#include "../includes/logic.h"

void begin(){
	load_file();
	initialize();
}

void test_poll_event_quit(){
	begin();
	game_state = running;
	while(game_state != quit)
	{
		poll_event();
		display_grid();
		
	}
	TEST_ASSERT_EQUAL_INT(game_state, quit);
	closing();


}


void test_poll_event_pause(){
	begin();
	game_state = running;
	while(game_state != quit){
		poll_event();
		display_grid();
		if(game_state == pause){
			break;
		}
	}
	TEST_ASSERT_EQUAL_INT(game_state, pause);
	closing();

}

void test_poll_event_play(){
	begin();
	game_state = pause;
	while (game_state != quit)
	{
		poll_event();
		display_grid();
		if(game_state == running){
			break;
		}
	}
	TEST_ASSERT_EQUAL_INT(game_state, running);
	closing();

}

void test_poll_event_enter(){
	begin();
	game_state = start;
	while (game_state != quit)
	{
		poll_event();
		if(game_state == running){
			break;

		}
		display_grid();
	}
	TEST_ASSERT_EQUAL_INT(game_state, running);
	closing();
}

void test_poll_event_r(){
	begin();
	game_state = running;
	while(game_state != quit)
	{
		poll_event();
		if(game_state == start){
			break;
		}
		display_grid();
	}	
	TEST_ASSERT_EQUAL_INT(game_state, start);
	closing();

}

void test_mouse(){
	begin();
	game_state = start;
	while(game_state != quit)
	{
		poll_event();
		if(game_state == running){
			break;
		}
		display_grid();
	}	
	TEST_ASSERT_TRUE(grid[0][0]->current_state);
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
	// press quit
	RUN_TEST(test_poll_event_quit);
	// press pause
	RUN_TEST(test_poll_event_pause);
	// press pause againg 
	RUN_TEST(test_poll_event_play);
	// press enter 
	RUN_TEST(test_poll_event_enter);
	// press reset 
	RUN_TEST(test_poll_event_r);
	// tests mouse click on cell[0][0] and close
	RUN_TEST(test_mouse);
	return UNITY_END();
}
