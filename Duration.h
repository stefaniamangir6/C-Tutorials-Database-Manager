#pragma once
#include <string>

class Duration {

private:
	int minutes;
	int seconds;

public:
	Duration(int minutes = 0, int seconds = 0);
	/*	-constructor for the Tutorial type

		input: none
		output: creates a new empty object of type Duration
	*/

	int getMinutes() const;
	/*
			-get the minutes of the current duration

			input: none
			output: the minutes of the current duration
	*/

	int getSeconds() const;
	/*
			-get the seconds of the current duration

			input: none
			output: the seconds of the current duration
	*/

	~Duration();
};