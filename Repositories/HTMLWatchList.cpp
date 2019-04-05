#include "HTMLWatchList.h"
#include <fstream>
#include <Windows.h>
#include "RepositoryExceptions.h"

using namespace std;

void HTMLWatchList::writeToFile()
{
	ofstream f(this->source);

	if (!f.is_open())
		throw FileException("The file could not be opened!");
	f << "<!DOCTYPE html> \n <html> \n <head> \n <title>WatchList</title> \n </head>  \n <body> \n <table border=\"1\">";
	f << " \n <td>Title</td> \n <td>Genre</td> \n <td>Year</td> \n <td>Likes</td> \n<td>Link</td> \n<td>Duration</td> \n </tr> \n";
	for (auto m : this->movies)
		f << "\n <tr> <td>" << m.getTitle() << "</td> \n <td>" << m.getGenre() << "</td> \n <td>" << m.getRelease() << "</td> \n <td>" << m.getLikes() << "</td> \n <td><a href=\""<<m.getSource()<<"\"> Link </a> </td> \n <td>" << m.getDuration();
	f << "\n </table> \n </body> \n </html>";
	f.close();
}

void HTMLWatchList::display()const
{
	string aux = "\"" + this->source + "\""; // if the path contains spaces, we must put it inside quotations
											   //ShellExecuteA(NULL, NULL, "C:\\Program Files (x86)\\OpenOffice 4\\program\\scalc.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
	ShellExecuteA(NULL, NULL, "chrome.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
	//ShellExecuteA(NULL, NULL, "c:\\Program Files\\Microsoft Office\\Office15\\EXCEL.EXE",, NULL, SW_SHOWMAXIMIZED);
}
