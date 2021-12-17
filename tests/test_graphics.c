#include "unity/src/unity.h"
#include "src/main.h"

// void test_a_function() {
// 	add__books("Engineering", "john smith", 2020, 40);
// 	int a = find_books__year(2020);
// 	TEST_ASSERT_EQUAL_INT(1, a);
// }

void setUp() {
	 //this function is called before each test, it can be empty
}

void tearDown() {
	 //this function is called after each test, it can be empty
}

int main() {
	UNITY_BEGIN();


	// RUN_TEST(test_a_function);

	return UNITY_END();
}
