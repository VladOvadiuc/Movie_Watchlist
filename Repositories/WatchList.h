#pragma once
#include <vector>
#include "Movie.h"

class WatchList
{
protected:
	
	int current;
	

public:
	WatchList();
	std::vector<Movie> movies;

	// Adds a movie to the playlist.
	void add(const Movie& movie);

	int deleteMovie(const std::string& title);
	/*
	// Returns the movie that is currently playing.
	Movie getCurrentMovie();

	// Starts the playlist - plays the first movie.
	void play();

	// Plays the next movie in the playlist.
	void next();
	*/
	// Checks if the playlist is empty.
	bool isEmpty();
	int getSize() const { return this->movies.size(); }
	std::vector<Movie> getMovies() const { return movies; }

	virtual ~WatchList() {}
};

