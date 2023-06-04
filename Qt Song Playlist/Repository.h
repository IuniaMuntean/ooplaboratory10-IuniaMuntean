#pragma once
#include "Song.h"
#include <algorithm>

class Repository
{
public:
	Repository() : m_repo{} {};

	Repository(const Repository& other) = delete;
	Repository& operator=(const Repository& other) = delete;

	const std::vector<Song>& getAllSongs();

	virtual void store(const Song& s);
	virtual const Song& find(std::string title, std::string artist);
	virtual void remove(const Song& s);

	~Repository() = default;

protected:
	std::vector<Song> m_repo;
};

