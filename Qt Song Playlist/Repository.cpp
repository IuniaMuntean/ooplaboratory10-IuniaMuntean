#include "Repository.h"

const std::vector<Song>& Repository::getAllSongs() {
	return this->m_repo;
}

void Repository::store(const Song& s) {
	if (!(s.getArtist() != "" && s.getTitle() != ""))
		throw SongException(" Song attributes missing.");
	try {
		find(s.getTitle(), s.getArtist());
	}
	catch (SongException) {
		// exception was thrown by find, means song does not exist which is good
		m_repo.push_back(s);
		return;
	}
	throw SongException("The Song " + s.getTitle() + " by " + s.getArtist() + " already exists.\n");
}

const Song& Repository::find(std::string title, std::string artist) {
	// so lambda is like a function duh-uh, and if u want to use variables outside its scope, you need to capture them in [] 
	std::vector<Song>::iterator it = std::find_if(m_repo.begin(), m_repo.end(), [artist, title](const Song& a) { return (a.getArtist() == artist) && (a.getTitle() == title); });
	if (it != m_repo.end()) {
		return *it;
	}

	throw SongException("The Song " + title + " by " + artist + " does not exist. \n");
}

void Repository::remove(const Song& s) {
	try {
		find(s.getTitle(), s.getArtist());
	}
	catch (SongException) {
		// exception was thrown by find, means song does not exist
		throw SongException("The Song " + s.getTitle() + " by " + s.getArtist() + " does not exist. \n");
	}
	m_repo.erase(std::find(m_repo.begin(), m_repo.end(), s));
	// do not forget to overload == for Song
}