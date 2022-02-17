#include "testWatchlist.h"

void TestWatchlist::runAllTests() {

	TestsearchTutorialW();
	TestaddTW();
	TestremoveTW();
	TestgetAllW();
	//TestFileRepo();
}

void TestWatchlist::TestaddTW() {

	std::vector<TElem> v;
	UserRepo r;
	Duration newDuration{ 33,22 };
	Tutorial newTutorial{ "C++", "Me", newDuration, 1200, "https:abc" };
	int result = r.UaddT(newTutorial);
	assert(result == 1);

	Duration newDur{ 22,42 };
	Tutorial newTut{ "C", "Me", newDur, 120, "https:abc" };

	try {
		r.UaddT(newTut);
		assert(false);
	}
	catch (RepositoryException& re) {
		assert(re.getMessage() == "Existing Tutorial!\n");
	}

}

void TestWatchlist::TestsearchTutorialW() {

	std::vector<TElem> v;
	UserRepo r;
	Duration newDuration{ 33,22 };
	Tutorial newTutorial{ "C++", "Me", newDuration, 1200, "https:abc" };
	r.UaddT(newTutorial);
	try {
		r.searchTutorialU("https:ooo");
		assert(false);
	}
	catch (RepositoryException& re) {
		assert(re.getMessage() == "This Tutorial does not exist!\n");
	}

	Duration newDur{ 33,22 };
	Tutorial newTut{ "C++", "Me", newDur, 1200, "https:def" };
	r.UaddT(newTut);
	auto tutorial = r.searchTutorialU("https:def");
	assert(tutorial == newTut);
}

void TestWatchlist::TestremoveTW() {

	std::vector<TElem> v;
	UserRepo r;
	Duration newDuration{ 33,22 };
	Tutorial newTutorial{ "C++", "Me", newDuration, 1200, "https:abc" };
	r.UaddT(newTutorial);

	int rr;

	try {
		 assert(r.UremoveT("https:aaa") == 0);
	}
	catch (RepositoryException& re) {
		assert(re.getMessage() == "This Tutorial does not exist!\n");
	}
	int res;
	res = r.UremoveT("https:abc");
	assert(res == 1);


}


void TestWatchlist::TestgetAllW()
{
	std::vector<TElem> a;
	UserRepo r;
	Duration newDuration{ 33,22 };
	Tutorial newTutorial{ "C++", "Me", newDuration, 1200, "https:abc" };
	r.UaddT(newTutorial);

	std::vector<TElem> v = r.UgetAll();
	assert(v.size() == 1);
	assert(v[0] == newTutorial);

}

/*void TestWatchlist::TestFileRepo() {

	std::vector<TElem> a;
	UserRepo r = UserRepo(a);
	char fileName[100] = {};
	strcpy_s(fileName, "testTutorials1.txt");
	r.loadFromFile(fileName);
	assert(a.sizee() == 2);

	Duration newDuration{ 22,33 };
	Tutorial newTutorial{ "C++ Tutorial", "Me", newDuration, 1000, "https:abc" };

	Duration newDuration1{ 11,22 };
	Tutorial newTutorial1{ "C Tutorial 2020", "You", newDuration1, 333, "https:aaa" };

	assert(a[0] == newTutorial);
	assert(a[1] == newTutorial1);
	r.saveToFile(fileName);


}*/