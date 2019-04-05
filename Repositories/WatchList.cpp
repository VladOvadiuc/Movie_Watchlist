#include "WatchList.h"
#include <string>
#include <fstream>
#include "Utils.h"
#include "RepositoryExceptions.h"

using namespace std;

WatchList::WatchList()
{
	this->current = 0;
	
}

void WatchList::add(const Movie& movie)
{
	this->movies.push_back(movie);
}

int WatchList::deleteMovie(const std::string & title)
{
	std::vector<Movie> moviesInDynamicVector = this->movies;
	/*if (moviesInDynamicVector == NULL)
		return 0;*/

	for (int i = 0; i < this->movies.size(); i++)
	{
		Movie m = moviesInDynamicVector[i];
		if (m.getTitle() == title) {
			for (int j = i; j < this->movies.size(); j++)
			{
				moviesInDynamicVector[i] = moviesInDynamicVector[j];
			}
			this->movies.erase(movies.begin()+i);
			return 1;}}

	return 0;
}


/*Movie WatchList::getCurrentMovie()
{
	if (this->current == this->movies.getSize())
		this->current = 0;
	Movie* elems = this->movies.getAllElems();
	if (elems != NULL)
		return elems[this->current];
	return Movie{};
}

void WatchList::play()
{
	if (this->movies.getSize() == 0)
		return;
	this->current = 0;
	Movie currentmovie = this->getCurrentMovie();
	currentmovie.play();
}

void WatchList::next()
{
	if (this->movies.getSize() == 0)
		return;
	this->current++;
	Movie currentmovie = this->getCurrentMovie();
	currentmovie.play();
}*/

bool WatchList::isEmpty()
{
	return this->movies.size() == 0;
}