#include "Tutorial.h"
#include <iostream>
#include <sstream>
using namespace std;

Tutorial::Tutorial()
{
	this->title = "";
	this->presenter = "";
	this->duration = Duration(0, 0);
	this->likes = 0;
	this->tutorialLink = "";
}

Tutorial::Tutorial(std::string title, std::string presenter, Duration duration, double likes, std::string tutorialLink)
{
	this->title = title;
	this->presenter = presenter;
	this->duration = duration;
	this->likes = likes;
	this->tutorialLink = tutorialLink;
}

string Tutorial::getTitle() const
{
	return this->title;
}

string Tutorial::getPresenter() const
{
	return this->presenter;
}

Duration Tutorial::getDuration() const
{
	return this->duration;
}


int Tutorial::getLikes() const
{
	return this->likes;
}


std::string Tutorial::getTutorialLink() const
{
	return this->tutorialLink;
}

bool Tutorial::operator==(const Tutorial& newTutorial) {
	return (this->title == newTutorial.title && this->presenter == newTutorial.presenter && this->duration.getMinutes() == newTutorial.duration.getMinutes() && this->duration.getSeconds() == newTutorial.duration.getSeconds() && this->tutorialLink == newTutorial.tutorialLink);
}

std::string Tutorial::toString() const {
	stringstream buffer;
	buffer << "Tutorial \n\t Title: " << this->title << endl << "\t Presenter: " << this->presenter << endl << "\t Duration: " << this->duration.getMinutes() << "m:" << this->duration.getSeconds() << "s" <<endl << "\t Number of likes: " << this->likes << endl << "\t Link: " << this->tutorialLink << endl;
	return buffer.str();
}

std::string Tutorial::toString1() const {
	stringstream buffer;
	buffer << "Tutorial \n\t Title: " << this->title << endl << "\t Presenter: " << this->presenter << endl << "\t Duration: " << this->duration.getMinutes() << "m:" << this->duration.getSeconds() << "s" << endl << "\t Number of likes: " << this->likes << endl;
	return buffer.str();
}

std::vector<std::string> tokenize(const std::string& str, char delimiter) {
	std::vector<std::string> result;
	std::istringstream ss(str);
	std::string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);

	return result;
}


std::ostream &operator<<(std::ostream& os, const Tutorial& t)
{
	os << t.title << ';' << t.presenter << ';' << t.duration.getMinutes() << ';' << t.duration.getSeconds() << ';' << t.likes << ';' << t.tutorialLink << '\n';
	return os;
}


std::istream &operator>>(std::istream& is, Tutorial& t)
{
	std::string line;
	getline(is, line);

	std::vector<std::string> tokens = tokenize(line, ';');
	if (tokens.size() != 6) // make sure all the tutorial data was valid
		return is;
	t.title = tokens[0];
	t.presenter = tokens[1];
	Duration dur{ stoi(tokens[2]), stoi(tokens[3]) };
	t.duration = dur;
	t.likes = stod(tokens[4]);
	t.tutorialLink = tokens[5];

	return is;
}

std::string Tutorial::getCSVRepresentation() const {
	std::string TutorialRepresentation = "";

	TutorialRepresentation += (this->getTitle() + ", ");
	TutorialRepresentation += (this->getPresenter() + ", ");
	TutorialRepresentation += (std::to_string(this->getDuration().getMinutes()) + ": ");
	TutorialRepresentation += (std::to_string(this->getDuration().getSeconds()) + ", ");
	TutorialRepresentation += (std::to_string(this->getLikes()) + ", ");
	TutorialRepresentation += (this->getTutorialLink());

	return TutorialRepresentation;
}

std::string Tutorial::getHTMLRepresentation() const {
	std::string TutorialRepresentation = "";

	TutorialRepresentation += "\t\t<tr>\n";
	TutorialRepresentation += ("\t\t\t<td>" + this->getTitle() + "</td>\n");
	TutorialRepresentation += ("\t\t\t<td>" + this->getPresenter() + "</td>\n");
	TutorialRepresentation += ("\t\t\t<td>" + std::to_string(this->getDuration().getMinutes()) + "</td>\n");
	TutorialRepresentation += ("\t\t\t<td>" + std::to_string(this->getDuration().getSeconds()) + "</td>\n");
	TutorialRepresentation += ("\t\t\t<td>" + std::to_string(this->getLikes()) + "</td>\n");
	TutorialRepresentation += ("\t\t\t<td>" + this->getTutorialLink() + "</td>\n");
	TutorialRepresentation += "\t\t</tr>\n";

	return TutorialRepresentation;

}
Tutorial::~Tutorial() = default;