#include"ManagerAdr.h"
#include "ManagerDP.h"
#include<Windows.h>
#include<iostream>

bool ManagerDP::isNumber(string line)
{
	for (char c : line) {
		if (!isdigit(c)) {
			return false;
		}
	}
	return true;
}

void ManagerDP::create(string nume, string adr)
{
	ifstream file;
	file.open("BDDatePersonale.txt");
	if (!file.is_open())
		throw MyException("File did not open", 1);
	string aux;
	int i = 0;	
	while (!file.eof())
	{
		getline(file, aux);
		i++;
	}
	file.seekg(0, ios::beg);
	for (int j = 1;j < i;j++)
		getline(file, aux);
	file >> aux;
	while (!isNumber(aux))
		file >> aux;
	int i1 = stoi(aux);
	file >> aux;
	int i2 = stoi(aux);
	i1 =ManagerAdr::sameAdr(adr,i1);
	file.close();
	ofstream fileW;
	fileW.open("BDDatePersonale.txt", ios::app);
	if (!fileW.is_open())
		throw MyException("File did not open", 1);
	
	fileW <<endl<< nume << " " << i1<< " " << i2 + 1;
	fileW.close();
}

void ManagerDP::read()
{
	system("cls");
	ifstream file("BDDatePersonale.txt");
	if (!file.is_open())
		throw MyException("File did not open", 1);
	while (!file.eof())
	{
		string line;
		file >> line;
		cout << line << " ";
		file >> line;
		cout << line <<endl;
		getline(file, line);
		line = "";
	}
	Sleep(5000);
	file.close();
}

