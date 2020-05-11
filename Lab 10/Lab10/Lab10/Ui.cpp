#include "UI.h"
#include "User.h"
#include<iostream>
using namespace std; 

int UI::login()
{
	string user, pass;
	u.setUserName(user);
	u.setPassword(pass);
	cout << "Dati user: ";
	cin >> user;
	cout << endl << "Parola:";
	cin >> pass;
	return s.login(user, pass);
}