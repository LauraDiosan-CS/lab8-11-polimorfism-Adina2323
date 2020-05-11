#pragma once
#include "Tren.h"
#include <exception>
using namespace std; 

class Validation
{
protected:
	int err;
	string mesaj;
public:
	Validation();
	virtual int validate(Tren*);
	string toString();
	~Validation();
};

