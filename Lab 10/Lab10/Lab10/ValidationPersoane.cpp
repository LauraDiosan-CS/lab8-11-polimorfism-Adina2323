#include "ValidationPersoane.h"
#include "ValidationException.h"
ValidationPersoane::ValidationPersoane()
{

}
void ValidationPersoane::validate(Tren* t)
{
	Validation::validate(t);
	TrenPersoane* tp = (TrenPersoane*)t;
	if (tp->getLocuri() <= 0)
	{
		throw ValidationException("Numarul de locuri trebuie sa fie strict poz");
	}
}

ValidationPersoane::~ValidationPersoane()
{}