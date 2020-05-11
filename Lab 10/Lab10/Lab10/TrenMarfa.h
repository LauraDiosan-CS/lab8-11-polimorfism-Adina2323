#pragma once
#include "Tren.h"

class TrenMarfa:public Tren
{
private:
	string marfa;

public:
	TrenMarfa();
	TrenMarfa(string, string, int, string, int, int);
	TrenMarfa(const TrenMarfa&);
	Tren* clone();

	void setMarfa(string);
	string getMarfa();

	TrenMarfa& operator=(const TrenMarfa& t);
	bool operator==(const TrenMarfa&);
	string toString(string delim);
	~TrenMarfa();
};