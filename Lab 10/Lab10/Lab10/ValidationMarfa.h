#pragma once
#include "TrenMarfa.h"
#include "Validation.h"
class ValidationMarfa:public Validation
{
public: 
	ValidationMarfa();
	int validate(Tren*);
	~ValidationMarfa();
};

