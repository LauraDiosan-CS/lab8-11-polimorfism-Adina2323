#pragma once
#include "Tren.h"
#include "Validation.h"
#include "ValidationException.h"
#include "Validation.h"
#include <vector>

using namespace std;

class RepoFile {
protected:
	vector<Tren*> garnituri;
	string fileName;
	Validation* validation=new Validation;
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

	virtual void loadFromFile() = 0;
	virtual void saveToFile() = 0;
};
