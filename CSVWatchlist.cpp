#include "CSVWatchlist.h"

CSVWatchlist::CSVWatchlist(const std::string& outputFilename) : outputFilename{ outputFilename }, FileWatchlist("watchlist.txt"){
	loadFromFile();
	saveToFile();
}

void CSVWatchlist::saveToFile() {

	FileWatchlist::saveToFile();
	std::ofstream f(this->outputFilename);
	if (f.is_open())
	{
		for (const auto& t : tutorials)
			f << t.getCSVRepresentation() << "\n";
		f.close();
	}
}

CSVWatchlist::~CSVWatchlist()
{
}