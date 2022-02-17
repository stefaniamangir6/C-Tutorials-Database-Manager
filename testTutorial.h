#pragma once
#include <assert.h>
#include "Tutorial.h"
#include "Duration.h"

class TestTutorial {
private:
	void TutorialTitle();
	void TutorialPresenter();
	void TutorialDuration();
	void TutorialLikes();
	void TutorialLink();
	void TutorialString();
	void TutorialString1();

public:
	void runAllTests();
};