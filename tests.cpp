#include "tests.h"

void runAllTestss() {
	TestTutorial().runAllTests();
	TestRepository().runAllTests();
	TestController().runAllTests();
	TestValidator().runAllTests();
	TestDynamicVector().runAllTests();
	TestWatchlist().runAllTests();
	TestUserController().runAllTests();
	TestFileRepository().runAllTests();
	TestFileWatchlist().runAllTests();
}