#include "Duration.h"

Duration::Duration(int minutes, int seconds) {
	this->minutes = minutes;
	this->seconds = seconds;
}

int Duration::getMinutes() const
{
	return this->minutes;
}

int Duration::getSeconds() const
{
	return this->seconds;
}

Duration::~Duration() = default;