#pragma once
#include "Repository.h"
#include "WatchList.h"
#include "FileWatchlist.h"
#include "MovieValidator.h"
#include "Undo.h"
#include <Redo.h>
#include<memory>

class Controller
{
private:
	Repository repo;
	FileWatchList* watchList;
	MovieValidator validator;
	// a vector of unique_ptr of undo actions;
	// pointers are required, as we need polymorphism;
	// each add/remove action (on the repository) will be recorded in this vector
	std::vector<std::unique_ptr<UndoAction>> undoActions;
	std::vector<std::unique_ptr<RedoAction>> redoActions;


public:
	Controller(const Repository& r, FileWatchList* w, MovieValidator v) : repo{ r }, watchList{w}, validator { v } {}
	Controller(const Controller& ctrl) = delete; // controller cannot be copied now, because it contains unique_ptr
	void operator=(const Controller& ctrl) = delete;

	Repository getRepo() const { return repo; }
	WatchList* getWatchList() const { return watchList; }

	// Adds a movie with the given data to the movie repository.
	void addMovieToRepository(const std::string& title, const std::string& genre, int date, int likes, const std::string& source,int duration);
	int deleteMovieRepo(const std::string& title);
	void update(Movie& old, Movie& nou);

	Movie findMovie(const std::string & title);

	/*
	Adds a given movie to the current playlist.
	Input: movie - Movie, the movie must belong to the repository.
	Output: the movie is added to the playlist.
	*/
	void addMovieToWatchList(const Movie& movie);
	int deleteMovieWatchList(const std::string & title);


	// Adds all the movies from the repository, that have the given artist, to the current playlist.
	void addAllMoviesByGenre(const std::string& genre);

	void start();
	void nextMovie();
	void undo();
	void redo();

	void saveWatchList();

	/*
	Opens the playlist, with an appropriate application.
	Throws: FileException - if the given file cannot be opened.
	*/
	void openWatchList() const;
};

