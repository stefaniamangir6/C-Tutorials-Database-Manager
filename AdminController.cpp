#include "AdminController.h"


AdminController::AdminController(Repo& _repo, Validator valid) : repo{ _repo }, valid{ valid }{

}

void AdminController::undoLastAction() {
	if (this->undoStack.size() == 0) {
		throw std::exception("No more undos!");
	}

	std::unique_ptr<Action> currentAction = move(this->undoStack.back());
	currentAction->executeUndo();
	this->redoStack.push_back(move(currentAction));
	this->undoStack.pop_back();
}

void AdminController::redoLastAction() {
	if (this->redoStack.size() == 0) {
		throw std::exception("No more redos!");
	}

	std::unique_ptr<Action> currentAction = move(this->redoStack.back());
	currentAction->executeRedo();
	this->undoStack.push_back(move(currentAction));
	this->redoStack.pop_back();
}

int AdminController::addTutorial(std::string title, std::string presenter, int minutes, int seconds, double likes, std::string TutorialLink)
{
	int status;

	if (this->valid.validate(title, presenter, minutes, seconds, likes, TutorialLink) == 1)
	{
		Duration newDuration{ minutes, seconds };
		Tutorial newTutorial{ title, presenter, newDuration, likes, TutorialLink };
		status = this->repo.addT(newTutorial);
		std::unique_ptr<Action> currentAction = std::make_unique<AddAction>(this->repo, newTutorial);
		this->undoStack.push_back(move(currentAction));
		this->redoStack.clear();
		
	}
	return status;
}

int AdminController::removeTutorial(std::string link)
{
	int status;
	Tutorial deletedTutorial = this->repo.searchTutorial(link);
	status = repo.removeT(link);
	std::unique_ptr<Action> currentAction = std::make_unique<DeleteAction>(this->repo, deletedTutorial);
	this->undoStack.push_back(move(currentAction));
	this->redoStack.clear();
	return status;
}

int AdminController::updateTutorial(std::string newTitle, std::string newPresenter, int newMinutes, int newSeconds, double newLikes, std::string link)
{
	int status;

	if (this->valid.validate(newTitle, newPresenter, newMinutes, newSeconds, newLikes, link) == 1)
	{
		Tutorial oldTutorial = this->repo.searchTutorial(link);
		Duration newDuration{ newMinutes, newSeconds };
		Tutorial newTutorial{ newTitle, newPresenter, newDuration, newLikes, link };
		status = this->repo.updateT(newTutorial);
		std::unique_ptr<Action> currentAction = std::make_unique<UpdateAction>(this->repo, oldTutorial, newTutorial);
		this->undoStack.push_back(move(currentAction));
		this->redoStack.clear();

	}
	return status;

}

std::vector<TElem>& AdminController::getAllC()
{
	return this->repo.getAll();
}


/*void AdminController::load(char fileName[]) {
	repo.loadFromFile(fileName);
}*/

/*void AdminController::save(char fileName[]) {
	repo.saveToFile(fileName);
}*/

AdminController::~AdminController() = default;