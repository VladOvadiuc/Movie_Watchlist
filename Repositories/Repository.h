#pragma once
#include "Movie.h"
#include <vector>
#include "RepositoryExceptions.h"

class Repository
{
private:
	//std::vector<Movie> movies;
	int current;

	std::string filename;

public:
	std::vector<Movie> movies;
	/*
	Default constructor.
	Initializes an object of type repository.
	*/
	Repository(const std::string& filename);
	/*
	Adds a movie to the repository.
	Input: m-movie.
	Output: the movie is added to the repository.
	*/
	void addMovie(Movie& m);
	int deleteMovie(const std::string& title);
	void update(Movie& old,Movie& nou);

	/*
	Finds a song, by artist and title.
	Input: artist, title - string
	Output: the song that was found, or an "empty" song (all fields empty and duration 0), if nothing was found.
	*/
	Movie findByTitle(const std::string& title);

	// Returns the movie that is currently playing.
	Movie getCurrentMovie();

	// Starts the playlist - plays the first movie.
	void play();

	// Plays the next movie in the playlist.
	void next();
	// Checks if the playlist is empty.
	bool isEmpty();
	virtual ~Repository() {}
	std::vector<Movie> getMovies() const { return movies; }

	std::vector<Movie> getAll();

private:
	void readFromFile();
	void writeToFileRepo();
};