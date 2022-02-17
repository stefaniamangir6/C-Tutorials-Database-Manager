#pragma once
#include <string>
#include "Duration.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <vector>

class Tutorial {

private: 
	std::string title;
	std::string presenter;
	Duration duration;
	double likes;
	std::string tutorialLink; //unique

public:

	Tutorial();
	/*	-default constructor for the Tutorial type
		
		input: none
		output: creates a new empty object of type Victim
	*/

	Tutorial(std::string title, std::string presenter, Duration duration, double likes, std::string tutorialLink);
	/*
			-overloaded/parameterised constructor for the Victim type
			
			input: the tutorial's properties
			output: creates a new object of type Tutorial
	*/

	std::string getTitle() const;
	/*
			-get the title of the current tutorial

			input: none
			output: the title of the current Tutorial
	*/

	std::string getPresenter() const;
	/*
			-get the presenter of the current tutorial

			input: none
			output: the presenter of the current Tutorial
	*/

	Duration getDuration() const;
	/*
			-get the duration of the current tutorial

			input: none
			output: the duration of the current Tutorial
	*/

	int getLikes() const;
	/*
			-get the number of likes of the current tutorial

			input: none
			output: number of likes of the current Tutorial
	*/

	std::string getTutorialLink() const;
	/*
			-get the link of the current tutorial

			input: none
			output: the link of the current Tutorial
	*/

	bool operator == (const Tutorial& newTutorial);
	/*
		- overloaded equality operator
		input: reference to another tutorial
		output: true, if the content of the 2 tutorials is the same, false, otherwise
		
	*/

	std::string toString() const;
	/*
		converting a Tutorial to a string format 	
	*/

	std::string toString1() const;
	/*
		converting a Tutorial to a string format
	*/
	friend std::ostream& operator<<(std::ostream& os, const Tutorial& t);
	friend std::istream& operator>>(std::istream& is, Tutorial& t);

	std::string getCSVRepresentation() const;

	std::string getHTMLRepresentation() const;

	~Tutorial();
};