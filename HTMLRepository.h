#pragma once 
#include "Tutorial.h"
#include <fstream>
#include <sstream>
#include <string.h>
#include <vector>
#include <algorithm>
#include "Exceptions.h"
#include "FileRepository.h"

class HTMLRepo : public FileRepo {

private:
	void saveToFile() override;
	std::string outputFilename;

public:

	HTMLRepo(const std::string& outputFilename);
	~HTMLRepo();
};