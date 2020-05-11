#include "ValidationMarfa.h"
ValidationMarfa::ValidationMarfa()
{

}
int ValidationMarfa::validate(Tren* t)
{
	TrenMarfa* tm = (TrenMarfa*)t;
	Validation::validate(tm);
	for (int i = 0; i < size(tm->getMarfa()); i++)
		if (!isalpha(tm->getMarfa()[i]) and tm->getMarfa()[i] != ' ') { err++; mesaj += "Marfa trebuie sa contina numai litere sau spatiu! "; break; }
	return err;
}

ValidationMarfa::~ValidationMarfa()
{}