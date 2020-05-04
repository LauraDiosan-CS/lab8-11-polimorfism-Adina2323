#include "TestRepo.h"
#include <assert.h>
#include <iostream>


void TestRepo::runCSVTests()
{
	/*Tren*/
	RepoFile<Tren>* repo = new RepoFileCSV<Tren>("Trenuri.csv");
	((RepoFileCSV<Tren>*)repo)->loadFromFile();
	assert(repo->size() == 2);
	Tren t1("modelut", "CFR", 23);
	repo->add(t1);
	((RepoFileCSV<Tren>*)repo)->saveToFile();
	assert(repo->find(t1) == 2);
	Tren t2("model1", "CFR", 22);
	repo->update(t1, t2);
	assert(repo->find(t2) == 2);
	assert(repo->find(t1) ==-1);
	assert(repo->size()==3);
	assert(repo->remove(t2) == 0);
	assert(repo->size() == 2);	
	//TrenMarfa
	RepoFile<TrenMarfa>* repo_marfa = new RepoFileCSV<TrenMarfa>("TrenuriMarfa.csv");
	((RepoFileCSV<TrenMarfa>*)repo_marfa)->loadFromFile();
	assert(repo_marfa->size() == 2);
	TrenMarfa m1(t1, "paie", 22, 12);
	repo_marfa->add(m1);
	assert(repo_marfa->size() == 3);
	cout << repo_marfa->find(m1);
	assert(repo_marfa->find(m1) == 2);
	((RepoFileCSV<TrenMarfa>*)repo_marfa)->saveToFile();
	TrenMarfa m2(t2,"paie", 100, 22);
	repo_marfa->update(m1, m2);
	assert(repo_marfa->find(m2) == 2);
	assert(repo_marfa->find(m1) == -1);
	assert(repo_marfa->size() == 3);
	assert(repo_marfa->remove(m2) == 0);
	assert(repo_marfa->size() == 2);

}
void TestRepo::runTXTTests()
{
	/*Tren*/
	RepoFile<Tren>* repo = new RepoFileTXT<Tren>("Trenuri.txt");
	((RepoFileTXT<Tren>*)repo)->loadFromFile();
	assert(repo->size() == 2);
	Tren t1("modelut", "CFR", 23);
	repo->add(t1);
	((RepoFileTXT<Tren>*)repo)->saveToFile();
	assert(repo->find(t1) == 2);
	Tren t2("model1", "CFR", 22);
	repo->update(t1, t2);
	assert(repo->find(t2) == 2);
	assert(repo->find(t1) == -1);
	assert(repo->size() == 3);
	assert(repo->remove(t2) == 0);
	assert(repo->size() == 2);
	//TrenPersoane
	RepoFile<TrenPersoane>* repo_persoane = new RepoFileTXT<TrenPersoane>("TrenuriPersoane.txt");
	((RepoFileTXT<TrenPersoane>*)repo_persoane)->loadFromFile();
	assert(repo_persoane->size() == 2);
	TrenPersoane p1(t1, 100, 22, 12);
	repo_persoane->add(p1);
	assert(repo_persoane->size() == 3);
	assert(repo_persoane->find(p1) == 2);
	((RepoFileTXT<TrenPersoane>*)repo_persoane)->saveToFile();
	TrenPersoane p2(t2, 255, 100, 22);
	repo_persoane->update(p1, p2);
	assert(repo_persoane->find(p2) == 2);
	assert(repo_persoane->find(p1) == -1);
	assert(repo_persoane->size() == 3);
	assert(repo_persoane->remove(p2) == 0);
	assert(repo_persoane->size() == 2);
}
//void TestRepo::live()
/*
{
	RepoFile<Tren>* repo = new RepoFileCSV<Tren>("fisier-111-1.csv");
	((RepoFileCSV<Tren>*)repo)->loadFromFile();
	Tren* g1 = new TrenMarfa("KBT8", "Fleishmann", 8, "carbuni", 10, 20);
	Tren* g2 = new TrenPersoane("A0JK", "Neumann", 10, 200, 4, 30);
	Tren* g3 = new TrenMarfa("B1xC", "Aron", 11, "benzina", 9, 12);
	Tren* g4 = new TrenPersoane("DIJ9", "Stora", 9, 150, 5, 28);
	assert(repo->size() == 2);*/
	/*
	assert(*(repo->get(0)) == *g2);
	assert(*(repo->get(1)) == *g1);
	repo->add(g3);
	assert(repo->getSize() == 3);
	assert(*(repo->get(0)) == *g2);
	assert(*(repo->get(1)) == *g3);
	assert(*(repo->get(2)) == *g1);
	repo->add(g4);
	assert(repo->getSize() == 4);
	assert(*(repo->get(0)) == *g2);
	assert(*(repo->get(1)) == *g3);
	assert(*(repo->get(2)) == *g4);
	assert(*(repo->get(3)) == *g1);*/



//}*/
void TestRepo::runInMemoryTests()
{
	//User
	Repo<User>* repoUseri = new RepoInMemory<User>();
	User u1("Ana", "123");
	User u2("Andrei", "111");
	repoUseri->add(u1);
	assert(repoUseri->size() == 1);
	assert(repoUseri->find(u1) == 0);
	repoUseri->update(u1, u2);
	assert(repoUseri->find(u1) == -1);
	assert(repoUseri->remove(u2) == 0);
	assert(repoUseri->size() == 0);

}

TestRepo::TestRepo()
{
}



void TestRepo::runTests()
{
	runCSVTests();
	runTXTTests();
	runInMemoryTests();
	//live();
}


TestRepo::~TestRepo()
{
}
