#include "Service.h"
#include "TrenMarfa.h"
#include "TrenPersoane.h"
#include <algorithm>
#include "Validation.h"
#include "RepoException.h"

template<typename Base, typename T>
inline bool instanceof(const T*) {
	return is_base_of<Base, T>::value;
}

Service::Service()
{
	this->repo = NULL;
}
void Service::setRepo(RepoFile* repo)
{
	this->repo = repo;
}

bool Service::login(string u, string p)
{
	User usr(u, p);
	return repoUser->find(usr) != -1;
}
Tren* Service::getTrenAtPos(int pos)
throw (RepoException)
{
	return this->repo->getTren(pos);
}
void Service::addTrenMarfa(string m, string p, int nr, int l, int o, string i)
throw(ValidationException, RepoException) 
{
	TrenMarfa* v = new TrenMarfa(m,p,nr,i,l,o);
	this->repo->addTren(v);
	
}
int Service::getsize()
{
	return this->repo->getSize();
}
void Service::addTrenPersoane(string m, string p, int nr, int l, int o, int locs)
throw(ValidationException, RepoException) 
{

	Tren* v = new TrenPersoane(m, p, nr, locs, l, o);
	this->repo->addTren(v);

}

void Service::updateTM(string numeV, string modelV, int nrV, int ocupV, int libV, string marfaV, string nume, string model, int nr, int ocup, int lib, string marfa)
throw (ValidationException, RepoException)
{
	Tren* tv = new Tren(numeV, modelV, nrV, ocupV, libV);
	TrenMarfa* tn = new TrenMarfa(nume, model, nr, marfa, ocup, lib);
	this->repo->updateTren(tv, tn);
}
void Service::updateTP(string numeV, string modelV, int nrV, int ocupV, int libV, int locV, string nume, string model, int nr, int ocup, int lib, int loc)
throw (ValidationException, RepoException)
{
	Tren* tv = new Tren(numeV, modelV, nrV, ocupV, libV);
	TrenPersoane* tn = new TrenPersoane(nume, model, nr, loc, ocup, lib);
	this->repo->updateTren(tv, tn);
}
void Service::delTren(string model)throw (RepoException)
{
	Tren* t = new Tren(model, " ", 0, 0, 0);
	this->repo->deleteTren(t);
}
void Service::upTren(string mV, string m, string p, int nr, int lib, int ocup)
{
	Tren* t=new Tren("","",0,0,0);
	for (Tren* c : this->getAll())
	{
		if (c->getModel() == mV)
			break;
		t = c;
	}
	if (!t->getModel().empty())
	{
		Tren* tn = new  Tren(m, p, nr, lib, ocup);
		this->repo->updateTren(t, tn);
	}
	else return;
}
vector <Tren*> Service::filterbyNr(int nr)
{
	vector<Tren*> trenuri = this->repo->getAll();
	vector <Tren*> result;
	for (Tren* t : trenuri)
	{
		if (t->getNr() == nr)
		{
			result.push_back(t->clone());
		}
	}
	return result;
}
Tren* Service::getTrenModel(string model)
{
	vector<Tren*> trenuri = this->repo->getAll();
	for (Tren* t : trenuri)
	{
		if (t->getModel() == model)
		{
			return t;
		}
	}
	Tren* t=new Tren(" ", " ", 0, 0, 0);
	return t;

}
vector <Tren*> Service::filterbyProd(string prod)
{
	vector<Tren*> trenuri = this->repo->getAll();
	vector <Tren*> result;
	for (Tren* t : trenuri)
	{
		if (t->getProducator()==prod)
		{
			result.push_back(t->clone());
		}
	}
	return result;
}
vector<Tren*> Service::getAll()
{
	return this->repo->getAll();
}


void Service::saveFromFile()
{
	this->repo->saveToFile();
}
void Service::loadFromfile()
{
	this->repo->loadFromFile();
}

void Service::setFileName(string fileName)
{
	this->repo->setFileName(fileName);
}

Service::~Service()
{
}
