#include "testTutorial.h"

void TestTutorial::runAllTests() {
	TutorialTitle();
	TutorialPresenter();
	TutorialDuration();
	TutorialLikes();
	TutorialLink();
	TutorialString();
	TutorialString1();
}

void TestTutorial::TutorialTitle() {
	
	Duration newDuration{ 33,22 };
	Tutorial newTutorial{"C++", "Me", newDuration, 1200, "https:abc"};
	assert(newTutorial.getTitle() == "C++");
}

void TestTutorial::TutorialPresenter() {
	Duration newDuration{ 33,22 };
	Tutorial newTutorial{ "C++", "Me", newDuration, 1200, "https:abc" };
	assert(newTutorial.getPresenter() == "Me");
}

void TestTutorial::TutorialDuration() {
	Duration newDuration{ 33,22 };
	Tutorial newTutorial{ "C++", "Me", newDuration, 1200, "https:abc" };
	assert(newTutorial.getDuration().getMinutes() == 33);
	assert(newTutorial.getDuration().getSeconds() == 22);
}

void TestTutorial::TutorialLikes() {
	Duration newDuration{ 33,22 };
	Tutorial newTutorial{ "C++", "Me", newDuration, 1200, "https:abc" };
	assert(newTutorial.getLikes() == 1200 );

}

void TestTutorial::TutorialLink() {
	Duration newDuration{ 33,22 };
	Tutorial newTutorial{ "C++", "Me", newDuration, 1200, "https:abc" };
	assert(newTutorial.getTutorialLink() == "https:abc");
}

void TestTutorial::TutorialString() {
	Duration newDuration{ 33,22 };
	Tutorial newTutorial{ "C++", "Me", newDuration, 1200, "https:abc" };
	std::string s;
	s = newTutorial.toString();
}

void TestTutorial::TutorialString1() {
	Duration newDuration{ 33,22 };
	Tutorial newTutorial{ "C++", "Me", newDuration, 1200, "https:abc" };
	std::string s;
	s = newTutorial.toString1();
	std::string csv = newTutorial.getCSVRepresentation();
	std::string html = newTutorial.getHTMLRepresentation();
	

}