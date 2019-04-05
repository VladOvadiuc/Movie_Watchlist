#pragma once
#include "FileWatchlist.h"

#include <string>
class HTMLWatchList : public FileWatchList
{
public:
	HTMLWatchList(const std::string& s) : FileWatchList{ s } {};
	void writeToFile() override ; 

	void display()const override;

};