#include "Controller.h"
#include <vector>
#include <algorithm>
#include "FileWatchlist.h"
#include <QtWidgets/qmessagebox.h>

void Controller::addMovieToRepository(const std::string& title, const std::string& genre, int date, int likes, const std::string& source,int duration)
{
	Movie m{ title, genre, date,likes, source , duration};

	this->validator.validate(m);
	this->repo.addMovie(m);
	// record the action for undo
	this->undoActions.push_back(std::make_unique<UndoAdd>(this->repo, m));
	this->redoActions.push_back(std::make_unique<RedoRemove>(this->repo, m));
}
void Controller::update(Movie& old, Movie& nou)
{
	

	this->validator.validate(nou);
	this->repo.update(old,nou);
	this->undoActions.push_back(std::make_unique<UndoUpdate>(this->repo,old,nou));

	this->redoActions.push_back(std::make_unique<RedoUpdate>(this->repo, nou,old));
}
Movie Controller::findMovie(const std::string & title)
{
	return this->repo.findByTitle(title);
}
int Controller::deleteMovieRepo(const std::string & title)
{
	Movie m = this->repo.findByTitle(title);
	
	// record the action for undo
	this->undoActions.push_back(std::make_unique<UndoRemove>(this->repo, m));

	this->redoActions.push_back(std::make_unique<RedoAdd>(this->repo, m));
	return this->repo.deleteMovie(title);
}
int Controller::deleteMovieWatchList(const std::string & title)
{
	return this->watchList->deleteMovie(title);
	
}
void Controller::addMovieToWatchList(const Movie& movie)
{
	this->watchList->add(movie);

}
void Controller::undo()
{
	if (undoActions.empty())
	{
		throw RepositoryException{ "There are no more actions to undo." };
	}
	try
	{
		undoActions.back()->executeUndo();
		undoActions.pop_back();
	}
	catch (RepositoryException& e)
	{
		QMessageBox msg;
		msg.critical(0, "ERROR", "No input data");
	}
}
void Controller::redo()
{
	if (redoActions.empty())
	{
		throw RepositoryException{ "There are no more actions to redo." };
	}
	try
	{
		redoActions.back()->executeRedo();
		redoActions.pop_back();
	}
	catch (RepositoryException& e)
	{
		QMessageBox msg;
		msg.critical(0, "ERROR", "No input data");
	}
}

void Controller::addAllMoviesByGenre(const std::string& genre)
{
	// get all the movies from the repository
	std::vector<Movie> v = this->repo.getMovies();
	int64_t nMovies = count_if(v.begin(), v.end(),
		[genre](const Movie& s)
	{
		return s.getGenre() == genre;
	});

	std::vector<Movie> moviesByGenre(nMovies);
	copy_if(v.begin(), v.end(), moviesByGenre.begin(),
[genre](const Movie& s)
	{
		return s.getGenre() == genre;
	});

	for (auto s : moviesByGenre)
		this->watchList->add(s);
}

void Controller::start()
{
	this->repo.play();
}

void Controller::nextMovie()
{
	this->repo.next();
}
void Controller::saveWatchList()
{
	if (this->watchList == nullptr)
		return;

	this->watchList->writeToFile();
}

void Controller::openWatchList() const
{
	if (this->watchList == nullptr)
		return;

	this->watchList->display();
}