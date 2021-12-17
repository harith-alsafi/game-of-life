#include "../unity/src/unity.h"
#include "../includes/main.h"
#include "../includes/logic.h"

void initial(){
	load_file();
	grid[2][2]->current_state = 0;
	grid[3][2]->current_state = 1;
	grid[2][3]->current_state = 1;
	grid[1][2]->current_state = 1;
}

void test_load_file() {
	int a = load_file();
	TEST_ASSERT_EQUAL_INT(1, a);
	TEST_ASSERT_EQUAL_INT(20, row);
	TEST_ASSERT_EQUAL_INT(75, col);
	TEST_ASSERT_EQUAL_FLOAT(1.0, rate);
	TEST_ASSERT_EQUAL_INT(10, pixels);
	TEST_ASSERT_NOT_NULL(grid[0][0]);
}

void test_store_file(){
	initial();
	int a = store_file();
	TEST_ASSERT_EQUAL_INT(1, a);
}

void test_get_neighbours(){

	// test-2
	grid[0][0]->current_state = 1;
	grid[0][1]->current_state = 1;
	grid[1][0]->current_state = 1;
	int b = get_neighbours(0, 0);

	// test-3
	grid[4][4]->current_state = 1;
	grid[4][5]->current_state = 1;
	grid[4][3]->current_state = 1;
	int c = get_neighbours(4, 4);

	TEST_ASSERT_EQUAL_INT(2, b);
	TEST_ASSERT_EQUAL_INT(2, c);
}

void test_reshape_grid(){
	initial();
	// reshape-1, + get population 
	reshape_grid();
	TEST_ASSERT_TRUE(grid[2][2]->current_state);
	TEST_ASSERT_FALSE(grid[3][2]->current_state);
	TEST_ASSERT_EQUAL_INT(2, alive);
	TEST_ASSERT_EQUAL_INT(pop-alive, dead);
	// reshape-2 + get population
	reshape_grid();
	TEST_ASSERT_EQUAL_INT(0, alive);
	TEST_ASSERT_EQUAL_INT(pop, dead);
}

void test_undo_reshape(){
	initial(); 
	reshape_grid();
	TEST_ASSERT_TRUE(grid[2][2]->current_state);
	TEST_ASSERT_FALSE(grid[3][2]->current_state);
	TEST_ASSERT_EQUAL_INT(2, alive);
	undo_reshape();
	TEST_ASSERT_FALSE(grid[2][2]->current_state);
	TEST_ASSERT_TRUE(grid[2][3]->current_state);
	TEST_ASSERT_EQUAL_INT(3, alive);
}

void test_restore_stored_file(){
	initial();
	test_get_neighbours();

	store_file();

	reset_all_alive_cells();
	reset_grid();

	restore_stored_file();

	test_get_neighbours();

	TEST_ASSERT_FALSE(grid[2][2]->current_state);
	TEST_ASSERT_TRUE(grid[3][2]->current_state);
	TEST_ASSERT_TRUE(grid[2][3]->current_state);
	TEST_ASSERT_TRUE(grid[1][2]->current_state);

	reshape_grid();
}


void test_seg_fault(){
	initial();
	int i = 0; 
	// reshape 
	while(i < 2*max_dim+row+col){
		reshape_grid();
		i++;
	}
	// undo reshape 
	i = 0;
	while(i < 2*max_dim+row+col){
		undo_reshape();
		i++;
	}
}

void setUp() {
	 //this function is called before each test, it can be empty
}

void tearDown() {
	 //this function is called after each test, it can be empty
}

int main() {
	UNITY_BEGIN();
	RUN_TEST(test_load_file);
	RUN_TEST(test_store_file);
	RUN_TEST(test_get_neighbours);
	RUN_TEST(test_reshape_grid);
	RUN_TEST(test_undo_reshape);
	RUN_TEST(test_restore_stored_file);
	RUN_TEST(test_seg_fault);
	return UNITY_END();
}
