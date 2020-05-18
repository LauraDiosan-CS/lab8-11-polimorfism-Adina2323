#pragma once
#include "Tren.h"
#include "Validation.h"
#include "ValidationException.h"
#include "Validation.h"
#include "ValidationMarfa.h"
#include "ValidationPersoane.h"
#include <vector>

using namespace std;

class RepoFile {
protected:
	vector<Tren*> garnituri;
	string fileName;
	ValidationMarfa validatorTM;
	ValidationPersoane validatopTP;
public:
	RepoFile();
	RepoFile(Validation*);
	RepoFile(string fileName);
	~RepoFile();
	void setFileName(string fileName);

	vector<Tren*> getAll();
	int getSize();
	Tren* getTren(int pos);
	void addTren(Tren* p);
	void updateTren(Tren* pVechi, Tren* pNou);
	void deleteTren(Tren* p);
	void emptyRepo();
	int findTren(Tren* t);

	virtual void loadFromFile() = 0;
	virtual void saveToFile() = 0;
};
