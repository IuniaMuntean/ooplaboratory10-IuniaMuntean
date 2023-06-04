#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <exception>

class Song
{
private:
	std::string m_artist;
	std::string m_title;
	std::string m_year;
	std::string m_url;
protected:
	std::vector<std::string> m_lyrics;
public:
	Song() = default;
	Song(std::string, std::string, std::string, std::string, std::string);
	std::string getArtist() const;
	std::string getTitle() const;
	std::string getYear() const;
	std::string getUrl() const;
	std::vector<std::string> getLyrics() const;

	bool operator==(const Song& other);

	std::string toString();

	//friend std::ostream& operator<<(std::ostream& os, Song s);

};

class SongException : public std::exception
{
public:
	SongException(std::string msg) 
		: std::exception(msg.c_str()) {}

	/*friend std::ostream& operator<<(std::ostream& os, SongException e) {
		os << e.what();
		return os;
	}*/
};