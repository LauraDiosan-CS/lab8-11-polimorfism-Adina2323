#include "RepoFile.h"
#include "RepoException.h"
#include <typeinfo>
#include "ValidationException.h"
RepoFile::RepoFile()
{
}
RepoFile::RepoFile(Validation* v)
{
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
	throw RepoException("Indexul nu e valid! ");
}
int RepoFile::findTren(Tren* t)
{
	for (int i = 0; i < this->garnituri.size(); i++)
	{
		if (this->garnituri[i]->getModel() == t->getModel())
		{
			return i;
		}
	}
	return -1;
}
void RepoFile::addTren(Tren* t) throw(ValidationException, RepoException)
{
	if (typeid(*t) == typeid(TrenMarfa))
	{
		this->validatorTM.validate(t);
	}
	if (typeid(*t) == typeid(TrenPersoane))
	{
		this->validatopTP.validate(t);
	}
	if (this->findTren(t) >= 0)
	{
		throw ValidationException("Exista deja un tren cu acelasi model");
	}
	this->garnituri.push_back(t->clone());
	this->saveToFile();


}


void RepoFile::updateTren(Tren* pVechi, Tren* pNou)
{
	if (typeid(*pNou) == typeid(TrenMarfa))
	{
		this->validatorTM.validate(pNou);
	}
	if (typeid(*pNou) == typeid(TrenPersoane))
	{
		this -> validatopTP.validate(pNou);
	}
	if (this->findTren(pVechi) < 0)
		throw RepoException("Nu exista acest Tren!");
	for (int i = 0; i < this->garnituri.size(); i++)
	{
		if (this->getTren(i)->getModel() == pVechi->getModel())
		{
			delete this->garnituri[i];
			this->garnituri[i] = pNou->clone();
			this->saveToFile();
			return;
		}
	}
}

void RepoFile::deleteTren(Tren* p)
{
	for (int i = 0; i < this->garnituri.size(); i++)
	{
		if (this->garnituri[i]->getModel() == p->getModel())
		{
			delete this->garnituri[i];
			
			this->garnituri.erase(this->garnituri.begin() + i);
			this->saveToFile();
			return;
		}
	}
	throw RepoException("Nu exista niciun tren cu modelul dat!");
}

void RepoFile::emptyRepo()
{
	for (int i = 0; i < this->garnituri.size(); i++)
	{
		delete this->garnituri[i];
	}
	this->garnituri.clear();
}
