#pragma once
#include "Repository.h"
#include <istream>
class FileRepository :public Repository
{
protected:
	std::string source;
public:
	FileRepository(std::string s) : source(s), Repository(s) {}
	virtual void writeToFile() { return; };
	virtual void display() {
		return;
	};

};