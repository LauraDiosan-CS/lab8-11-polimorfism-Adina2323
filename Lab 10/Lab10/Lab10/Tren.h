#pragma once
#include <string>
using namespace std;
class Tren
{
private:
	string model;
	string producator;
	int nr_vag;
public: 
	Tren();
	Tren(string model, string prod, int nr);
	Tren(string linie, char delim);
	string getModel();
	string getProducator();
	int getNr();
	void setModel(string new_model);
	void setProducator(string new_prod);
	void setNrVag(int new_nr);
	bool operator==(const Tren&);
	string toString();
	string toStringDelimiter(char delim);
	~Tren();
	friend class TrenPersoane;
	friend class TrenMarfa;
};

