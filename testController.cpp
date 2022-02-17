#include "testController.h"

void TestController::runAllTests() {

	TestaddTutorial();
	TestupdateTutorial();
	TestremoveTutorial();
	TestGetAll();
	//TestFileRepo();
}

void TestController::TestaddTutorial() {

	std::vector<TElem> v;
	Repo r;
	Validator valid;
	AdminController c = AdminController(r, valid);
	std::string title, presenter, link;
	int minutes, seconds;
	double likes;

	title = "C++ Tutorial For Beginners";
	presenter = "FreeCodeCamp";
	likes = 1500;
	minutes = 56;
	seconds = 33;
	link = "https://www.youtube.com/watch?v=vLnPwxZdW4Y&t=4807s";
	int result = c.addTutorial(title, presenter, minutes, seconds, likes, link);

	assert(result == 1);


	try {
		c.addTutorial(title, presenter, minutes, seconds, likes, link);
		assert(false);
	}
	catch (RepositoryException& re) {
			assert(re.getMessage() == "Existing Tutorial!\n");
		}

}

void TestController::TestremoveTutorial() {


	std::vector<TElem> v;
	Repo r;
	Validator valid;
	AdminController c = AdminController(r, valid);
	std::string title, presenter, link;
	int minutes, seconds;
	double likes;

	title = "C++ Tutorial For Beginners";
	presenter = "FreeCodeCamp";
	likes = 1500;
	minutes = 56;
	seconds = 33;
	link = "https:abc";
	c.addTutorial(title, presenter, minutes, seconds, likes, link);


	int res;
	res = c.removeTutorial("https:abc");
	assert(res == 1);

	try {
		c.removeTutorial("https:aaa");
		assert(false);
	}
	catch (RepositoryException& re) {
		assert(re.getMessage() == "This Tutorial does not exist!\n");
	}




}

void TestController::TestupdateTutorial() {



	std::vector<TElem> v;
	Repo r;
	Validator valid;
	AdminController c = AdminController(r, valid);
	std::string title, presenter, link;
	int minutes, seconds;
	double likes;

	title = "C++ Tutorial For Beginners";
	presenter = "FreeCodeCamp";
	likes = 1500;
	minutes = 56;
	seconds = 33;
	link = "https:abc";
	c.addTutorial(title, presenter, minutes, seconds, likes, link);


	int res;
	res = c.updateTutorial("C", "You", 3, 2, 12, "https:abc");
	assert(res == 1);

	try {
		c.updateTutorial("C", "You", 1, 2, 12, "https:aaa");
		assert(false);
	}
	catch (RepositoryException& re) {
		assert(re.getMessage() == "This Tutorial does not exist!\n");
	}


	


}

void TestController::TestGetAll()
{

	std::vector<TElem> a;
	Repo r;
	Validator valid;
	AdminController c = AdminController(r, valid);
	std::string title, presenter, link;
	int minutes, seconds;
	double likes;

	title = "C++ Tutorial For Beginners";
	presenter = "FreeCodeCamp";
	likes = 1500;
	minutes = 56;
	seconds = 33;
	link = "https:abc";
	c.addTutorial(title, presenter, minutes, seconds, likes, link);

	Duration newDuration{ 56,33 };
	Tutorial newTutorial{ "C++ Tutorial For Beginners", "FreeCodeCamp", newDuration, 1500, "https:abc" };

	std::vector<TElem> v = c.getAllC();
	assert(v.size() == 1);
	assert(v[0] == newTutorial);

}

/*void TestController::TestFileRepo() {

	DynamicVector<TElem> a;
	Repo r = Repo(a);
	Validator valid;
	AdminController c = AdminController(r, valid);
	char fileName[100] = {};
	strcpy_s(fileName, "testTutorials.txt");
	c.load(fileName);
	assert(a.sizee() == 2);

	Duration newDuration{ 22,33 };
	Tutorial newTutorial{ "C++ Tutorial", "Me", newDuration, 1000, "https:abc" };

	Duration newDuration1{ 11,22 };
	Tutorial newTutorial1{ "C Tutorial 2020", "You", newDuration1, 333, "https:aaa" };

	assert(a[0] == newTutorial);
	assert(a[1] == newTutorial1);
	c.save(fileName);


}*/