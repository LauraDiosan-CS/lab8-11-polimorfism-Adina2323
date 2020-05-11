#include "TrenPersoane.h"
#include "Tren.h"
#include "Util.h"
TrenPersoane::TrenPersoane()
{
	locuri = 0;
}
TrenPersoane::TrenPersoane(string m, string p, int locs, int nr_vag, int lib, int ocup):Tren(m,p,nr_vag,lib,ocup)
{
	this->locuri = locs;
}
TrenPersoane::TrenPersoane(const TrenPersoane &t):Tren(t)
{
	this->locuri = t.locuri;
}
int TrenPersoane::getLocuri()
{
	return locuri;
}
void  TrenPersoane::setLocuri(int locs)
{
	locuri=locs;
}
Tren* TrenPersoane::clone()
{
	return new TrenPersoane(this->model, this->producator, this->locuri, this->nr_vag, this->nr_libere, this->nr_ocupate);
}
bool  TrenPersoane::operator==(const TrenPersoane& tren)
{
	return Tren::operator==(tren) && this->locuri == tren.locuri;
}
TrenPersoane& TrenPersoane::operator=(const TrenPersoane& t)
{
	Tren::operator=(t);
	this->locuri = t.locuri;
	return *this;
}
string  TrenPersoane::toString(string delim)
{
	return "TP"+ delim+Tren::toString(delim)+delim+to_string(this->locuri);
}

TrenPersoane::~TrenPersoane()
{
}
