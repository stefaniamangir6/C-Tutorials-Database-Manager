#pragma once 
#include "Repository.h"
#include "Watchlist.h"
#include <iostream>
using namespace std;

class UserController {

private:
	Repo& repo;
	UserRepo& watchlist;

public:

	UserController(Repo& _repo, UserRepo& _watchlist);


	std::vector<TElem>& getAllUC();
	/*

			input: none
			output: return a vector of type Dynamicvector, meaningly the current elements of the repo
	*/

	std::vector<TElem> showTutorialsOfGivenPresenterUC(const std::string &presenter);

	int addToWatchList(Tutorial t);

	int removeTutorialUC(std::string link);

	void rateTutorial(std::string link);

	//void load(char fileName[]);

	//void save(char fileName[]);

	~UserController();

};