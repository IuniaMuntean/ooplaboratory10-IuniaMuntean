#include "SongController.h"

void SongController::add_new_song(std::string artist, std::string title, std::string lyrics, std::string year, std::string url) {
	try {
		repo.store(Song(artist, title, lyrics, year, url));
		//undo.push(ActionAdd(repo, Song(artist, title, lyrics, year, url)));
	}
	catch (...) {
		throw;
	}
}

void SongController::remove_song(const Song& s) {
	try
	{
		repo.remove(s);
		//undo.push(ActionAdd(repo, s));
	}
	catch (...)
	{
		throw;

	}
}

const Song& SongController::search(std::string artist, std::string title) {
	try
	{
		return repo.find(title, artist);
	}
	catch (...) {
		throw;
	}
}

std::vector<Song> SongController::sort_by_artist(WAY p) {
	if ( p == ASC )
	{
		auto ASC = [](const Song& a, const Song& b) {
			return a.getArtist() < b.getArtist();
		};
		std::vector<Song> songsASC = repo.getAllSongs();
		std::sort(songsASC.begin(), songsASC.end(), ASC);
		return songsASC;
	}
	if ( p == DESC )
	{
		auto DESC = [](const Song& a, const Song& b) {
			return a.getArtist() > b.getArtist();
		};
		std::vector<Song> songsDESC = repo.getAllSongs();
		std::sort(songsDESC.begin(), songsDESC.end(), DESC);
		return songsDESC;
	}
}

std::vector<Song> SongController::sort_by_title(WAY p) {
	if (p == ASC)
	{
		auto ASC = [](const Song& a, const Song& b) {
			return a.getTitle() < b.getTitle();
		};
		std::vector<Song> songsASC = repo.getAllSongs();
		std::sort(songsASC.begin(), songsASC.end(), ASC);
		return songsASC;
	}
	if (p == DESC)
	{
		auto DESC = [](const Song& a, const Song& b) {
			return a.getTitle() > b.getTitle();
		};
		std::vector<Song> songsDESC = repo.getAllSongs();
		std::sort(songsDESC.begin(), songsDESC.end(), DESC);
		return songsDESC;
	}
}

Repository& SongController::getInstance() {
	return repo;
}