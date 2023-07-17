#pragma once
#include <string>
using namespace std;
class Componenta
{
	string culoare;
public:
	Componenta(string c) : culoare(c) {}
	virtual ~Componenta() { culoare = ""; }
	string getCuloare() { return culoare; }
	virtual string getComponent() = 0;
};

