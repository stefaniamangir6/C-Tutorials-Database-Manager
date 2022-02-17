#include "testDynamicVector.h"

void TestDynamicVector::runAllTests() {
	
	TestSize();
	Testadd();
	Testupdate();
	Testremove();
	TestOperator();

}

void TestDynamicVector::TestSize() {

	DynamicVector<TElem> v = DynamicVector<TElem>();
	Duration newDuration{ 33,22 };
	Tutorial newTutorial{ "C++", "Me", newDuration, 1200, "https:abc" };
	v.add(newTutorial);
	assert(v.sizee() == 1);
	
}

void TestDynamicVector::Testadd() {

	DynamicVector<TElem> v = DynamicVector<TElem>();
	Duration newDuration{ 33,22 };
	Tutorial newTutorial{ "C++", "Me", newDuration, 1200, "https:abc" };
	v.add(newTutorial);
	assert(v.sizee() == 1);
	assert(v[0] == newTutorial);
	Tutorial new1{ "C", "You", newDuration, 12400, "https:def" };
	v.add(new1);
	assert(v.sizee() == 2);
	assert(v[0] == newTutorial);
	assert(v[1] == new1);
	Tutorial new2{ "C++ 2020", "X", newDuration, 2400, "https:ghi" };
	v.add(new2);
	assert(v.sizee() == 3);
	assert(v[0] == newTutorial);
	assert(v[1] == new1);
	assert(v[2] == new2);
	Tutorial new3{ "C++ 2020", "X", newDuration, 2400, "https:jkl" };
	v.add(new3);
	assert(v.sizee() == 4);
	assert(v[0] == newTutorial);
	assert(v[1] == new1);
	assert(v[2] == new2);
	assert(v[3] == new3);
	Tutorial new4{ "C++ 2020", "X", newDuration, 2400, "https:jklo" };
	v.add(new4);
	Tutorial new5{ "C++ 2020", "X", newDuration, 2400, "https:jklp" };
	v.add(new5);
	Tutorial new6{ "C++ 2020", "X", newDuration, 2400, "https:jkuu" };
	v.add(new6);
	Tutorial new7{ "C++ 2020", "X", newDuration, 2400, "https:juuukl" };
	v.add(new7);
	Tutorial new8{ "C++ 2020", "X", newDuration, 2400, "https:jgnkl" };
	v.add(new8);
	Tutorial new9{ "C++ 2020", "X", newDuration, 2400, "https:jkgnl" };
	v.add(new9);
	v.resize(v);
	

}

void TestDynamicVector::Testupdate() {

	DynamicVector<TElem> v = DynamicVector<TElem>();
	Duration newDuration{ 33,22 };
	Tutorial newTutorial{ "C++", "Me", newDuration, 1200, "https:abc" };
	v.add(newTutorial);

	Tutorial new1{ "C", "You", newDuration, 12400, "https:def" };
	v.add(new1);

	Tutorial new2{ "C++ 2020", "X", newDuration, 2400, "https:ghi" };
	v.add(new2);
	
	Duration newDur{ 3,2 };
	Tutorial new3{ "C++ 2021", "Y", newDur, 200, "https:def" };

	v.update(new3, 1);
	assert(v.sizee() == 3);
	assert(v[0] == newTutorial);
	assert(v[1] == new3);
	assert(v[2] == new2);
	v.update(new3, 5);

}

void TestDynamicVector::Testremove() {

	DynamicVector<TElem> v = DynamicVector<TElem>();
	Duration newDuration{ 33,22 };
	Tutorial newTutorial{ "C++", "Me", newDuration, 1200, "https:abc" };
	v.add(newTutorial);
	
	Tutorial new1{ "C", "You", newDuration, 12400, "https:def" };
	v.add(new1);
	
	Tutorial new2{ "C++ 2020", "X", newDuration, 2400, "https:ghi" };
	v.add(new2);
	
	v.remove(1);
	assert(v.sizee() == 2);
	assert(v[0] == newTutorial);
	assert(v[1] == new2);
	v.remove(5);


}

void TestDynamicVector::TestOperator()
{
	DynamicVector<TElem> v = DynamicVector<TElem>();
	DynamicVector<TElem> v1 = DynamicVector<TElem>();

	Duration newDuration{ 33,22 };
	Tutorial newTutorial{ "C++", "Me", newDuration, 1200, "https:abc" };
	v.add(newTutorial);

	v1 = v;
	assert(v1[0] == newTutorial);

	DynamicVector<TElem> v2 = DynamicVector<TElem>();

	v = v;
	assert(v[0] == newTutorial);
}