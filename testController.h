#pragma once 
#include <assert.h>
#include "Repository.h"
#include "DynamicVector.h"
#include "Tutorial.h"
#include "AdminController.h"

class TestController {

private:
	void TestaddTutorial();
	void TestupdateTutorial();
	void TestremoveTutorial();
	void TestGetAll();
	void TestFileRepo();

public:
	void runAllTests();
};