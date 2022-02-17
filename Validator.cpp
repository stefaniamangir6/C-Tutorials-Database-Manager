#include "Validator.h"


Validator::Validator() = default;

int Validator::validate(std::string title, std::string presenter, int minutes, int seconds, double likes, std::string TutorialLink)
{
    string message = "";

    if(minutes < 0)
        message += "The number representing the minutes must be a positive number!\n";

    if (seconds < 0 || seconds >= 60)
        message += "The number representing the seconds must be a positive number smaller tha 60!\n";

    if(title == "" || presenter == "" || TutorialLink == "")
        message += "The title, presenter or the link of the tutorial must not be empty!\n";


    if(!isupper(title[0]) || !isupper(presenter[0]))
        message += "Either the title or the presenter must start with an uppercase letter!\n";

    if(TutorialLink[0] != 'h' || TutorialLink[1] != 't' || TutorialLink[2] != 't' || TutorialLink[3] != 'p' || TutorialLink[4] != 's' || TutorialLink[5] != ':')
        message += "The link must start with 'https:' !\n";

    if(likes < 0)
        message += "Invalid number of likes!\n";

    if (message != "")
        throw ValidatorException(message);
    else
        return 1;}

Validator::~Validator() = default;