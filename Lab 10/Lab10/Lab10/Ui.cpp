#include "UI.h"
#include "User.h"
#include <iostream>
#include "RepoFileTXT.h"
#include "RepoFileCSV.h"
#include "ValidationException.h"
#include "ReadFromFileException.h"
#include <fstream>
#include "RepoException.h"
#include <istream>
#include <conio.h>
using namespace std; 
int UI::login()
{
	string user, pass;
	cout << "Dati user: ";
	cin >> user;
	u.setUserName(user);
	cout <<  "Parola:";
	cin >> pass;
	u.setPassword(pass);
	return serv.login(user, pass);
}
void UI::showMenu()
{
	cout << "1. Citeste din fisier\n";
	cout << "2. Afiseaza toate trenurile\n";
	cout << "3. Adauga tren marfa\n";
	cout << "4. Adauga tren persoane\n";
	cout << "5. Modifica tren\n";
	cout << "6. Sterge tren\n";
	cout << "7. Afiseaza trenuri cu producatorul dat\n";
	cout << "8.Afiseaza trenuri cu nr de vagoane dat\n";
	cout << "9.Rezerva Tren\n";
	cout << "----------------\n";
	cout << "0. Logout\n";
}
void UI::chooseFileType()
{
	int option = 0;
	cout << "Alegeti ce tip de fisier doriti. Scrieti 1 pt. TXT si 2 pt. CSV: ";
	cin >> option;
	while (option < 1 || option > 2)
	{
		cout << "Ati trecut un identificator gresit! Scrieti 1 pt. TXT si 2 pt. CSV: ";
		cin >> option;
	}
	if (option == 1)
	{
		this->serv.setRepo(new RepoFileTXT("TrenuriIN.txt"));
	}
	else
	{
		this->serv.setRepo(new RepoFileCSV("TrenuriIN.csv"));
	}
}
void UI::UILoadFromFile()
{
	try {
		this->serv.loadFromfile();
	}
	catch (ReadFromFileException& e) {
		cout << e.what() << endl;
		cout << "Dati un alt nume de fisier: ";
		string fileName;
		getline(cin, fileName);
		this->serv.setFileName(fileName);
	}
	catch (ValidationException& e) {
		cout << e.what() << endl;
	}
}
void UI::UIAddTrenMarfa()
{
	cout << "Dati modelul: ";
	string model; string prod; string marfa;
	cin >> model;
	cout << "Dati numele producatorului: ";
	cin >> prod;
	cout << "Dati numarul de vagoane: ";
	int nr, rez, lib;
	cin >> nr;
	cout << "Dati numarul de vagoane disponibile: ";
	cin >> lib;
	cout << "Dati numarul de vagoane ocupate: ";
	cin >> rez;
	cout << "Dati tipul de marfa: ";
	cin >> marfa;
	try {
		this->serv.addTrenMarfa(model, prod, nr, lib, rez, marfa);
	}
	catch (ValidationException& e)
	{
		cout << e.what() << endl;
	}
	catch (RepoException& e) {
		cout << e.what() << endl;
	}
}
void UI::UIAddTrenPersoane()
{
	cout << "Dati modelul: ";
	string model; string prod; 
	cin >> model;
	cout << "Dati numele producatorului: ";
	cin >> prod;
	cout << "Dati numarul de vagoane: ";
	int nr, rez, lib,loc;
	cin >> nr;
	cout << "Dati numarul de vagoane disponibile: ";
	cin >> lib;
	cout << "Dati numarul de vagoane ocupate: ";
	cin >> rez;
	cout << "Dati numarul de locuri";
	cin >> loc;
	try {
		this->serv.addTrenPersoane(model, prod, nr, lib, rez, loc);
	}
	catch (ValidationException& e)
	{
		cout << e.what() << endl;
	}
	catch (RepoException& e) {
		cout << e.what() << endl;
	}
}
void UI::UIModifyTren()
{
	cout << " Dati modelul vechiului Tren: ";
	string modelV;
	cin >> modelV;
	int op;
	do {
		cout << "Ce fel de tren doriti sa modificati?1. Marfa 2.Persoane";
		cin >> op;
	} while (op < 1 || op>2);
	cin.ignore();
	cout << "Dati noul model: ";
	string modN, prodN;
	cin >> modN;
	cout << "Dati noul producator: ";
	cin >> prodN;
	int nr, rez, lib;
	cout << "Dati numarul de vagoane: ";
	cin >> nr;
	cout << "Dati numarul de vagoane disponibile: ";
	cin >> lib;
	cout << "Dati numarul de vagoane ocupate: ";
	cin >> rez;
	if (op == 1) {
		string marfa;
		cout << "Dati tipul de marfa";
		cin >> marfa;
		try {
			this->serv.updateTM(modelV, prodN, nr, rez, lib, marfa, modN, prodN, nr, rez, lib, marfa);

		}
		catch (ValidationException& e)
		{
			cout << e.what() << endl;
		}
		catch (RepoException& e)
		{
			cout << e.what() << endl;
		}
	}
	else {
		int loc;
		cout << "Dati numarul de locuri: ";
		cin >> loc;
		try {
			this->serv.updateTP(modelV, prodN, nr, rez, lib, loc, modN, prodN, nr, rez, lib, loc);

		}
		catch (ValidationException& e)
		{
			cout << e.what() << endl;
		}
		catch (RepoException& e)
		{
			cout << e.what() << endl;
		}
	}

}
void UI::UIDeleteTren()
{
	cout << "Dati modelul trenului de sters: ";
	string model;
	cin >> model;
	try {
		this->serv.delTren(model);
	}
	catch (RepoException& e)
	{
		cout << e.what() << endl;
	}
}
void UI::UIShowAll()
{
	this->printTren(this->serv.getAll());
}
void UI::printTren(vector <Tren*> trens)
{
	for (Tren* t : trens)
	{
		cout << t->toString(" ").erase(0, 3) << endl;
	}
}
void UI::getByNr()
{
	int nr;
	cout << "Dati numarul de vagoane dorit: ";
	cin >> nr;
	this->printTren(this->serv.filterbyNr(nr));
}
void UI::getByProd()
{
	string prod;
	cout << "Introduceti producatorul: ";
	cin >> prod;
	this->printTren(this->serv.filterbyProd(prod));
}
void UI::ModifyRezervari()
{
	vector <Tren*> trens = this->serv.getAll();
	cout << " Dati modelul vechiului Tren: ";
	string modelV;
	cin >> modelV;
	cout << "introduceti numatul de vagoane pe care doriti sa il rezervati: ";
	int vag;
	cin >> vag;
		Tren* t =serv.getTrenModel(modelV);
		int max = t->getNr();
		int ocupate = t->getOcupate();
		if (vag +ocupate >max)
		{
			cout << "Numarul de vagoane inserat este prea mare!";
		}
		else try {
			this->serv.upTren(modelV, modelV, t->getProducator(), max, t->getLibere() - vag, vag + t->getOcupate());
			for (Tren* t : this->serv.getAll())
			{
				if (t->getNr() == t->getOcupate())
				{
					cout << t->toString(" ").erase(0,3)<<endl;
				}
				else cout << t->toString(" ").erase(0, 3) << endl;
			}
		}
		catch (ValidationException& e)
		{
			cout << e.what() << endl;
		}
		catch (RepoException& e)
		{
			cout << e.what() << endl;
		}	
}
UI::UI()
{

}
UI::~UI()
{

}
void UI::run()
{
	this->chooseFileType();
	bool shouldRun = true;
	int option;
	while (shouldRun)
	{
		this->showMenu();
		cin >> option;
		cin.ignore();
		switch (option)
		{
		case 1: {
			this->UILoadFromFile();
			break;
		}
		case 2: {
			this->UIShowAll();
			break;
		}
		case 3: {
			this->UIAddTrenMarfa();
			break;
		}
		case 4: {
			this->UIAddTrenPersoane();
			break;
		}
		case 5: {
			this->UIModifyTren();
			break;
		}
		case 6: {
			this->UIDeleteTren();
			break;
		}
		case 7: {
			this->getByProd();
			break;
		}
		case 8: {
			this->getByNr();
			break;
		}
		case 9: {
			this->ModifyRezervari();
			break;
		}
		case 0: {
			shouldRun = false;
			break;
		}
		default: {
			break;
		}
		}
	}
}