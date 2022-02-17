#include "Watchlist.h"
#include "Exceptions.h"


UserRepo::UserRepo(){

}

const Tutorial& UserRepo::searchTutorialU(std::string link)
{
	auto it = std::find_if(this->tutorials.begin(), this->tutorials.end(), [&link](const auto& x) {return x.getTutorialLink() == link; });
	if (it == this->tutorials.end())
		throw RepositoryException("This Tutorial does not exist!\n");
	return *it;
	/*for (int i = 0; i < tutorials.sizee(); ++i) {
		if (this->tutorials[i].getTutorialLink() == link) // if it exists
			return i; // return its position
	}
	return -1;*/
}

int UserRepo::UaddT(const Tutorial &t)
{
	std::string link = t.getTutorialLink();
	auto it = std::find_if(this->tutorials.begin(), this->tutorials.end(), [&link](const auto& x) {return x.getTutorialLink() == link; });
	if (it != this->tutorials.end())
		throw RepositoryException("Existing Tutorial!\n");
	else
	{
		this->tutorials.push_back(t);
		return 1;}}
	/*if (searchTutorialU(t.getTutorialLink()) == -1) { // if there is no tutorial with the same link 
		tutorials.add(t);
		return 1;}
	else
		return 0;*/

int UserRepo::UremoveT(std::string link)
{
	Tutorial tutorial = searchTutorialU(link);
	auto it = std::find(this->tutorials.begin(), this->tutorials.end(), tutorial);
	this->tutorials.erase(it);
	return 1;}
	/*int pos = searchTutorialU(link);
	if (searchTutorialU(link) != -1) {// if tutorial exists
		tutorials.remove(pos);
		return 1;}
	else
		return 0;*/


std::vector<TElem>& UserRepo::UgetAll() {
	return this->tutorials;
}

/*void UserRepo::loadFromFile(char fileName[])
{
	string presenter, title, link;
	int minutes, seconds;
	double likes;
	char line[1000];
	std::string t;
	fstream f(fileName);
	while (f.getline(line, 1000, '\n'))
	{
		char split_with = ';';
		std::vector<string> fields;
		std::string token;
		stringstream ss(line);
		while (getline(ss, token, split_with)) fields.push_back(token);
		title = fields[0];
		presenter = fields[1];
		minutes = stoi(fields[2]);
		seconds = stoi(fields[3]);
		likes = stoi(fields[4]);
		link = fields[5];
		Duration dur{ minutes, seconds };
		Tutorial newT{ title, presenter, dur, likes, link };
		tutorials.add(newT);
	}
	f.close();
}

void UserRepo::saveToFile(char fileName[])
{
	fstream f(fileName);
	for (int i = 0; i < tutorials.sizee(); ++i)
		f << tutorials[i].getTitle() << ";" << tutorials[i].getPresenter() << ";" << tutorials[i].getDuration().getMinutes() << ";" << tutorials[i].getDuration().getSeconds() << ";" << tutorials[i].getLikes() << ";" << tutorials[i].getTutorialLink() << "\n";
	f.close();
}
*/
UserRepo::~UserRepo() = default;