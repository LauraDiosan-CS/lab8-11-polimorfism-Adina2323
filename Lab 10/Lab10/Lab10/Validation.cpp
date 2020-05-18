#include "Validation.h"
#include "ValidationException.h"
#include <string>
using namespace std;

Validation::Validation()
{
	err = 0;
}

void Validation::validate(Tren* v)
{
	err = 0;
	if (v->getModel().empty())
	{
		throw ValidationException("Modelul nu poate fi gol!");
	}
	if ((v->getNr()) < 0)
	{
		throw ValidationException("Numarul de vagoane trebuie sa fie strict pozitiv");
	}
	if (v->getOcupate() <= -1)
	{
		throw ValidationException("Numarul de vagoane libere trebuie sa fie strict pozitiv");
	}
	if (v->getLibere() <= -1)
	{
		throw ValidationException("Numarul de vagoane ocupate trebuie sa fie strict pozitiv");
	}
	for (char c : v->getProducator())
	{
		if (!isalpha(c))
		{
			throw ValidationException("Numele Producatorului trebuie sa fie format doar din litere");
		}
	}
}

string Validation::toString()
{
	return mesaj;
}


Validation::~Validation()
{
}
