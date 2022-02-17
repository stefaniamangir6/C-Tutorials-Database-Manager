#pragma once 
#include <assert.h>
#include "FileWatchlist.h"
#include "Tutorial.h"

class TestFileWatchlist {

private:
	void TestsearchTutorialW();
	void TestaddTW();
	void TestremoveTW();
	void TestgetAllW();
	

public:
	void runAllTests();
};