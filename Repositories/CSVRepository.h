#pragma once
#include "FileRepository.h"
class CSVRepository : public FileRepository
{
public:
	CSVRepository(std::string s) : FileRepository(s) {};
	void writeToFileRepo();

	void displayRepo();

};