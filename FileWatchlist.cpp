#include "FileWatchlist.h"

FileWatchlist::FileWatchlist(const std::string& filename) : filename{ filename } {
	loadFromFile();
}

void FileWatchlist::loadFromFile() {

	std::ifstream f(this->filename);
	if (f.is_open())
	{
		this->tutorials.clear();
		Tutorial t;
		while (f >> t)
		{
			this->tutorials.push_back(t);
		}
		f.close();
	}
}

void FileWatchlist::saveToFile() {

	std::ofstream f(this->filename);
	if (f.is_open())
	{
		for (const auto& t : tutorials)
			f << t;
		f.close();
	}
}

int FileWatchlist::UaddT(const Tutorial& t) {
	this->loadFromFile();
	int r = UserRepo::UaddT(t);
	this->saveToFile();
	return r;
}

int FileWatchlist::UremoveT(std::string link)
{
	this->loadFromFile();
	int r = UserRepo::UremoveT(link);
	this->saveToFile();
	return r;
}

std::vector<TElem>& FileWatchlist::UgetAll() {
	this->loadFromFile();
	return UserRepo::UgetAll();
}

const Tutorial& FileWatchlist::searchTutorialU(std::string link) {
	this->loadFromFile();
	return UserRepo::searchTutorialU(link);

}

FileWatchlist::~FileWatchlist()
{
}
