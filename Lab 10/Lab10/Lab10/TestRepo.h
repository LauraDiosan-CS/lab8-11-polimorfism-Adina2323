#pragma once
#include <vector>
#include "Tren.h"
class TestRepo
{
private:
	const string fileNameInTXT = "TrenuriIN.txt";
	const string fileNameOutTXT = "TrenuriOut.txt";
	const string fileNameInCSV = "TrenuriIN.csv";
	const string fileNameOutCSV = "TrenuriOut.csv";

	vector<Tren*> garnituri;

	void testGetAll();
	void testGetSize();
	void testGetProdus();
	void testAddProdus();
	void testUpdateProdus();
	void testDeleteProdus();

	void testLoadFromFileTXT();
	void testSaveToFileTXT();
	void testLoadFromFileCSV();
	void testSaveToFileCSV();
	void live();
public:
	TestRepo();
	~TestRepo();
	void testAll();
};

