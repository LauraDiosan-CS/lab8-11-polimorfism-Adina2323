#include "ValidationMarfa.h"
#include "ValidationException.h"
ValidationMarfa::ValidationMarfa()
{

}
void ValidationMarfa::validate(Tren* t)
{
	Validation::validate(t);
	TrenMarfa* tm = (TrenMarfa*)t;
	if (tm->getMarfa().empty())
	{
		throw ValidationException("Marfa trebuie sa fie specificata");
	}
	for (char c : tm->getMarfa()) {
		if (!isalpha(c))
		{
			throw ValidationException("Marfa trebuie sa contina doar litere");
		}
	}
	
}

ValidationMarfa::~ValidationMarfa()
{}