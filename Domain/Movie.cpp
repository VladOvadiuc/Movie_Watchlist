#include "Movie.h"
#include <Windows.h>
#include <shellapi.h>
#include "Utils.h"
#include <iostream>
#include <vector>

using namespace std;

Movie::Movie() : title(""), genre(""), date(),likes(), source("") {}

Movie::Movie(const std::string& title, const std::string& genre, int date, int likes, const std::string& source, int duration)
{
	this->title = title;
	this->genre = genre;
	this->date = date;
	this->likes = likes;
	this->source = source;
	this->duration = duration;
}
void Movie::update(const std::string& title, const std::string& genre, int date, int likes, const std::string& source,int duration)
{
	this->title = title;
	this->genre = genre;
	this->date = date;
	this->likes = likes;
	this->source = source;
	this->duration = duration;
}
void Movie::play(){ShellExecuteA(NULL, NULL, "chrome.exe", this->getSource().c_str(), NULL, SW_SHOWMAXIMIZED);}

std::istream & operator>>(std::istream & is, Movie & s)
{
	string line;
	getline(is, line);

	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() != 6) // make sure all the song data was valid
		return is;

	s.title = tokens[0];
	s.genre = tokens[1];
	s.date = stod(tokens[2]);

	s.likes = stod(tokens[3]);
	s.source = tokens[4];
	s.duration = stod(tokens[5]);

	return is;
}

ostream & operator<<(ostream & os, const Movie & s)
{
	os << s.title << "," << s.genre << "," << s.date<< "," << s.likes << "," << s.source << ", " << s.duration  << "\n";
	return os;
}
