#include "Repository.h"
#include "Exceptions.h"

Repo::Repo(){

}

const Tutorial& Repo::searchTutorial(std::string link)
{
	auto it = std::find_if(this->elems.begin(), this->elems.end(), [&link](const auto& x) {return x.getTutorialLink() == link; });
	if (it == this->elems.end())
		throw RepositoryException("This Tutorial does not exist!\n");
	return *it;
	/*for (int i = 0; i < elems.sizee(); ++i) {
		if (this->elems[i].getTutorialLink() == link) // if it exists
			return i; // return its position
	}
	return -1;}*/
}


int Repo::addT(const Tutorial& t)
{
	std::string link = t.getTutorialLink();
	auto it = std::find_if(this->elems.begin(), this->elems.end(), [&link](const auto& x) {return x.getTutorialLink() == link; });
	if (it != this->elems.end())
		throw RepositoryException("Existing Tutorial!\n");
	else
	{
		this->elems.push_back(t);
		return 1;}}
	/*if (searchTutorial(t.getTutorialLink()) == -1){ // if there is no tutorial with the same link 
		elems.add(t);
		return 1;}
	else
		return 0;*/

int Repo::removeT(std::string link)
{
	Tutorial tutorial = searchTutorial(link);
	auto it = std::find(this->elems.begin(), this->elems.end(), tutorial);
	if (it == this->elems.end())
		return 0;
	else
	{
		this->elems.erase(it);
		return 1;}}

	/*int pos = searchTutorial(link);
	if (searchTutorial(link) != -1){// if tutorial exists
		elems.remove(pos);
		return 1;}
	else
		return 0;*/



int Repo::updateT(const Tutorial& newT)
{
	std::string link = newT.getTutorialLink();
	auto it = std::find_if(this->elems.begin(), this->elems.end(), [&link](const auto& x) {return x.getTutorialLink() == link; });
	if (it == this->elems.end())
		throw RepositoryException("This Tutorial does not exist!\n");
	else
	{
		removeT(newT.getTutorialLink());
		addT(newT);
		return 1;}}
	/*int pos = searchTutorial(newT.getTutorialLink());
	if (searchTutorial(newT.getTutorialLink()) != -1){
		elems.update(newT, pos);
		return 1;}
	else
		return 0;}*/


void Repo::updateNumberOfLikes(std::string link)
{
	Tutorial tutorial = searchTutorial(link);
	string name, presenter;
	Duration dur;
	double nrOfLikes;
	name = tutorial.getTitle();
	presenter = tutorial.getPresenter();
	dur = tutorial.getDuration();
	nrOfLikes = tutorial.getLikes();
	nrOfLikes += 1;
	Tutorial newT{ name, presenter, dur, nrOfLikes, link };
	updateT(newT);
}
std::vector<TElem>& Repo::getAll() {
	return this->elems;
}

/*void Repo::loadFromFile(char fileName[])
{
	string presenter, title, link;
	int minutes, seconds;
	double likes;
	char line[10000];
	std::string t;
	fstream f(fileName);
	while (f.getline(line, 10000, '\n'))
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
		elems.add(newT);
	}
	f.close();
}*/

/*void Repo::saveToFile(char fileName[])
{
	std::ofstream ofs;
	ofs.open(fileName, std::ofstream::out | std::ofstream::trunc);
	ofs.close();
	fstream f(fileName);
	for (int i = 0; i < elems.sizee(); ++i)
		f << elems[i].getTitle() << ";" << elems[i].getPresenter() << ";" << elems[i].getDuration().getMinutes() << ";" << elems[i].getDuration().getSeconds() << ";" << elems[i].getLikes() << ";" << elems[i].getTutorialLink() << ";"<<"\n";
	f.close();
}*/

Repo::~Repo() = default;