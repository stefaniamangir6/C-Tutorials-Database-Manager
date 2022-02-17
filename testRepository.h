#pragma once 
#include <assert.h>
#include "Repository.h"
#include "DynamicVector.h"
#include "Tutorial.h"

class TestRepository {

private:
	void TestsearchTutorial();
	void TestaddT();
	void TestupdateT();
	void TestremoveT();
	void TestgetAll();
	void TestupdateNrOfLikes();
	void TestFileRepo();

public:
	void runAllTests();
};