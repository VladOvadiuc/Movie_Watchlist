#include "CSVWatchList.h"
#include <fstream>
#include <string>
#include <Windows.h>

void CSVWatchList::writeToFile()
{
	std::ofstream f(this->source);
	for (auto& it : movies) {
		f << it;
	}
	f.close();
}
void CSVWatchList::display()const
{
	std::string aux = "\"" + this->source + "\"";
	ShellExecuteA(NULL, NULL, "C:\\Program Files (x86)\\Microsoft Office\\Office14\\EXCEL.EXE", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
}
