#pragma once
#include "Repository.h"


class FileRepository : public Repository {
public:
	FileRepository(std::string f)
		: filepath(f) {}
	void load();
	void save();

	void changeFilepath(std::string);

	void store(const Song& s) override;
	void remove(const Song& s) override;
private:
	std::string filepath;
};

