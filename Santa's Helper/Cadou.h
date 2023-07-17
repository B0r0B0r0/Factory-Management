#pragma once
#include<vector>
#include"Componenta.h"
using namespace std;
class Cadou
{
	vector<Componenta*> comps;
public:
	Cadou() {}
	~Cadou() { comps.clear(); }
	void adaugaComponenta(Componenta* C);
	string getComponents();
};

