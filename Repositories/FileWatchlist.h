#pragma once
#include "WatchList.h"
#include <istream>
class FileWatchList :public WatchList
{
protected:
	std::string source;
public:
	FileWatchList(const std::string& source);
	virtual ~FileWatchList() {}
	virtual void writeToFile() = 0  ;
	virtual void display() const = 0;

};