#pragma once 
#include "Tutorial.h"
#include <fstream>
#include <sstream>
#include <string.h>
#include <vector>
#include <algorithm>
#include "Exceptions.h"
#include "Watchlist.h"

class FileWatchlist : public UserRepo {

protected:
	void loadFromFile();
	virtual void saveToFile();
	std::string filename;

public:

	FileWatchlist(const std::string& filename);


	virtual const Tutorial& searchTutorialU(std::string link)override;

	// returns 1 id if was succesfully added, 0 otherwise 
	virtual int UaddT(const Tutorial& t)override;

	// returns 1 id if was succesfully removed, 0 otherwise
	virtual int UremoveT(std::string link)override;

	//retunr the elemnts of the vector
	virtual std::vector<TElem>& UgetAll()override;

	~FileWatchlist();
};