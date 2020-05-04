#pragma once
#include "Repo.h"
template <class T> class RepoFile : public Repo<T>
{

protected:
	const char* fileName;

public:
	RepoFile();
	RepoFile(const char*);
	virtual void saveToFile();
	virtual void loadFromFile();
	~RepoFile();
};


template<class T>
RepoFile<T>::RepoFile() :Repo<T>()
{
}

template<class T>
RepoFile<T>::RepoFile(const char* name)
{
	fileName = name;
}

template<class T>
RepoFile<T>::~RepoFile()
{
}

template<class T>
void RepoFile<T>::saveToFile()
{
}

template<class T>
void RepoFile<T>::loadFromFile()
{
}