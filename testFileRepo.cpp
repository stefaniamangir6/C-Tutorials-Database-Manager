#include "testFileRepo.h"

void TestFileRepository::runAllTests() {

	TestsearchTutorial();
	TestaddT();
	TestupdateT();
	TestremoveT();
	TestgetAll();
	TestupdateNrOfLikes();
}

void TestFileRepository::TestaddT() {

	std::vector<TElem> v;
	FileRepo r("testTutorials.txt");
	Duration newDuration{ 33,22 };
	Tutorial newTutorial{ "C++", "Me", newDuration, 1200, "https:abc" };
	int result = r.addT(newTutorial);
	assert(result == 1);

	Duration newDur{ 22,42 };
	Tutorial newTut{ "C", "Me", newDur, 120, "https:abc" };

	try {
		r.addT(newTut);
		assert(false);
	}
	catch (RepositoryException& re) {
		assert(re.getMessage() == "Existing Tutorial!\n");
	}

}

void TestFileRepository::TestsearchTutorial() {

	std::vector<TElem> v;
	FileRepo r("testTutorials.txt");
	Duration newDuration{ 33,22 };
	Tutorial newTutorial{ "C++", "Me", newDuration, 1200, "https:abb" };
	r.addT(newTutorial);
	auto t = r.searchTutorial("https:abb");
	assert(t == newTutorial);

	Duration newDur{ 33,22 };
	Tutorial newTut{ "C++", "Me", newDur, 1200, "https:def" };
	r.addT(newTut);
	auto tt = r.searchTutorial("https:def");
	assert(tt == newTut);


	try {
		r.searchTutorial("https:ooo");
		assert(false);
	}
	catch (RepositoryException& re) {
		assert(re.getMessage() == "This Tutorial does not exist!\n");
	}

}

void TestFileRepository::TestremoveT() {

	std::vector<TElem> v;
	FileRepo r("testTutorials.txt");
	Duration newDuration{ 33,22 };
	Tutorial newTutorial{ "C++", "Me", newDuration, 1200, "https:abbc" };
	r.addT(newTutorial);

	try {
		r.removeT("https:aaa");
		assert(false);
	}
	catch (RepositoryException& re) {
		assert(re.getMessage() == "This Tutorial does not exist!\n");
	}

	int res;
	res = r.removeT("https:abbc");
	assert(res == 1);

}

void TestFileRepository::TestupdateT() {

	std::vector<TElem> v;
	FileRepo r("testTutorials.txt");
	Duration newDuration{ 33,22 };
	Tutorial newTutorial{ "C++", "Me", newDuration, 1200, "https:abcc" };
	r.addT(newTutorial);

	Duration newDur{ 3,2 };
	Tutorial newTut{ "C", "You", newDur, 12, "https:abcc" };

	int res;
	res = r.updateT(newTut);
	assert(res == 1);

	Duration newDu{ 3,2 };
	Tutorial newTu{ "C", "You", newDu, 12, "https:aaa" };

	try {
		r.updateT(newTu);
		assert(false);
	}
	catch (RepositoryException& re) {
		assert(re.getMessage() == "This Tutorial does not exist!\n");
	}


}

void TestFileRepository::TestupdateNrOfLikes() {

	std::vector<TElem> v;
	FileRepo r("testTutorials.txt");
	Duration newDuration{ 33,22 };
	Tutorial newTutorial{ "C++", "Me", newDuration, 1200, "https:aabc" };
	r.addT(newTutorial);

	r.updateNumberOfLikes("https:aabc");

}


void TestFileRepository::TestgetAll()
{
	std::vector<TElem> a;
	FileRepo r("testTutorials.txt");
	Duration newDuration{ 33,22 };
	Tutorial newTutorial{ "C++", "Me", newDuration, 1200, "https:aaabc" };
	r.addT(newTutorial);

	std::vector<TElem> v = r.getAll();
	assert(v.size() == 5);
	

}
