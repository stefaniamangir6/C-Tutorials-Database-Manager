#include "testUserController.h"

void TestUserController::runAllTests() {

	TestaddTutorial();
	TestremoveTutorial();
	TestGetAll();
	TestRateTutorial();
	TestshowTutorialsOfGivenPresenterUC();
	//TestFileRepo();

}

void TestUserController::TestaddTutorial() {

	Repo repo;
	UserRepo r;
	UserController c = UserController(repo, r);


	Duration newDuration{ 56,33 };
	Tutorial newTutorial{ "C++ Tutorial For Beginners", "FreeCodeCamp", newDuration, 1500, "https:abc" };

	int result = c.addToWatchList(newTutorial);

	assert(result == 1);

	try {
		c.addToWatchList(newTutorial);
		assert(false);
	}
	catch (RepositoryException& re) {
		assert(re.getMessage() == "Existing Tutorial!\n");
	}


}

void TestUserController::TestremoveTutorial() {



	Repo repo;
	UserRepo r;
	UserController c = UserController(repo, r);
	

	Duration newDuration{ 56,33 };
	Tutorial newTutorial{ "C++ Tutorial For Beginners", "FreeCodeCamp", newDuration, 1500, "https:abc" };
	c.addToWatchList(newTutorial);

	int res;
	res = c.removeTutorialUC("https:abc");
	assert(res == 1);

	try {
		c.removeTutorialUC("https:aaa");
		assert(false);
	}
	catch (RepositoryException& re) {
		assert(re.getMessage() == "This Tutorial does not exist!\n");
	}


}

void TestUserController::TestGetAll()
{

	Repo repo;
	UserRepo r;
	UserController c = UserController(repo, r);

	Duration newDuration{ 56,33 };
	Tutorial newTutorial{ "C++ Tutorial For Beginners", "FreeCodeCamp", newDuration, 1500, "https:abc" };
	c.addToWatchList(newTutorial);

	std::vector<TElem> v = c.getAllUC();
	assert(v.size() == 1);
	assert(v[0] == newTutorial);

}

void TestUserController::TestRateTutorial() {

	Repo repo;
	UserRepo r;
	UserController c = UserController(repo, r);

	Duration newDuration{ 56,33 };
	Tutorial newTutorial{ "C++ Tutorial For Beginners", "FreeCodeCamp", newDuration, 1500, "https:abc" };
	repo.addT(newTutorial);

	c.rateTutorial("https:abc");
	assert(repo.getAll()[0].getLikes() == 1501);
}

void TestUserController::TestshowTutorialsOfGivenPresenterUC() {

	std::vector<TElem> a, b;
	Repo repo;
	UserRepo r;
	UserController c = UserController(repo, r);

	Duration newDuration{ 56,33 };
	Tutorial newTutorial{ "C++ Tutorial For Beginners", "FreeCodeCamp", newDuration, 1500, "https:abc" };
	repo.addT(newTutorial);

	Tutorial newTutorial1{ "C++", "FreeCodeCamp", newDuration, 1500, "https:aaa" };
	repo.addT(newTutorial1);

	Tutorial newTutorial2{ "C", "CodeBeauty", newDuration, 1200, "https:bbb" };
	repo.addT(newTutorial2);

	std::vector<TElem> filtered;
	filtered = c.showTutorialsOfGivenPresenterUC("FreeCodeCamp");
	assert(filtered.size() == 2);
	assert(filtered[0] == newTutorial);
	assert(filtered[1] == newTutorial1);

	std::vector<TElem> filtered1;
	filtered1 = c.showTutorialsOfGivenPresenterUC("CodeBeauty");
	assert(filtered1.size() == 1);
	assert(filtered1[0] == newTutorial2);

	std::vector<TElem> filtered2;
	filtered2 = c.showTutorialsOfGivenPresenterUC("sdhbk");
	assert(filtered2.size() == 0);



}
/*void TestUserController::TestFileRepo() {

	std::vector<TElem> a, b;
	Repo repo = Repo(b);
	UserRepo r = UserRepo(a);
	UserController c = UserController(repo, r);
	char fileName[100] = {};
	strcpy_s(fileName, "testTutorials1.txt");
	c.load(fileName);
	assert(a.size() == 2);

	Duration newDuration{ 22,33 };
	Tutorial newTutorial{ "C++ Tutorial", "Me", newDuration, 1000, "https:abc" };

	Duration newDuration1{ 11,22 };
	Tutorial newTutorial1{ "C Tutorial 2020", "You", newDuration1, 333, "https:aaa" };

	assert(a[0] == newTutorial);
	assert(a[1] == newTutorial1);
	c.save(fileName);


}*/

