#pragma once
#include "Repository.h"

class Action {
public:
	virtual void executeUndo() = 0;
	virtual void executeRedo() = 0;
};

class AddAction : public Action {
private:
	Repo& currentRepo;
	Tutorial addedTutorial;

public:
	AddAction(Repo & currentRepo, Tutorial addedTutorial);
	void executeUndo() override;
	void executeRedo() override;
};

class DeleteAction : public Action {
private:
	Repo& currentRepo;
	Tutorial deletedTutorial;

public:
	DeleteAction(Repo& currentRepo, Tutorial deletedTutorial);
	void executeUndo() override;
	void executeRedo() override;
};

class UpdateAction : public Action {
private:
	Repo& currentRepo;
	Tutorial oldTutorial;
	Tutorial newTutorial;

public:
	UpdateAction(Repo& currentRepo, Tutorial oldTutorial, Tutorial newTutorial);
	void executeUndo() override;
	void executeRedo() override;
};


