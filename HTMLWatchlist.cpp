#include "HTMLWatchlist.h"

HTMLWatchlist::HTMLWatchlist(const std::string& outputFilename) : outputFilename{ outputFilename }, FileWatchlist("watchlist.txt"){
	loadFromFile();
	saveToFile();
}

void HTMLWatchlist::saveToFile() {

	FileWatchlist::saveToFile();
	std::ofstream f(this->outputFilename);
	if (f.is_open())
	{
		f << "<!DOCTYPE html>\n";
		f << "<html>\n";
		f << "\t<head>\n";
		f << "\t\t<title>Tutorials</title>\n";
		f << "\t</head>\n";
		f << "\t<body>\n";
		f << "\t\t<table border = \"1\">\n";
		f << "\t\t<tr>\n";
		f << "\t\t\t<td><b>Title</b></td>\n";
		f << "\t\t\t<td><b>Presenter</b></td>\n";
		f << "\t\t\t<td><b>Minutes</b></td>\n";
		f << "\t\t\t<td><b>Seconds</b></td>\n";
		f << "\t\t\t<td><b>Likes</b></td>\n";
		f << "\t\t\t<td><b>Link</b></td>\n";
		f << "\t\t</tr>\n";

		for (const auto& t : tutorials)
			f << t.getHTMLRepresentation();

		f << "\t\t</table>\n";
		f << "\t</body>\n";
		f << "</html>";

		f.close();
	}
}

HTMLWatchlist::~HTMLWatchlist()
{
}