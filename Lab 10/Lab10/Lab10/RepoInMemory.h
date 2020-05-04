#pragma once
#include "Repo.h"
template <class T> class RepoInMemory :
	public Repo<T>
{
public:
	RepoInMemory() :Repo<T>() {};
	~RepoInMemory() {};
};

