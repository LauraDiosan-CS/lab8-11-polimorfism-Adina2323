#include "Tren.h"
#include"TrenMarfa.h"
#include "Util.h"
TrenMarfa::TrenMarfa() :Tren()
{

}

TrenMarfa::TrenMarfa(string m, string p, int nrr, string item, int lib, int ocup):Tren( m, p,  nrr,  lib,  ocup)
{
	this->marfa = item;
}

TrenMarfa::TrenMarfa(const TrenMarfa&t):Tren(t)
{
	this->marfa = t.marfa;
}
Tren* TrenMarfa::clone()
{
	return new TrenMarfa(this->model, this->producator, this->nr_vag, this->marfa, this->nr_libere, this->nr_ocupate);
}
string TrenMarfa::getMarfa()
{
	return this->marfa;
}

void  TrenMarfa::setMarfa(string new_marfa)
{
	this->marfa = new_marfa;
}
TrenMarfa& TrenMarfa::operator=(const TrenMarfa& t)
{
	Tren::operator=(t);
	this->marfa = t.marfa;
	return *this;

}
bool  TrenMarfa::operator==(const TrenMarfa&tren)
{
	return Tren::operator==(tren) && this->marfa==tren.marfa;
}
string  TrenMarfa::toString(string delim)
{
	return "TM" + delim +Tren::toString(delim)+delim+this->marfa ;
}

TrenMarfa::~TrenMarfa()
{
}
