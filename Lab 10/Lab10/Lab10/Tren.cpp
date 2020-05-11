#include "Tren.h"
#include"Util.h"
#include<vector>

Tren::Tren()
{
	nr_vag = 0;
	nr_libere = 0;
	nr_ocupate = 0;
}
Tren::Tren(string model, string prod, int nr,int lib,int ocup)
{
	this->model = model;
	producator = prod;
	nr_vag = nr;
	nr_libere = lib;
	nr_ocupate=ocup;
}
Tren::Tren(const Tren& t)
{
	this->model = t.model;
	this->producator = t.producator;
	this->nr_vag = t.nr_vag;
	this->nr_libere = t.nr_libere;
	this->nr_ocupate = t.nr_ocupate;
}
Tren* Tren::clone()
{
	return new Tren(this->model, this->producator, this->nr_vag, this->nr_libere, this->nr_ocupate);
}
string Tren::getModel()
{
	return model;
}
string Tren::getProducator()
{
	return producator;
}
int Tren::getNr()
{
	return nr_vag;
}
int Tren::getOcupate()
{
	return nr_ocupate;
}
int Tren::getLibere()
{
	return nr_libere;
}
void Tren::setModel(string new_model)
{
	model = new_model;
}
void Tren::setProducator(string new_prod)
{
	producator = new_prod;
}
void Tren::setNrVag(int new_val)
{
	nr_vag = new_val;
}
void Tren::setOcupate(int nr)
{
	nr_ocupate = nr;
}
void Tren::setLibere(int nr)
{
	nr_libere = nr;
}
Tren& Tren::operator=(const Tren& t)
{
	this->model = t.model;
	this->producator = t.producator;
	this->nr_vag = t.nr_vag;
	this->nr_libere = t.nr_libere;
	this->nr_ocupate = t.nr_ocupate;
	return *this;
}
bool Tren::operator==(const Tren&tren)
{
	return this->model==tren.model &&this->producator==tren.producator && this->nr_vag==tren.nr_vag && this->nr_libere==tren.nr_libere && this->nr_ocupate==tren.nr_ocupate;
}
string Tren::toString(string delim)
{
	return model + delim + producator + delim + to_string(nr_vag)+delim+to_string(nr_libere)+delim+to_string(nr_ocupate);
}

Tren::~Tren()
{
	nr_vag = 0;
}