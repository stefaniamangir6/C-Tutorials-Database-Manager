#include "FileRepoWatchlist.h"

void TestFileWatchlist::runAllTests() {

	TestsearchTutorialW();
	TestaddTW();
	TestremoveTW();
	TestgetAllW();

}

void TestFileWatchlist::TestaddTW() {

	std::vector<TElem> v;
	FileWatchlist r("testTutorials1.txt");
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

void TestFileWatchlist::TestsearchTutorialW() {

	std::vector<TElem> v;
	FileWatchlist r("testTutorials1.txt");
	Duration newDuration{ 33,22 };
	Tutorial newTutorial{ "C++", "Me", newDuration, 1200, "https:abbc" };
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

void TestFileWatchlist::TestremoveTW() {

	std::vector<TElem> v;
	FileWatchlist r("testTutorials1.txt");
	Duration newDuration{ 33,22 };
	Tutorial newTutorial{ "C++", "Me", newDuration, 1200, "https:aaabc" };
	r.UaddT(newTutorial);

	int rr;

	try {
		assert(r.UremoveT("https:aaa") == 0);
	}
	catch (RepositoryException& re) {
		assert(re.getMessage() == "This Tutorial does not exist!\n");
	}
	int res;
	res = r.UremoveT("https:aaabc");
	assert(res == 1);


}


void TestFileWatchlist::TestgetAllW()
{
	std::vector<TElem> a;
	FileWatchlist r("testTutorials1.txt");
	Duration newDuration{ 33,22 };
	Tutorial newTutorial{ "C++", "Me", newDuration, 1200, "https:abbbc" };
	r.UaddT(newTutorial);

	std::vector<TElem> v = r.UgetAll();
	assert(v.size() == 4);

}

