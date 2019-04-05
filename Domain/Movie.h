#pragma once
#include <iostream>

class Movie
{
private:
	std::string title;
	std::string genre;
	std::int16_t date;
	std::int16_t likes;
	std::string source; //link
	std::int16_t duration;
public:
	Movie();
	Movie(const std::string& title, const std::string& genre, int date, int likes, const std::string& source, int duration);
	std::string getTitle() const { return title; }
	std::string getGenre()  const { return genre; }
	std::int16_t getRelease() const { return date; }
	std::int16_t getLikes() const { return likes; }
	void setGenre(std::string& genre) { this->genre = genre; }
	std::string getSource() const { return source; }
	std::int16_t getDuration() const { return duration; }
	void update(const std::string& title, const std::string& genre, int date, int likes, const std::string& source,int duration);
	bool operator< (int d) {
		if (duration < d) {
			return true;
		}

		return false;
	}

	void play();
	friend std::istream& operator>>(std::istream& is, Movie& s);
	friend std::ostream& operator<<(std::ostream& os, const Movie& s);

};