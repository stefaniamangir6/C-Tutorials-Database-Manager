#include "testRepository.h"

void TestRepository::runAllTests() {
	
	TestsearchTutorial();
	TestaddT();
	TestupdateT();
	TestremoveT();
	TestgetAll();
	TestupdateNrOfLikes();
	//TestFileRepo();
}

void TestRepository::TestaddT() {

	std::vector<TElem> v;
	Repo r;
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

void TestRepository::TestsearchTutorial() {

	std::vector<TElem> v;
	Repo r;
	Duration newDuration{ 33,22 };
	Tutorial newTutorial{ "C++", "Me", newDuration, 1200, "https:abc" };
	r.addT(newTutorial);
	auto t = r.searchTutorial("https:abc");
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

void TestRepository::TestremoveT() {

	std::vector<TElem> v;
	Repo r;
	Duration newDuration{ 33,22 };
	Tutorial newTutorial{ "C++", "Me", newDuration, 1200, "https:abc" };
	r.addT(newTutorial);

	try {
		r.removeT("https:aaa");
		assert(false);
	}
	catch (RepositoryException& re) {
		assert(re.getMessage() == "This Tutorial does not exist!\n");
	}

	int res;
	res = r.removeT("https:abc");
	assert(res == 1);

}

void TestRepository::TestupdateT() {

	std::vector<TElem> v;
	Repo r;
	Duration newDuration{ 33,22 };
	Tutorial newTutorial{ "C++", "Me", newDuration, 1200, "https:abc" };
	r.addT(newTutorial);

	Duration newDur{ 3,2 };
	Tutorial newTut{ "C", "You", newDur, 12, "https:abc" };

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

void TestRepository::TestupdateNrOfLikes() {

	std::vector<TElem> v;
	Repo r;
	Duration newDuration{ 33,22 };
	Tutorial newTutorial{ "C++", "Me", newDuration, 1200, "https:abc" };
	r.addT(newTutorial);

	r.updateNumberOfLikes("https:abc");
	

}


void TestRepository::TestgetAll()
{
	std::vector<TElem> a;
	Repo r;
	Duration newDuration{ 33,22 };
	Tutorial newTutorial{ "C++", "Me", newDuration, 1200, "https:abc" };
	r.addT(newTutorial);

	std::vector<TElem> v = r.getAll();
	assert(v.size() == 1);
	assert(v[0] == newTutorial);

}

/*void TestRepository::TestFileRepo() {
	
	DynamicVector<TElem> a;
	Repo r = Repo(a);
	char fileName[100] = {};
	strcpy_s(fileName, "testTutorials.txt");
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