#pragma once 
#include "Tutorial.h"
#include <fstream>
#include <sstream>
#include <string.h>
#include <vector>
#include <algorithm>
#include "Exceptions.h"
#include "Repository.h"

class FileRepo : public Repo {

protected:
	void loadFromFile();
	virtual void saveToFile();
	std::string filename;

public:

	FileRepo(const std::string& filename);


	virtual const Tutorial& searchTutorial(std::string link)override;
	// returns 1 id if was succesfully added, 0 otherwise 
	virtual int addT(const Tutorial& t)override;

	// returns 1 id if was succesfully removed, 0 otherwise
	virtual int removeT(std::string link) override;

	// returns 1 id if was succesfully updated, 0 otherwise 
	virtual int updateT(const Tutorial& newT)override;

	virtual void updateNumberOfLikes(std::string link)override;

	virtual std::vector<TElem>& getAll() override;

	~FileRepo();
};