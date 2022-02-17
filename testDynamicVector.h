#pragma once 
#include <assert.h>
#include "DynamicVector.h"
#include "Tutorial.h"

class TestDynamicVector {

private:
	void TestSize();
	void Testadd();
	void Testupdate();
	void Testremove();
	void TestOperator();


public:
	void runAllTests();
};