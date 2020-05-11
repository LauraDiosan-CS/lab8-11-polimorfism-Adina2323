#pragma once
#include "Tren.h"

class TrenPersoane:public Tren
{
private:
	int locuri;
public:
	TrenPersoane();
	TrenPersoane(string, string, int, int, int, int);
	TrenPersoane(const TrenPersoane& t);

	Tren* clone();

	void setLocuri(int);
	int getLocuri();
	TrenPersoane& operator=(const TrenPersoane&);
	bool operator==(const TrenPersoane&);
	string toString(string delim);
	~TrenPersoane();
};