#pragma once 
#include <assert.h>
#include "FileRepository.h"
#include "Tutorial.h"

class TestFileRepository {

private:
	void TestsearchTutorial();
	void TestaddT();
	void TestupdateT();
	void TestremoveT();
	void TestgetAll();
	void TestupdateNrOfLikes();

public:
	void runAllTests();
};