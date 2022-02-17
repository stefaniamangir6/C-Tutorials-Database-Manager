#pragma once 
#include "Tutorial.h"
#include <fstream>
#include <sstream>
#include <string.h>
#include <vector>
#include <algorithm>
#include "Exceptions.h"
#include "FileWatchlist.h"

class CSVWatchlist : public FileWatchlist {

private:
	void saveToFile() override;
	std::string outputFilename;

public:

	CSVWatchlist(const std::string& outputFilename);
	~CSVWatchlist();
};