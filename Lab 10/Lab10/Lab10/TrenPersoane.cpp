#include "TrenPersoane.h"
#include "Tren.h"
#include "Util.h"
TrenPersoane::TrenPersoane()
{
	locuri = 0;
	nr_libere = 0;
	nr_ocupate = 0;
}
TrenPersoane::TrenPersoane(Tren& tren, int locs, int lib, int ocup)
{
	t = tren;
	locuri = locs;
	nr_libere = lib;
	nr_ocupate = ocup;
}
TrenPersoane::TrenPersoane(string linie, char delim)
{
	vector<string> tokens = splitLine(linie, delim);
	t.model = tokens[0];
	t.producator = tokens[1];
	t.nr_vag = stoi(tokens[2]);
	locuri = stoi(tokens[3]);
	nr_libere = stoi(tokens[4]);
	nr_ocupate = stoi(tokens[5]);
}
Tren TrenPersoane::getTren()
{
	return t;
}
int TrenPersoane::getLocuri()
{
	return locuri;
}
int  TrenPersoane::getLibere()
{
	return nr_libere;
}
int  TrenPersoane::getOcupate()
{
	return nr_ocupate;
}
void  TrenPersoane::setTren(Tren& tren)
{
	t = tren;
}
void  TrenPersoane::setLocuri(int locs)
{
	locuri=locs;
}
void  TrenPersoane::setLibere(int libs)
{
	nr_libere = libs;
}
void  TrenPersoane::setOcupate(int ocups)
{
	nr_ocupate = ocups;
}
bool  TrenPersoane::operator==(const TrenPersoane& tren)
{
	return t.operator==(tren.t) and (locuri == tren.locuri) and (nr_libere == tren.nr_libere) and (nr_ocupate == tren.nr_ocupate);
}
string  TrenPersoane::toString()
{
	return t.toString() + " " + to_string(locuri) + " " + to_string(nr_libere) + " " + to_string(nr_ocupate);
}
string TrenPersoane::toStringDelimiter(char delim)
{
	return t.toStringDelimiter(delim) + delim + to_string(locuri) + delim + to_string(nr_libere) + delim + to_string(nr_ocupate);
}
TrenPersoane::~TrenPersoane()
{
}
