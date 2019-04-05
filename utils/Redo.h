#pragma once
#include "Movie.h"
#include "Repository.h"
/*
Generic class for an undo action.
For each type of action (add, delete, update), a new class will be created,
inheriting from this UndoAction.
*/
class RedoAction
{
public:
	virtual void executeRedo() = 0;
	// virtual destructor!
	virtual ~RedoAction() {};
};
class RedoAdd : public RedoAction
{
private:
	Movie addedMovie;
	Repository& repo; // we keep a reference to the repository to be able to undo the action
public:
	RedoAdd(Repository& _repo, const Movie& m) : repo{ _repo }, addedMovie{ m } {}
	/*
	For the add operation, the reverse operation that must be executed is
	"remove".
	*/
	void executeRedo() override
	{
		this->repo.deleteMovie(addedMovie.getTitle());
	}
};
class RedoRemove : public RedoAction
{
private:
	Movie deletedMovie;
	Repository& repo;
public:
	RedoRemove(Repository& _repo, const Movie& m) : repo{ _repo }, deletedMovie{ m } {}
	void executeRedo() override
	{
		this->repo.addMovie(deletedMovie);
	}
};

class RedoUpdate : public RedoAction
{
private:
	Movie oldMovie;
	Movie newMovie;
	Repository& repo;
public:
	RedoUpdate(Repository& _repo, const Movie& old, const Movie& nou) : repo{ _repo }, oldMovie{ old }, newMovie{ nou } {}
	void executeRedo() override
	{
		this->repo.update(newMovie, oldMovie);
	}
};