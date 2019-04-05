#pragma once
#include "FileWatchlist.h"

#include <string>
class CSVWatchList : public FileWatchList
{
public:
	CSVWatchList(const std::string& source) : FileWatchList{ source } {}
	void writeToFile() override ;

	void display() const override;

};