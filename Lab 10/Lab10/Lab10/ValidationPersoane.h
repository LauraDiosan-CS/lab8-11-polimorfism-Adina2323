#pragma once
#include "TrenPersoane.h"
#include "Validation.h"
class ValidationPersoane:public Validation
{
public:
	ValidationPersoane();
	int validate(Tren*);
	~ValidationPersoane();
};

