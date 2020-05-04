#pragma once
#include "RepoFile.h"
#include <fstream>
using namespace std;

template  <class T> class RepoFileCSV :
	public RepoFile<T>
{
public:
	RepoFileCSV();
	RepoFileCSV(const char*);
	void loadFromFile();
	void saveToFile();
	~RepoFileCSV();
};
template<class T>
RepoFileCSV<T>::RepoFileCSV()
{
}

template<class T>
inline RepoFileCSV<T>::RepoFileCSV(const char* fName) :RepoFile<T>(fName)
{
}

template<class T>
void RepoFileCSV<T>::loadFromFile()
{
	string line;
	ifstream f(RepoFile<T>::fileName);
	while (getline(f, line)) {
		T ob(line, ',');
		Repo<T>::elem.push_back(ob);
	}
}

template<class T>
void RepoFileCSV<T>::saveToFile()
{
	ofstream f(RepoFile<T>::fileName);
	for (T crt : Repo<T>::elem) {
		f << crt.toStringDelimiter(',') << endl;
	}
}

template<class T>
RepoFileCSV<T>::~RepoFileCSV()
{
}

