#pragma once 
#include "Tutorial.h"
#include <fstream>
#include <sstream>
#include <string.h>
#include <vector>
#include <algorithm>
#include "Exceptions.h"
#include "FileRepository.h"

class CSVRepo : public FileRepo {

private: 
	void saveToFile() override;
	std::string outputFilename;

public:

	CSVRepo(const std::string& outputFilename);
	~CSVRepo();
};