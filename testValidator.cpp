#include "testValidator.h"

void TestValidator::runAllTests() {

	TestValidate();
}

void TestValidator::TestValidate() {

	Validator v = Validator();
	
	try
	{
		v.validate("a", "You", 3, 2, 12, "https:abc");
	}
	catch (ValidatorException& e) {
		assert(true);
	}

	try
	{
		v.validate("C", "You", 3, 2, 12, "abc");

	}
	catch (ValidatorException& e) {
		assert(true);
	}

	try
	{
		v.validate("", "", 3, 2, 12, "https:abc");

	}
	catch (ValidatorException& e) {
		assert(true);
	}

	try
	{
		v.validate("C", "You", -3, -2, -12, "https:abc");;
	}
	catch (ValidatorException& e) {
		assert(true);
	}

	try
	{
		v.validate("a", "ou", -93, -2, -12, "htps:abc");
	}
	catch (ValidatorException& e) {
		assert(true);
	}

	try
	{
		v.validate("C", "You", 3, 62, 62, "https:abc");

	}
	catch (ValidatorException& e) {
		assert(e.getMessage() == "The number representing the seconds must be a positive number smaller tha 60!\n");
	}

	int res = v.validate("A", "V", 33, 2, 12, "https:abc");
	assert(res == 1);
}