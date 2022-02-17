#pragma once 
#include <string>
#include "Tutorial.h"
#include "Exceptions.h"

class Validator{

private:
	;
public:

	Validator();

	int validate(std::string title, std::string presenter, int minutes, int seconds, double likes, std::string TutorialLink);

	~Validator();
};

