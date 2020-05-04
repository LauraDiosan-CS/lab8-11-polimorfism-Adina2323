#pragma once
#include "RepoFile.h"
#include "RepoFileCSV.h"
#include "RepoFileTXT.h"
#include "RepoInMemory.h"
#include "Tren.h"
#include "TrenMarfa.h"
#include "TrenPersoane.h"
#include "User.h"

class TestRepo
{
private:
	void runCSVTests();
	void runTXTTests();
	void live();
	void runInMemoryTests();
public:
	TestRepo();
	void runTests();
	~TestRepo();
};

