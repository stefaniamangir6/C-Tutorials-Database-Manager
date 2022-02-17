#pragma once 
#include <assert.h>
#include "Repository.h"
#include "DynamicVector.h"
#include "Tutorial.h"
#include "UserController.h"
#include "Watchlist.h"

class TestUserController {

private:
	void TestaddTutorial();
	void TestremoveTutorial();
	void TestGetAll();
	void TestRateTutorial();
	void TestshowTutorialsOfGivenPresenterUC();
	void TestFileRepo();

public:
	void runAllTests();
};