#pragma once
#include "RepoFile.h"
#include "RepoUser.h"
#include "Service.h"
#include "RepoFileTXT.h"
#include "User.h"
class Service
{
protected:
	RepoFile* repoMarfa;
	RepoFile* repoPers;
	IRepository<User>* repoUser;
public:
	Service();
	Service(RepoFile&, RepoFile&);
	void addTrenMarfa(string,string,int,int,int,string);
	void addTrenPersoane(string, string, int, int, int,int);
	//int updateTM(string, string, int, int, int, int,string, string, int, int, int, int);
	//int updateTP(string, string, int, int, int, string,string, string, int, int, int, string);
	void delTM(string, string, int, int, int, string);
	void delTP(string, string, int, int, int, int);
	bool login(string, string);
	vector<Tren*> getAll();
	vector<Tren*> getAllTP();
	vector<Tren*> getAllTM();
	~Service();
};

