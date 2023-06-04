#pragma once
#include "FileRepository.h"
#include <stack>
#include "Action.h"

enum WAY{
	ASC,
	DESC
};

class SongController
{
public:
	//SongController() :repo{ *new Repository{} } {}
	SongController(std::string filePath) :repo{ *new FileRepository{filePath} } { repo.load(); }
	void add_new_song(std::string artist, std::string title, std::string year, std::string url = "", std::string lyrics = "");
	const Song& search(std::string artist, std::string title);
	//void remove_song(std::string artist, std::string title);
	void remove_song(const Song& s);

	//void load();

	std::vector<Song> sort_by_artist(WAY p);
	std::vector<Song> sort_by_title(WAY p);

	Repository& getInstance();

	/*std::stack <ActionAdd, ActionDelete> undo;
	std::stack <ActionAdd, ActionDelete> redo;*/

private:
	FileRepository& repo;
};

