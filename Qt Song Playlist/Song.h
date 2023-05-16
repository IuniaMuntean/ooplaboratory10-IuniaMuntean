#pragma once
#include <string>

class Song
{
private:
	std::string m_title, m_artist, m_link;
	float m_duration;

public:
	Song();
	Song(std::string, std::string, std::string, float);

	Song& operator=(const Song& other);

	Song(const Song& other); // copy constructor

	std::string getTitle();
	std::string getArtist();
	std::string getLink();
	float getDuration();

	void setTitle(std::string);
	void setArtist(std::string);
	void setLink(std::string);
	void setDuration(float);

};

