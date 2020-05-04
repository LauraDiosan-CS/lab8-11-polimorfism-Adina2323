#pragma once
#include "Tren.h"

class TrenMarfa:public Tren
{
private:
	Tren t;
	string marfa;
	int nr_libere;
	int nr_ocupate;
public:
	TrenMarfa();
	//TrenMarfa(string, string, int, string, int, int);
	TrenMarfa(Tren&, string, int, int);
	TrenMarfa(string, char);
	Tren getTren();
	void setTren(Tren&);
	void setMarfa(string);
	void setLibere(int);
	void setOcupate(int);
	string getMarfa();
	int getLibere();
	int getOcupate();
	bool operator==(const TrenMarfa&);
	string toString();
	string toStringDelimiter(char delim);
	~TrenMarfa();
	friend class Tren;
};