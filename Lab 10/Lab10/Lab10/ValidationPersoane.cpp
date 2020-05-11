#include "ValidationPersoane.h"
ValidationPersoane::ValidationPersoane()
{

}
int ValidationPersoane::validate(Tren* t)
{
	TrenPersoane* tp = (TrenPersoane*)t;
	Validation::validate(tp);
	if (tp->getLocuri() < 0) { err++; mesaj += "Nr-ul de locuri trebuie sa fie strict pozitiv! ";
	}
	return err;
}

ValidationPersoane::~ValidationPersoane()
{}