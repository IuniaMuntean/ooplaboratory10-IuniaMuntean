#include "Song.h"

Song::Song() {
	m_artist = "NoName";
	m_title = "NoSong";
	m_link = "";
	m_duration = 0;
}
Song::Song(std::string artist, std::string title, std::string link, float duration) {
	m_artist = artist;
	m_duration = duration;
	m_link = link;
	m_title = title;
}

Song& Song::operator=(const Song& other) {
	m_artist = other.m_artist;
	m_duration = other.m_duration;
	m_title = other.m_title;
	m_link = other.m_link;

	return *this;
}

Song::Song(const Song& other) {
	this->m_artist = other.m_artist;
	this->m_title = other.m_title;
	this->m_link = other.m_link;
	this->m_duration = other.m_duration;
}

std::string Song::getTitle() {
	return m_title;
}
std::string Song::getArtist() {
	return m_artist;
}
std::string Song::getLink() {
	return m_link;
}
float Song::getDuration() {
	return m_duration;
}

void Song::setTitle(std::string newT) {
	m_title = newT;
}
void Song::setArtist(std::string newA){
	m_artist = newA;
}
void Song::setLink(std::string newT){
	m_link = newT;
}
void Song::setDuration(float newD){
	m_duration = newD;
}