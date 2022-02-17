#pragma once 
#include "DynamicVector.h"
#include "Tutorial.h"
#include <fstream>
#include <sstream>
#include <string.h>
#include <vector>
#include "Exceptions.h"


class UserRepo {

protected:
	std::vector<TElem> tutorials;

public:

	UserRepo(const UserRepo&) = delete;
	UserRepo(UserRepo&&) = delete;
	UserRepo& operator=(const UserRepo&) = delete;
	UserRepo& operator=(UserRepo&&) = delete;

	UserRepo();
	// constructor 

	virtual const Tutorial& searchTutorialU(std::string link);

	// returns 1 id if was succesfully added, 0 otherwise 
	virtual int UaddT(const Tutorial &t);

	// returns 1 id if was succesfully removed, 0 otherwise
	virtual int UremoveT(std::string link);

	//retunr the elemnts of the vector
	virtual std::vector<TElem>& UgetAll();

	//void loadFromFile(char fileName[100]);
	//void saveToFile(char fileName[100]);

	//destructor
	~UserRepo();
};