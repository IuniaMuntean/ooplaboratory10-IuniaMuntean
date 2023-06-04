#pragma once
#include "Song.h"

class Playlist : public Song {
public:
	void add(Song s);
	void clear();
	void remove(Song s);
	std::vector<Song> generateRandom(unsigned int n);
private:
	std::vector<Song> playlist;
};

