#pragma once
#include "TrenPersoane.h"
#include "Validation.h"
class ValidationPersoane:public Validation
{
public:
	ValidationPersoane();
	void validate(Tren*);
	~ValidationPersoane();
};

