#include "CSVRepository.h"
#include <fstream>
#include <string>
#include <Windows.h>

void CSVRepository::writeToFileRepo()
{
	std::ofstream f(source);
	for (auto& it : movies) {
		f << it;
	}
	f.close();
}
void CSVRepository::displayRepo()
{
	std::string s = "notepad \"" + source + "\"";
	system(s.c_str());
}
