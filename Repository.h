#pragma once 
#include "DynamicVector.h"
#include "Tutorial.h"
#include <fstream>
#include <sstream>
#include <string.h>
#include <vector>
#include <algorithm>
#include "Exceptions.h"

class Repo {

protected:
	std::vector<TElem> elems;

public:

	// constructor 

	Repo(const Repo&) = delete;
	Repo(Repo&&) = delete;
	Repo& operator=(const Repo&) = delete;
	Repo& operator=(Repo&&) = delete;

	Repo();

	virtual const Tutorial& searchTutorial(std::string link);

	// returns 1 id if was succesfully added, 0 otherwise 
	virtual int addT(const Tutorial &t);

	// returns 1 id if was succesfully removed, 0 otherwise
	virtual int removeT(std::string link);

	// returns 1 id if was succesfully updated, 0 otherwise 
	virtual int updateT(const Tutorial &newT);

	virtual void updateNumberOfLikes(std::string link);

	//return the elemnts of the vector
	virtual std::vector<TElem>& getAll();

	//void loadFromFile(char fileName[100]);
	//void saveToFile(char fileName[100]);

	//destructor
	~Repo();
};