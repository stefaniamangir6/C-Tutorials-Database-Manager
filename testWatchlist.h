#pragma once 
#include <assert.h>
#include "Watchlist.h"
#include "DynamicVector.h"
#include "Tutorial.h"

class TestWatchlist {

private:
	void TestsearchTutorialW();
	void TestaddTW();
	void TestremoveTW();
	void TestgetAllW();
	void TestFileRepo();

public:
	void runAllTests();
};