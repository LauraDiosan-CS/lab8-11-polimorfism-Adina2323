#pragma once
#include "RepoFile.h"
#include <fstream>
template <class T> class RepoFileTXT :public RepoFile<T>
{
public:
	RepoFileTXT();
	RepoFileTXT(const char*);
	void loadFromFile();
	void saveToFile();
	~RepoFileTXT();
};

template<class T>
inline RepoFileTXT<T>::RepoFileTXT()
{
}

template<class T>
inline RepoFileTXT<T>::RepoFileTXT(const char* fName) :RepoFile<T>(fName)
{
}

template<class T>
inline void RepoFileTXT<T>::loadFromFile()
{
	string line;
	ifstream f(RepoFile<T>::fileName);
	while (getline(f, line)) {
		T ob(line, ' ');
		Repo<T>::elem.push_back(ob);
	}
}

template<class T>
inline void RepoFileTXT<T>::saveToFile()
{
	ofstream f(RepoFile<T>::fileName);
	for (T crt : Repo<T>::elem) {
		f << crt.toStringDelimiter(' ') << endl;
	}
}

template<class T>
inline RepoFileTXT<T>::~RepoFileTXT()
{
}
