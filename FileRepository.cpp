#include "FileRepository.h"

FileRepo::FileRepo(const std::string& filename) : filename{ filename }{
	loadFromFile();
}

void FileRepo::loadFromFile() {

	std::ifstream f(this->filename);
	if (f.is_open())
	{
		this->elems.clear();
		Tutorial t;
		while (f >> t)
		{
			this->elems.push_back(t);
		}
		f.close();
	}
}

void FileRepo::saveToFile() {

	std::ofstream f(this->filename);
	if (f.is_open())
	{
		for (const auto& t : elems)
			f << t;
		f.close();
	}
}

int FileRepo::addT(const Tutorial& t) {
	this->loadFromFile();
	int r = Repo::addT(t);
	this->saveToFile();
	return r;
}

int FileRepo::removeT(std::string link)
{
	this->loadFromFile();
	int r = Repo::removeT(link);
	this->saveToFile();
	return r;
}

int FileRepo::updateT(const Tutorial& newT) {
	this->loadFromFile();
	int r = Repo::updateT(newT);
	this->saveToFile();
	return r;
}

void FileRepo::updateNumberOfLikes(std::string link) {
	this->loadFromFile();
	Repo::updateNumberOfLikes(link);
	this->saveToFile();
	
}

std::vector<TElem>& FileRepo::getAll() {
	this->loadFromFile();
	return Repo::getAll();
}

const Tutorial& FileRepo::searchTutorial(std::string link) {
	this->loadFromFile();
	return Repo::searchTutorial(link);
	
}

FileRepo::~FileRepo()
{
}
