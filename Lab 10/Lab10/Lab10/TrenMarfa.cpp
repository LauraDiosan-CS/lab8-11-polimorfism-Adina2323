#include "Tren.h"
#include"TrenMarfa.h"
#include "Util.h"
TrenMarfa::TrenMarfa()
{
	nr_libere = 0;
	nr_ocupate = 0;
}
/*
TrenMarfa::TrenMarfa(string m, string p, int nrr, string item, int lib, int ocup)
{
 model = m; prod = p; nr = nrr;
	marfa = item; nr_libere = lib; nr_ocupate = ocup;
}*/
TrenMarfa::TrenMarfa(Tren& tren, string item, int lib, int ocup)
{
	t = tren;
	marfa = item;
	nr_libere = lib;
	nr_ocupate = ocup;
}
TrenMarfa::TrenMarfa(string linie, char delim)
{
	vector<string> tokens = splitLine(linie, delim);
	t.model = tokens[0];
	t.producator = tokens[1];
	t.nr_vag = stoi(tokens[2]);
	marfa = tokens[3];
	nr_libere= stoi(tokens[4]);
	nr_ocupate = stoi(tokens[5]);
}
Tren TrenMarfa::getTren()
{

	return t;
}
string TrenMarfa::getMarfa()
{
	return marfa;
}
int  TrenMarfa::getLibere()
{
	return nr_libere;
}
int  TrenMarfa::getOcupate()
{
	return nr_ocupate;
}
void  TrenMarfa::setTren(Tren& tren)
{
	t = tren;
}
void  TrenMarfa::setMarfa(string new_marfa)
{
	marfa = new_marfa;
}
void  TrenMarfa::setLibere(int libs)
{
	nr_libere = libs;
}
void  TrenMarfa::setOcupate(int ocups)
{
	nr_ocupate = ocups;
}
bool  TrenMarfa::operator==(const TrenMarfa&tren)
{
	return t.operator==(tren.t) and (marfa == tren.marfa) and (nr_libere == tren.nr_libere) and (nr_ocupate == tren.nr_ocupate);
}
string  TrenMarfa::toString()
{
	return t.toString() +" " + marfa + " " + to_string(nr_libere) + " " + to_string(nr_ocupate);
}
string TrenMarfa::toStringDelimiter(char delim)
{
	return t.toStringDelimiter(delim) + delim + marfa + delim + to_string(nr_libere) + delim + to_string(nr_ocupate);
}
TrenMarfa::~TrenMarfa()
{
}
