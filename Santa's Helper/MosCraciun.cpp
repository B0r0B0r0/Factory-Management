#include "MosCraciun.h"
#include <iostream>
#include<conio.h>
#include<sstream>

bool MosCraciun::verifyData(string data)
{
	istringstream buffer(data);
	string token;
	getline(buffer, token, '/');	
	if (stoi(token) < 1 || stoi(token) > 31)
		return false;
	getline(buffer, token, '/');
	if (stoi(token) < 1 || stoi(token) > 12)
		return false;
	getline(buffer, token, '/');
	if (stoi(token) < 2005 || stoi(token) > 2023)
		return false;
	return true;	
}

bool MosCraciun::verifyFlag(string flag)
{
	if (flag == "obraznic" || flag == "cuminte")
		return true;
	return false;
}

void MosCraciun::adaugaCopil()
{
	system("cls");
	string nume, adr,aux;
	cout << "Introduceti numele si prenumele copilului: ";
	cin >> aux; nume = aux + " "; cin >> aux; nume += aux;
	cout << "Introduceti data nasterii (zi/luna/an): ";
	cin >> aux; 
	if (!verifyData(aux))
		throw MyException("Data este trecuta incorect", 2);
	nume += " "+aux;
	cout << "A fost obraznic sau cuminte: ";
	cin >> aux; 
	if (!verifyFlag(aux))
		throw MyException("Introducerea cuminteniei gresita", 3);
	nume += " " + aux;
	cout << "Introduceti adresa copilului (Tara Judet Localitate Strada Numar):  ";
	cin >> aux; adr = aux + " jud "; cin >> aux;adr += aux + " loc ";cin>>aux;adr += aux + " str ";cin >> aux;adr += aux + " nr ";cin >> aux; adr += aux;
	ManagerDP::create(nume, adr);
	
}

void MosCraciun::adaugaJucarie()
{
	system("cls");
	cout << "Introduceti indicele copilului caruia doriti sa ii adaugati un cadou:\n";
	int i;
	i = _getch()-'0';
	system("cls");
	cout << "Introduceti numarul corespunzator cadoului dorit:\n1)Masina\n2)Bicicleta\n3)Castel\n";
	int c;
	c = _getch()-'0';
	switch (c)
	{
	case 1:
		ManagerCD::create("Masina",i-1);
		break;
	case 2:
		ManagerCD::create("Bicicleta",i-1);
		break;
	case 3:
		ManagerCD::create("Castel",i-1);
		break;
	}
}

void MosCraciun::show()
{
	system("cls");
	cout << "Introduceti ce doriti sa vedeti:\n1)Date Personale\n2)Adrese\n3)Cadouri Dorite\n4)Cadouri Primite\n";
	int c;
	c = _getch() - '0';
	switch (c)
	{
	case 1:
		ManagerDP::read();
		break;
	case 2:
		ManagerAdr::read();
		break;
	case 3:
		ManagerCD::read();
		break;
	case 4:
		ManagerCP::read();
		break;

	}
}

void MosCraciun::modificaAdresa()
{
	string aux, adr;
	int index;
	cout << "Introduceti indecele adresei care doriti sa fie modificata: ";
	cin >> index;
	cout << "Introduceti noua adresa copilului (Tara Judet Localitate Strada Numar):  ";
	cin >> aux; adr = aux + " jud "; cin >> aux;adr += aux + " loc ";cin >> aux;adr += aux + " str ";cin >> aux;adr += aux + " nr ";cin >> aux; adr += aux;
	ManagerAdr::update(index, adr);
}
