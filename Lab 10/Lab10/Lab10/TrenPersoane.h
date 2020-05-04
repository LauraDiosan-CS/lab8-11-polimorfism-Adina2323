#pragma once
#include "Tren.h"

class TrenPersoane:public Tren
{
private:
	Tren t;
	int locuri;
	int nr_libere;
	int nr_ocupate;
public:
	TrenPersoane();
	//TrenPersoane(string, string, int, int, int, int);
	TrenPersoane(Tren&, int, int, int);
	TrenPersoane(string, char);
	Tren getTren();
	void setTren(Tren&);
	void setLocuri(int);
	void setLibere(int);
	void setOcupate(int);
	int getLocuri();
	int getLibere();
	int getOcupate();
	bool operator==(const TrenPersoane&);
	string toString();
	string toStringDelimiter(char delim);
	~TrenPersoane();
	friend class Tren;
};