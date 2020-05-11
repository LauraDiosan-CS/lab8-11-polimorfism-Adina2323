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
	Service s;
	User u;
public:
	int login();
};