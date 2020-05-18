#pragma once
#include "RepoFileCSV.h"
#include "RepoFileTXT.h"
#include"TestRepo.h"
#include "Tren.h"
#include "TrenMarfa.h"
#include "TrenPersoane.h"
#include "Service.h"

class UI
{
protected:
	Service serv;
	User u;
	int login();
	void showMenu();
	void chooseFileType();
	void UILoadFromFile();
	void UIAddTrenMarfa();
	void UIAddTrenPersoane();
	void UIModifyTren();
	void UIDeleteTren();
	void UIShowAll();
	void printTren(vector<Tren*> trenuri);
	void getByNr();
	void getByProd();
	void ModifyRezervari();
public:
	UI();
	~UI();
	void run();
};