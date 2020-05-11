#pragma once
#include "RepoFile.h"
#include "Validation.h"

class RepoFileTXT : public RepoFile {
public:
	RepoFileTXT();
	RepoFileTXT(Validation*);
	RepoFileTXT(string fileName);
	~RepoFileTXT();
	void loadFromFile();
	void saveToFile();
};