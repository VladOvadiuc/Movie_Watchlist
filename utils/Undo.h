#pragma once
#include "Movie.h"
#include "Repository.h"
/*
Generic class for an undo action.
For each type of action (add, delete, update), a new class will be created,
inheriting from this UndoAction.
*/
class UndoAction
{
public:
	virtual void executeUndo() = 0;
	// virtual destructor!
	virtual ~UndoAction() {};
};
class UndoAdd : public UndoAction
{
private:
	Movie addedMovie;
	Repository& repo; // we keep a reference to the repository to be able to undo the action
public:
	UndoAdd(Repository& _repo, const Movie& m) : repo{ _repo }, addedMovie{ m } {}
	/*
	For the add operation, the reverse operation that must be executed is
	"remove".
	*/
	void executeUndo() override
	{
		this->repo.deleteMovie(addedMovie.getTitle());
	}
};
class UndoRemove : public UndoAction
{
private:
	Movie deletedMovie;
	Repository& repo;
public:
	UndoRemove(Repository& _repo, const Movie& m) : repo{ _repo }, deletedMovie{m} {}
	void executeUndo() override
	{
		this->repo.addMovie(deletedMovie);
	}
};

class UndoUpdate : public UndoAction
{
private:
	Movie oldMovie;
	Movie newMovie;
	Repository& repo;
public:
	UndoUpdate(Repository& _repo, const Movie& old, const Movie& nou) : repo{ _repo }, oldMovie{ old }, newMovie{ nou } {}
	void executeUndo() override
	{
		this->repo.update( newMovie, oldMovie);
	}
};