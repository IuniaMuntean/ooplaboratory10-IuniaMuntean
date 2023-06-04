#include "Playlist.h"

void Playlist::add(Song s) {
	playlist.push_back(s);
}
void Playlist::clear() {
	playlist.clear();
}
void Playlist::remove(Song s) {
	playlist.erase(std::find(playlist.begin(), playlist.end(), s));
}
std::vector<Song> Playlist::generateRandom(unsigned int n) {
	std::vector<Song> newPlaylist;
	for (int i = 0; i < n; i++)
		newPlaylist.push_back(playlist[rand() % n]);
	return newPlaylist;
}