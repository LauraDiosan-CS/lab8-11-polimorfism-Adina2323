#include "TesteService.h"
#include"RepoFile.h"
#include "RepoFileTXT.h"
#include "RepoFileCSV.h"
#include "TrenMarfa.h"
#include "TrenPersoane.h"
#include <cassert>
#include <iostream>
#include "Validation.h"
#include "ValidationException.h"
#include "ValidationMarfa.h"
#include "ValidationPersoane.h"



TestService::TestService()
{
}

void TestService::runTests()
{
	Validation* validatorM = new ValidationMarfa();
	Validation* validatorP = new ValidationPersoane();
	RepoFile* r1 = new RepoFileTXT(validatorM);
	RepoFile* r2 = new RepoFileTXT(validatorP);
	Service s(*r1, *r2);
	assert(r1->getSize() == 0);
	string model = "Model"; string prod = "prod"; int nr = 1; string marfa = "cirese"; int lib = 2; int rez = 3;
	s.addTrenMarfa(model,prod,nr,lib,rez,marfa);
	string model1 = "model2";
	s.addTrenMarfa(model1,prod,nr,lib,rez,marfa);
	int locuri = 55;
	s.addTrenPersoane(model1, prod, nr, lib, rez, locuri);
	assert(s.getAll().size() == 3);
	assert(s.getAllTP().size() == 1);
	assert(s.getAllTM().size() == 2);
	s.delTM(model, prod, nr, lib, rez, marfa);
	assert(s.getAllTM().size() == 1);
	assert(s.getAll().size() == 2);

}


TestService::~TestService()
{
}
