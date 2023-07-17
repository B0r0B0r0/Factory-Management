#include "Cadou.h"
#include <string>

void Cadou::adaugaComponenta(Componenta* C)
{
	comps.push_back(C);
}

string Cadou::getComponents()
{
	string buff;
	buff = "[" + comps[0]->getComponent() + "][" + comps[0]->getCuloare() + "]";
	return buff;
	
}
