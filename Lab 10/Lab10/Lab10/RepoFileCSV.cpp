#include "RepoFileCSV.h"
#include <fstream>
#include "TrenMarfa.h"
#include "TrenPersoane.h"
#include "ReadFromFileException.h"

RepoFileCSV::RepoFileCSV() : RepoFile()
{

}

RepoFileCSV::RepoFileCSV(string fileName) : RepoFile(fileName)
{

}

RepoFileCSV::~RepoFileCSV()
{

}

void RepoFileCSV::loadFromFile()
{
	ifstream f(this->fileName);
	if (f.is_open())
	{
		this->emptyRepo();
		string linie;
		string delimitator = ",";
		try {
			while (getline(f, linie))
			{
				if (linie.substr(0, 2) == "TM")
				{
					linie = linie.erase(0, 3);

					int poz = linie.find(delimitator);
					string model = linie.substr(0, poz);
					linie = linie.erase(0, poz + 1);

					poz = linie.find(delimitator);
					string  producator = linie.substr(0, poz);
					linie = linie.erase(0, poz + 1);

					poz = linie.find(delimitator);
					int nr_vag = stol(linie.substr(0, poz));
					linie = linie.erase(0, poz + 1);

					poz = linie.find(delimitator);
					int nr_libere = stol(linie.substr(0, poz));
					linie = linie.erase(0, poz + 1);

					poz = linie.find(delimitator);
					int nr_ocup = stol(linie.substr(0, poz));
					linie = linie.erase(0, poz + 1);

					string marfa = linie;

					TrenMarfa* tm = new TrenMarfa(model, producator, nr_vag, marfa, nr_libere, nr_ocup);
					this->garnituri.push_back(tm);
				}
				if (linie.substr(0, 2) == "TP")
				{
					linie = linie.erase(0, 3);

					int poz = linie.find(delimitator);
					string model = linie.substr(0, poz);
					linie = linie.erase(0, poz + 1);

					poz = linie.find(delimitator);
					string  producator = (linie.substr(0, poz));
					linie = linie.erase(0, poz + 1);

					poz = linie.find(delimitator);
					int nr_vag = stol(linie.substr(0, poz));
					linie = linie.erase(0, poz + 1);

					poz = linie.find(delimitator);
					int nr_libere = stol(linie.substr(0, poz));
					linie = linie.erase(0, poz + 1);

					poz = linie.find(delimitator);
					int nr_ocup = stol(linie.substr(0, poz));
					linie = linie.erase(0, poz + 1);

					int locuri = stol(linie);

					TrenPersoane* tp = new TrenPersoane(model, producator, nr_vag, locuri, nr_libere, nr_ocup);
					this->garnituri.push_back(tp);
				}
			}
		}
		catch (...)
		{
			throw ReadFromFileException("formatul datelor nu convine!");
		}
		f.close();
	}
	else {
		throw ReadFromFileException("fisierul nu exista!");
	}
}

void RepoFileCSV::saveToFile()
{
	ofstream f(this->fileName);
	if (f.is_open())
	{
		for (Tren* elem : this->garnituri)
		{
			f << elem->toString(",") << endl;
		}
	}
}
