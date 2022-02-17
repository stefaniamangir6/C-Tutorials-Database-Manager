#include "UserController.h"


UserController::UserController(Repo& _repo, UserRepo& _watchlist) : repo{ _repo }, watchlist { _watchlist } {

}

std::vector<TElem>& UserController::getAllUC()
{
	return this->watchlist.UgetAll();
}


std::vector<TElem> UserController::showTutorialsOfGivenPresenterUC(const std::string &presenter) {

	/*std::vector<TElem> a;
	std::vector<TElem> v = this->repo.getAll();
	for (int i = 0; i < v.size(); i++)
		if (v[i].getPresenter() == presenter)
			a.push_back(v[i]);

	return a;*/

	std::vector<TElem> filtered;
	auto v = this->repo.getAll();
	std::copy_if(v.begin(), v.end(), std::back_inserter(filtered), [&presenter](const auto& x) { return x.getPresenter() == presenter; });
	return filtered;
}
 
int UserController::addToWatchList(Tutorial t)
{
	int status;
	status = this->watchlist.UaddT(t);
	return status;
}

int UserController::removeTutorialUC(std::string link)
{
	int status;
	status = this->watchlist.UremoveT(link);
	return status;
}

void UserController::rateTutorial(std::string link)
{
	this->repo.updateNumberOfLikes(link);
}

/*void UserController::load(char fileName[]) {
	this->watchlist.loadFromFile(fileName);
}*/

/*void UserController::save(char fileName[]) {
	this->watchlist.saveToFile(fileName);
}*/

UserController::~UserController() = default;