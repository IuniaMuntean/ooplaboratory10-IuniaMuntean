#pragma once
#include "Repository.h"

class Action {
public:
	Action(Repository& r, Song s) {
		repo = &r;
		song = s;
	}
	virtual void apply() = 0;
protected:
	Repository* repo;
	Song song;
};

class ActionAdd : public Action {
public:
	ActionAdd(Repository& r, Song s) : Action(r, s) {}

	void apply() override {
		repo->remove(song);
	}
};

class ActionDelete : Action {
public:
	ActionDelete(Repository& r, Song s) : Action(r, s) {}

	void apply() override {
		repo->store(song);
	}

};