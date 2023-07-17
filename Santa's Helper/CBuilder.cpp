#include "CBuilder.h"
#include"Roti.h"
#include"Motor.h"
#include"Turnuri.h"

void CBuilder::construiesteMasina()
{
	system("cls");
	cout << "Introduceti culoarea masinii:";
	string c; cin >> c;
	cout << "Introduceti cati cai putere are motorul:";
	int n; cin >> n;
	Componenta* aux = new Motor(c, n);
	cadouComplet->adaugaComponenta(aux);
}

void CBuilder::construiesteBicicleta()
{
	system("cls");
	cout << "Introduceti culoarea bicicletei:";
	string c; cin >> c;
	cout << "Introduceti diametrul rotilor:";
	int d; cin >> d;
	cadouComplet->adaugaComponenta(new Roti(c, d));
}

void CBuilder::construiesteCastel()
{
	system("cls");
	cout << "Introduceti culoarea castelului:";
	string c;cin >> c;
	cout << "Introduceti numarul de turnuri ale castelului:";
	int n; cin >> n;
	cadouComplet->adaugaComponenta(new Turnuri(c, n));
}

Cadou* CBuilder::getCadou()
{
	Cadou* aux = cadouComplet;
	reset();
	return aux;
}
