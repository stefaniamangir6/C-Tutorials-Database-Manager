#include "CSVRepository.h"

CSVRepo::CSVRepo(const std::string& outputFilename) : outputFilename{ outputFilename }, FileRepo("tutorials_in.txt"){
	loadFromFile();
	saveToFile();
}

void CSVRepo::saveToFile() {
	
	FileRepo::saveToFile();
	std::ofstream f(this->outputFilename);
	if (f.is_open())
	{
		for (const auto& t : elems)
			f << t.getCSVRepresentation() << "\n";
		f.close();
	}
}

CSVRepo::~CSVRepo()
{
}