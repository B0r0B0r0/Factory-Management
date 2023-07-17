#include "Elf.h"
#include"ManagerCD.h"
#include"ManagerCP.h"
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include"CBuilder.h"

using namespace std;

Elf* Elf::instance = nullptr;

Elf& Elf::getInstance(string username_p,string password_p)
{
	if (instance == nullptr)
		instance = new Elf(username_p,password_p);

	return *instance;
}

Elf& Elf::getInstance()
{
	if (instance != nullptr)
		return *instance;
}

void Elf::destroyInstance()
{
	if (instance != nullptr)
	{
		delete Elf::instance;
		instance = nullptr;
	}
}

void Elf::construireCadou()
{
	
	ManagerCD::read();
	cout << "Ce cadouri doriti construite?\n";
	int index; cin >> index;
	vector<string> sfile;

	ifstream file("BDCadouriDorite.txt");
	if (!file.is_open())
		throw MyException("File did not open", 1);
	while (!file.eof())
	{
		string aux;
		getline(file, aux);
		sfile.push_back(aux);
	}
	file.close();
	int contor=0;
	for (auto it : sfile)
	{
		contor++;
		if (it == "#")
			index++;
		if (contor == index)
			break;
	}
	istringstream buffer(sfile[index-1]);
	string token;
	CBuilder builder;
	string cadouComplet;
	
	while (true)
	{
		getline(buffer, token, ' ');
		if (token == "#")
			break;
		if (token == "Bicicleta")
		{
			builder.construiesteBicicleta();
			cadouComplet = " Bicicleta " + builder.getCadou()->getComponents();
			ManagerCP::create(index, cadouComplet);
		}
		if (token == "Castel")
		{
			builder.construiesteCastel();
			cadouComplet = " Castel " + builder.getCadou()->getComponents();
			ManagerCP::create(index, cadouComplet);
		}
		if (token == "Masina")
		{
			builder.construiesteMasina();
			cadouComplet = " Masina " + builder.getCadou()->getComponents();
			ManagerCP::create(index, cadouComplet);
		}


	}
	sfile[index-1] = "#";
	ofstream ofile("BDCadouriDorite.txt");
	if (!ofile.is_open())
		throw MyException("File did not open", 1);
	for (int i=0;i<sfile.size()-1;i++)
		ofile << sfile[i] << endl;
	ofile << sfile[sfile.size()-1];
	ofile.close();
}
