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
	TrenMarfa g1("104", "Fleishmann", 8, "carbuni", 30, 20);
	TrenMarfa g2("104", "Aron", 11, "benzina", 12, 9);
	TrenPersoane g3("106", "Alonso", 20, 300, 10, 2);
	TrenMarfa g4("103", "Amarra", 20, "petrol", 40, 10);
	TrenMarfa g5("105", "Fierra", 12, "lemn", 13, 11);

	Service service;
	try {
		service.addTrenMarfa("104", "Fleishmann", 8, 30, 20,"carbuni");
		service.addTrenMarfa("104", "Aron", 11, 12, 9,"benzina");
		service.addTrenPersoane("106", "Alonso", 20, 300, 10, 2);
		service.addTrenMarfa("103", "Amarra", 20, 40, 10,"petrol");
		service.addTrenMarfa("105", "Fierra", 12, 13, 11,"lemn");
	}
	catch (...) {
		assert(false);
	}
	assert(service.getsize() == 5);
	assert(service.getTrenAtPos(0)->getModel() == "104");
	assert(service.getTrenAtPos(1)->getModel() == "105");
	assert(service.getTrenAtPos(2)->getModel() == "106");
	assert(service.getTrenAtPos(3)->getModel() == "103");
	assert(service.getTrenAtPos(4)->getModel() == "107");


}


TestService::~TestService()
{
}
