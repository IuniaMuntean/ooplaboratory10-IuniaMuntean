#include "FileRepository.h"
#include <fstream>

void FileRepository::load() {
	std::ifstream MyFile(filepath);

	if (!MyFile)
		throw std::runtime_error("File could not be open.");

	// the file will have the following format:
	// ARTIST
	// SONG TITLE
	// YEAR it was released 
	// URL
	// "
	// LYRICS
	// "
	// the lyrics will start && end with "...", both " " will sit on a new line

	std::string artist;
	std::string title;
	std::string year, url, lyrics;

	while (!MyFile.eof()) {
		std::getline(MyFile, artist);
		std::getline(MyFile, title);
		std::getline(MyFile, year);
		std::getline(MyFile, url);

		std::string line;
		std::getline(MyFile, line);
		if ( line == "\"" )
		{
			std::getline(MyFile, line);
			lyrics += line;
			while (line != "\"" && !MyFile.eof()) {
				std::getline(MyFile, line);
				lyrics += '\n';
				lyrics += line;
			}
		}

		if (artist != "" && title != "" && lyrics != "" && year != "" && url != "") {
			// artist, title, lyrics, year, url
			Repository::store(Song{ artist, title, lyrics, year, url });
		}
		else throw SongException(" Missing song attributes at loading.");
		artist = ""; title = ""; lyrics = ""; year = ""; url = "";
	}
	MyFile.close();
}
void FileRepository::save() {
	std::ofstream MyFile(filepath);

	if (!MyFile)
		throw std::runtime_error("Songs could not be saved.");

	if(m_repo.begin() == m_repo.end())
		throw std::runtime_error("Repo is empty.");

	for (auto s : m_repo) {
		MyFile << s.getArtist() << "\n" << s.getTitle() << "\n" << s.getYear() << "\n" << s.getUrl() << "\n";
		MyFile << "\"\n";
		for (auto word : s.getLyrics())
			if (word == "\n") 
				MyFile << "\n";
			else MyFile << word << " ";
		MyFile <<"\n\"";
		if (!(s == m_repo[m_repo.size() - 1]))
			MyFile << "\n";
	}
	MyFile.close();
}

void FileRepository::changeFilepath(std::string newFilepath) {
	filepath = newFilepath;
}

void FileRepository::store(const Song& s) {
	Repository::store(s);
	save();
}
void FileRepository::remove(const Song& s) {
	Repository::remove(s);
	save();
}