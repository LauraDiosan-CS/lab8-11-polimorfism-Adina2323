#pragma once
#include "RepoFile.h"
#include "RepoUser.h"
#include "Service.h"
#include "RepoFileTXT.h"
#include "User.h"
class Service
{
protected:
	RepoFile* repo;
	IRepository<User>* repoUser;
public:
	Service();
	void setRepo(RepoFile* repo);
	Tren* getTrenAtPos(int pos);
	void addTrenMarfa(string,string,int,int,int,string);
	void addTrenPersoane(string, string, int, int, int,int);
	void updateTM(string, string, int, int, int,string, string, string, int, int, int, string);
	void updateTP(string, string, int, int, int,int,string, string, int, int, int, int);
	void delTren(string);
	int getsize();
	void upTren(string, string, string, int, int, int);
	Tren* getTrenModel(string);
	vector <Tren*> filterbyProd(string);
	vector <Tren*> filterbyNr(int);
	bool login(string, string);
	vector<Tren*> getAll();
	void loadFromfile();
	void saveFromFile();
	void setFileName(string fileName);
	~Service();
};

