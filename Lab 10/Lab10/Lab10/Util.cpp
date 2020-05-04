#include "Util.h"
#include <sstream>
#include <iostream>
using namespace std;

vector<string> splitLine(string linie, char delim)
{

	stringstream ss(linie);
	string item;
	vector<string> elems;
	while (getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}
