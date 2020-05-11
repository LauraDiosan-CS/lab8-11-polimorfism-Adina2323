#include "TestRepo.h"
#include "RepoFileTXT.h"
#include "RepoFileCSV.h"
#include "TrenMarfa.h"
#include "TrenPersoane.h"
#include <cassert>
#include <iostream>
#include "Validation.h"
#include "ValidationException.h"
void TestRepo::testGetAll()
{
	RepoFile* repoFile = new RepoFileTXT();
	TrenPersoane* t1 = new TrenPersoane("model1"," cfrm", 23, 50, 23, 27);
	TrenMarfa* t2 = new TrenMarfa("model2"," CFR", 100, "ceapa", 4, 2);
	repoFile->addTren(t1);
	repoFile->addTren(t2);
	vector<Tren*> produse = repoFile->getAll();
	assert(repoFile->getSize() == 2);
	assert(*garnituri[0] == *t1);
	assert(*garnituri[1] == *t2);
}

void TestRepo::testGetSize()
{
	RepoFile* repoFile = new RepoFileTXT();
	assert(repoFile->getSize() == 0);
	TrenMarfa* p = new  TrenMarfa("model2", " CFR", 100, "ceapa", 4, 2);
	repoFile->addTren(p);
	assert(repoFile->getSize() == 1);
}

void TestRepo::testGetProdus()
{
	RepoFile* repoFile = new RepoFileTXT();
	TrenMarfa* p = new  TrenMarfa("model2", " CFR", 100, "ceapa", 4, 2);
	repoFile->addTren(p);
	assert(*(repoFile->getTren(0)) == *p);
	
}

void TestRepo::testAddProdus()
{
	RepoFile* repoFile = new RepoFileTXT();
	TrenMarfa* p = new  TrenMarfa("model2", " CFR", 100, "ceapa", 4, 2);
	repoFile->addTren(p);
	assert(*(repoFile->getTren(0)) == *p);
}

void TestRepo::testUpdateProdus()
{
	RepoFile* repoFile = new RepoFileTXT();
	TrenMarfa* p1 = new  TrenMarfa("model2", " CFR", 100, "ceapa", 4, 2);
	repoFile->addTren(p1);
	TrenPersoane* t1 = new TrenPersoane("model1", " cfrm", 23, 50, 23, 27);
	TrenPersoane* t2 = new TrenPersoane("model1", " cfrm", 100, 2, 2, 2);
	repoFile->updateTren(t1, t2);
	assert(*(repoFile->getTren(0)) == *p1);
	repoFile->updateTren(p1, t2);
	assert(*(repoFile->getTren(0)) == *t2);
}

void TestRepo::testDeleteProdus()
{
	RepoFile* repoFile = new RepoFileTXT();
	TrenMarfa* p1 = new  TrenMarfa("model2", " CFR", 100, "ceapa", 4, 2);
	repoFile->addTren(p1);
	TrenPersoane* t1 = new TrenPersoane("model1", " cfrm", 23, 50, 23, 27);
	repoFile->deleteTren(p1);
	assert(repoFile->getSize() == 0);
	repoFile->addTren(t1);
	assert(*(repoFile->getTren(0)) == *t1);
	repoFile->deleteTren(t1);
	assert(repoFile->getSize() == 0);
}

void TestRepo::testLoadFromFileTXT()
{
	RepoFile* repoFile = new RepoFileTXT(this->fileNameInTXT);
	repoFile->loadFromFile();
	assert(repoFile->getSize() == 4);
}

void TestRepo::testSaveToFileTXT()
{
	RepoFile* repoFile = new RepoFileTXT(this->fileNameInTXT);
	repoFile->loadFromFile();
	repoFile->setFileName(this->fileNameOutTXT);
	TrenPersoane* t1 = new TrenPersoane("model1", " cfrm", 23, 50, 23, 27);
	repoFile->addTren(t1);
	repoFile->saveToFile();
	
}

void TestRepo::testLoadFromFileCSV()
{
	RepoFile* repoFile = new RepoFileCSV(this->fileNameInCSV);
	repoFile->loadFromFile();
	assert(repoFile->getSize() == 4);
}

void TestRepo::testSaveToFileCSV()
{
	RepoFile* repoFile = new RepoFileCSV(this->fileNameInCSV);
	repoFile->loadFromFile();
	repoFile->setFileName(this->fileNameOutCSV);
	TrenPersoane* t1 = new TrenPersoane("model1", " cfrm", 23, 50, 23, 27);
	repoFile->addTren(t1);
	repoFile->saveToFile();
}

TestRepo::TestRepo()
{
	TrenPersoane* t1 = new TrenPersoane("model1", " cfrm", 23, 50, 23, 27);
	TrenMarfa* t2 = new TrenMarfa("model2", " CFR", 100, "ceapa", 4, 2);
	this->garnituri.push_back(t1);
	this->garnituri.push_back(t2);
}

TestRepo::~TestRepo()
{
}
void TestRepo::live()
{
	RepoFile* repo = new RepoFileTXT();
	TrenMarfa* g1 = new TrenMarfa("104", "Fleishmann", 8, "carbuni", 10, 20);
	TrenPersoane* g2 = new TrenPersoane("749", "Neumann", 10, 200, 4, 30);
	TrenMarfa* g3 = new TrenMarfa("951", "Aron", 11, "benzina", 9, 12);
	TrenPersoane* g4 = new TrenPersoane("104", "Alonso", 20, 300, 2, 10);
	TrenMarfa* g5 = new TrenMarfa("354", "Fierra", 12, "lemn", 11, 13);
	repo->addTren(g1);
	repo->addTren(g2);
	repo->addTren(g3);
	try {
		repo->updateTren(g2, g4);
		assert(repo->getSize() == 3);
		assert(*(repo->getTren(0)) == *g1);
		assert(*(repo->getTren(1)) == *g4);
		assert(*(repo->getTren(2)) == *g3);
	}
	catch (exception& e)
	{
			UpdateException1:
		cout << "Assert false";
			UpdateException2:
		cout << "Assert false";
			UpdateException3:
		cout << "Assert false";
	}/*
	try {}
			Update Train with model “770” to g5
			Assert false
			Catch
			UpdateException1 :
		Print “UpdateException1 thrown”
			Assert Size equals 3
			Assert GetAtPos(0) equals g1
			Assert GetAtPos(1) equals g4
			Assert GetAtPos(2) equals g3
			UpdateException2 :
		Assert false
			UpdateException3 :
			Assert false
			Try
			Update Train with model “104” to g4
			Assert false
			Catch
			UpdateException1 :
		Assert false
			UpdateException2 :
			Print “UpdateException2 thrown”
			Assert Size equals 3
			Assert GetAtPos(0) equals g1
			Assert GetAtPos(1) equals g4
			Assert GetAtPos(2) equals g3
			UpdateException3 :
		Assert false
			Try
			Update Train with model “770” to g5
			Assert false
			Catch
			UpdateException3
			Print “UpdateException3 thrown”
			UpdateException1
			Assert false
			UpdateException2
			Assert false
			Try
			Update Train with model “104” to g5
			Assert false
			Catch
			UpdateException3 :
		Print “UpdateException3 thrown”
			UpdateException1 :
		Assert false
			UpdateException2 :
			Assert false*/

	
}
void TestRepo::testAll()
{
	this->testGetAll();
	this->testGetSize();
	this->testGetProdus();
	this->testAddProdus();
	this->testUpdateProdus();
	this->testDeleteProdus();
	this->testLoadFromFileTXT();
	this->testSaveToFileTXT();
	this->testLoadFromFileCSV();
	this->testSaveToFileCSV();
	this->live();
}
