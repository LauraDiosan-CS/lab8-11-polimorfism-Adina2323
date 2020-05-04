#pragma once
#include "RepoFileCSV.h"
#include "RepoFileTXT.h"
#include"TestRepo.h"
#include "Tren.h"
#include "TrenMarfa.h"
#include "TrenPersoane.h"

class UI
{
private:
	Repo<User>* repoUser;
	Repo<Tren>* repoTren;
	Repo<TrenMarfa>* repoMarfa;
	Repo<TrenPersoane>* repoPersoane;

};