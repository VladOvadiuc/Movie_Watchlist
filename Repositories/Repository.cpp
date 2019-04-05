#include "Repository.h"
#include <string>
#include <fstream>
#include "Utils.h"

using namespace std;
Repository::Repository(const std::string& filename)
{
	this->current = 0;
	this->filename = filename;
	this->readFromFile();
}

void Repository::addMovie(Movie& m)
{
	int ok = 0;
	for (auto s : this->movies)
	{
		if (s.getTitle() == m.getTitle())
			ok=1;
	}
	if(ok==1)
		throw DuplicateMovieException();
	this->movies.push_back(m);
	this->writeToFileRepo();
}
Movie Repository::findByTitle(const std::string& title)
{
	for (auto s : this->movies)
	{
		if (s.getTitle() == title)
			return s;
	}

	return Movie{};
	
}
int Repository::deleteMovie(const std::string & title)
{
	unsigned int i = 0;
	for (auto s : this->movies)
	{
		if (s.getTitle() == title){
			this->movies.erase(this->movies.begin()+i);
			this->writeToFileRepo();
				return 1;
		}
		i++;
	}

	return 0;
}

void Repository::update(Movie& old, Movie& nou)
{
	unsigned int i = 0;
	for (auto s : this->movies)
	{
		if (s.getTitle() == old.getTitle()) {

			s.update(nou.getTitle(), nou.getGenre(), nou.getRelease(), nou.getLikes(), nou.getSource(), nou.getDuration());
			this->movies.erase(this->movies.begin() + i);
			this->movies.emplace(this->movies.begin() + i, s);
			this->writeToFileRepo();
		}
		i++;
	}
}

Movie Repository::getCurrentMovie()
{
	if (this->current == this->movies.size())
		this->current = 0;
	std::vector<Movie> elems = this->movies;
	return elems[this->current];
}

void Repository::play()
{
if (this->movies.size() == 0)
return;
this->current = 0;
Movie currentmovie = this->getCurrentMovie();
currentmovie.play();
}

void Repository::next()
{
	if (this->movies.size() == 0)
		return;
	this->current++;
	Movie currentmovie = this->getCurrentMovie();
	currentmovie.play();
}
bool Repository::isEmpty()
{
	return this->movies.size() == 0;
}

vector<Movie> Repository::getAll()
{
	return vector<Movie>();
}

void Repository::readFromFile()
{
	ifstream file(this->filename);

	//if (!file.is_open())
		//throw FileException("The file could not be opened!");

	Movie s;
	while (file >> s)
		this->movies.push_back(s);

	file.close();
}

void Repository::writeToFileRepo()
{
	ofstream file(this->filename);
	//if (!file.is_open())
		//throw FileException("The file could not be opened!");

	for (auto s : this->movies)
	{
		file << s;
	}

	file.close();
}