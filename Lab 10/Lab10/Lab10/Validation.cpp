#include "Validation.h"
#include <string>
using namespace std;

Validation::Validation()
{
	err = 0;
}

int Validation::validate(Tren* v)
{
	err = 0;
	if ((v->getNr())<=-1) 
		{ err++; mesaj += "Nr de vag trebuie sa fie strict pozitiv!"; }
	if(v->getOcupate()<=-1)
		{ err++; mesaj += "Nr de locuri ocupate trebuie sa fie strict pozitiv!"; }
	if(v->getLibere()<=-1)
		{ err++; mesaj += "Nr de locuri libere trebuie sa fie strict pozitiv!"; }
	for (int i = 0; i < size(v->getProducator()); i++)
		if (!isalpha(v->getProducator()[i]) and v->getProducator()[i] != ' ')
			{ err++; mesaj += "Producatorul trebuie sa contina numai litere sau spatiu! "; break; }
	return err;
}

string Validation::toString()
{
	return mesaj;
}


Validation::~Validation()
{
}
