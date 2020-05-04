#include "Tren.h"
#include"Util.h"
#include<vector>

Tren::Tren()
{
	nr_vag = 0;
}
Tren::Tren(string model, string prod, int nr)
{
	this->model = model;
	producator = prod;
	nr_vag = nr;
}
Tren::Tren(string linie, char delim)
{
	vector<string> tokens = splitLine(linie, delim);
	model = tokens[0];
	producator = tokens[1];
	nr_vag = stoi(tokens[2]);
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
bool Tren::operator==(const Tren&tren)
{
	return (model == tren.model) and (producator == tren.producator) and (nr_vag == tren.nr_vag);
}
string Tren::toString()
{
	return model + " " + producator + " " + to_string(nr_vag);
}
string Tren::toStringDelimiter(char delim)
{
	return model + delim + producator + delim + to_string(nr_vag);
}
Tren::~Tren()
{
	nr_vag = 0;
}