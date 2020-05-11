#include "RepoFile.h"

RepoFile::RepoFile()
{
}
RepoFile::RepoFile(Validation* v)
{
	validation = v;
}
RepoFile::RepoFile(string fileName)
{
	this->fileName = fileName;
}

RepoFile::~RepoFile()
{
	this->garnituri.clear();
}

void RepoFile::setFileName(string fileName)
{
	this->fileName = fileName;
}

vector<Tren*> RepoFile::getAll()
{
	return this->garnituri;
}

int RepoFile::getSize()
{
	return this->garnituri.size();
}

Tren* RepoFile::getTren(int pos)
{
	if (pos >= 0 && pos < this->getSize())
	{
		return this->garnituri[pos]->clone();
	}
	return new Tren();
}

void RepoFile::addTren(Tren* t)
{
	if (validation->validate(t) == 0) {
		this->garnituri.push_back(t->clone());
		this->saveToFile();
	}
	else throw ValidationException(validation->toString().c_str());
}

void RepoFile::updateTren(Tren* pVechi, Tren* pNou)
{
	if (validation->validate(pNou)==0) 
	{
		for (int i = 0; i < this->garnituri.size(); i++)
		{
			if (*(this->garnituri[i]) == *pVechi)
			{
				delete this->garnituri[i];
				this->garnituri[i] = pNou->clone();
				this->saveToFile();
				return;
			}
		}
	}
	else throw ValidationException(validation->toString().c_str());
}

void RepoFile::deleteTren(Tren* p)
{
	for (int i = 0; i < this->garnituri.size(); i++)
	{
		if (*(this->garnituri[i]) == *p)
		{
			delete this->garnituri[i];
			this->garnituri.erase(this->garnituri.begin() + i);
			this->saveToFile();
			return;
		}
	}
}

void RepoFile::emptyRepo()
{
	for (int i = 0; i < this->garnituri.size(); i++)
	{
		delete this->garnituri[i];
	}
	this->garnituri.clear();
}
