#include "Action.h"

AddAction::AddAction(Repo& currentRepo, Tutorial addedTutorial) : currentRepo(currentRepo) {
	this->addedTutorial = addedTutorial;
}

void AddAction::executeUndo() {
	this->currentRepo.removeT(this->addedTutorial.getTutorialLink());
}

void AddAction::executeRedo() {
	this->currentRepo.addT(this->addedTutorial);
}

DeleteAction::DeleteAction(Repo& currentRepo, Tutorial deletedTutorial) : currentRepo(currentRepo) {
	this->deletedTutorial = deletedTutorial;
}

void DeleteAction::executeUndo() {
	this->currentRepo.addT(this->deletedTutorial);
}

void DeleteAction::executeRedo() {
	this->currentRepo.removeT(this->deletedTutorial.getTutorialLink());
}


UpdateAction::UpdateAction(Repo& currentRepo, Tutorial oldTutorial, Tutorial newTutorial) : currentRepo(currentRepo) {
	this->oldTutorial = oldTutorial;
	this->newTutorial = newTutorial;
}

void UpdateAction::executeUndo() {
	this->currentRepo.updateT(this->oldTutorial);
}

void UpdateAction::executeRedo() {
	this->currentRepo.updateT(this->newTutorial);
}
