#include "Service.h"
#include "TrenMarfa.h"
#include "TrenPersoane.h"
#include <algorithm>
#include "Validation.h"

template<typename Base, typename T>
inline bool instanceof(const T*) {
	return is_base_of<Base, T>::value;
}

Service::Service()
{
}

Service::Service(RepoFile& rN, RepoFile& rP)
{
	repoMarfa = &rN;
	repoPers = &rP;
}

bool Service::login(string u, string p)
{
	User usr(u, p);

	return repoUser->find(usr) != -1;
}

void Service::addTrenMarfa(string m, string p, int nr, int l, int o, string i)
{
	try {
		Tren* v = new TrenMarfa(m,p,nr,i,l,o);
		repoMarfa->addTren(v);
	}
	catch (ValidationException ex) {
		throw ex;
	}
}

void Service::addTrenPersoane(string m, string p, int nr, int l, int o, int locs)
{
try {
	Tren* v = new TrenPersoane(m, p, nr, locs, l, o);
	repoMarfa->addTren(v);
}
catch (ValidationException ex) {
	throw ex;
}
}


void Service::delTM(string m, string p, int nr, int l, int o, string i)
{
	repoMarfa->deleteTren(new TrenMarfa(m,p,nr,i,l,o));
}
void Service::delTP(string m, string p, int nr, int l, int o,int locs) {
	repoPers->deleteTren(new TrenPersoane(m, p, nr, locs, l, o));
}

vector<Tren*> Service::getAll()
{
	vector<Tren*> all(repoMarfa->getAll());
	vector<Tren*> poezii = repoPers->getAll();

	all.insert(all.end(), poezii.begin(), poezii.end());
	return all;
}

vector<Tren*> Service::getAllTP()
{
	return repoPers->getAll();
}

vector<Tren*> Service::getAllTM()
{

	return repoMarfa->getAll();
}




Service::~Service()
{
}
