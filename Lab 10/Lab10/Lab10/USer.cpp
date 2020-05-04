#include "User.h"

User::User()
{
}
User::User(string name, string password) :userName(name), password(password)
{
}

string User::getUserName()
{
	return userName;
}
string User::getPassword()
{
	return password;
}
void User::setUserName(string new_username)
{
	userName = new_username;
}
void User::setPassword(string new_password)
{
	password = new_password;
}
bool User::operator==(const User& user)
{
	return(userName == user.userName) and (password == user.password);
}
string User::toString()
{
	return userName + " " + password;
}
string User::toStringDelimiter(char delimitator)
{
	return userName + delimitator + password;
}
User::~User()
{

}