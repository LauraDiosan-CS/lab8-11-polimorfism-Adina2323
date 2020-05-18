#pragma once
#include <string>
using namespace std;
class Tren
{
protected:
	string model;
	string producator;
	int nr_vag;
	int nr_libere;
	int nr_ocupate;
public: 
	Tren();
	Tren(string model, string prod, int nr,int lib, int ocup);
	Tren(const Tren&p);

	virtual Tren* clone();

	string getModel();
	string getProducator();
	int getNr();
	int getLibere();
	int getOcupate();
	void setModel(string new_model);
	void setProducator(string new_prod);
	void setNrVag(int new_nr);
	void setLibere(int);
	void setOcupate(int);

	Tren& operator=(const Tren&);
	bool operator==(const Tren&);
	friend istream& operator>>(ifstream& is, Tren* t);
	virtual string toString(string);
	~Tren();
};

