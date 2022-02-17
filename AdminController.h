#pragma once 
#include "Repository.h"
#include "Validator.h"
#include "Action.h"

class AdminController {

private:
	Repo& repo;
	Validator valid;

	std::vector<std::unique_ptr<Action>> undoStack;
	std::vector<std::unique_ptr<Action>> redoStack;

public:

	AdminController(Repo &_repo, Validator valid);

	void undoLastAction();
	void redoLastAction();

	int addTutorial(std::string title, std::string presenter, int minutes, int seconds, double likes, std::string TutorialLink);
	/*
			- calls "validate" function in order to validate the user's input
			- if the details are valid, it adds an element of type Tutorial to the current repository

			input: the details of the future Tutorial
			output: returns 1 if the tutorial was succesfully added, 0 otherwise 
	*/
	int removeTutorial(std::string link);
	/*
			- removes the tutorial with the given link from the repository

			input: the link of the Tutorial that needs to be removed
			output: returns 1 if the tutorial was succesfully removed, 0 otherwise
	*/

	int updateTutorial(std::string newTitle, std::string newPresenter, int newMinutes, int newSeconds, double newLikes, std::string link);
	/*
			- calls "validate" function in order to validate the user's input
			- if the details are valid, it updates the element of type Tutorial, with the link "link" of the current repository

			input: the details of the future Tutorial, the link of the Tutorial that will be updated
			output: returns 1 if the tutorial with the given link was succesfully updated, 0 otherwise
	*/

	std::vector<TElem>& getAllC();
	/*

			input: none
			output: return a vector of type Dynamicvector, meaningly the current elements of the repo
	*/

	//void load(char fileName[]);

	//void save(char fileName[]);

	~AdminController();

};