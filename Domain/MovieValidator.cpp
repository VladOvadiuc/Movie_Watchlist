#include "MovieValidator.h"
#include <time.h>
#include <chrono>
#include <ctime>
#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

typedef std::chrono::system_clock Clock;

MovieException::MovieException(std::vector<std::string> _errors) : errors{ _errors }
{
}

std::vector<std::string> MovieException::getErrors() const
{
	return this->errors;
}

void MovieValidator::validate(const Movie & s)
{
	auto now = Clock::now();
	std::time_t now_c = Clock::to_time_t(now);
	struct tm *parts = std::localtime(&now_c);
	vector<string> errors;
	if (s.getTitle().size() < 3)
		errors.push_back("The title name cannot be less than 2 characters!\n");
	if (!isupper(s.getTitle()[0]))
		errors.push_back(string("The title of the movie must start with a capital letter!\n"));
	
	if (s.getGenre().size() < 3)
			errors.push_back("The genre cannot be less than 2 characters!\n");
	if (s.getDuration() == 0 )
		errors.push_back(string("The duration cannot be 0!\n"));
	if(s.getRelease()>1900 + parts->tm_year && !(int)s.getRelease())
		errors.push_back(string("The release year of the movie cannot be in the future!\n"));
	if (s.getRelease()<1782 + parts->tm_year)
		errors.push_back(string("The release year of the movie cannot be older than 1900!\n"));
	// search for "www" or "http" at the beginning of the source string
	size_t posWww = s.getSource().find("www");
	size_t posHttp = s.getSource().find("http");
	if (posWww != 0 && posHttp != 0)
		errors.push_back("The youtube source must start with one of the following strings: \"www\" or \"http\"\n");

	if (errors.size() > 0)
		throw MovieException(errors);
}
