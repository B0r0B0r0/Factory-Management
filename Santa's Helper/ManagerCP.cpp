#include "ManagerCP.h"
#include<iostream>
#include<Windows.h>
#include<vector>

void ManagerCP::create(int index,string s)
{
	ifstream file("BDCadouriPrimite.txt");
	if(!file.is_open())
		throw MyException("File did not open", 1);
	vector<string> sfile;
	
	while (!file.eof())
	{
		string aux;
		getline(file, aux);
		if(aux!="")
			sfile.push_back(aux);
	}
	int aux = sfile.size();
	if (index - 1 > sfile.size())
	{
		for (int i = 0;i < index - aux;i++)
			sfile.push_back("#");
	}
	file.close();

	
	
	if (sfile[index - 1] != "#")
		sfile[index - 1] += " " + s;
	else
		sfile[index - 1] = s;


	ofstream ofile("BDCadouriPrimite.txt");
	for (int i = 0;i < sfile.size() - 1;i++)
		ofile << sfile[i] << endl;
	ofile << sfile[sfile.size() - 1];
	ofile.close();
}

void ManagerCP::read()
{
	system("cls");
	ifstream file("BDCadouriPrimite.txt");
	if (!file.is_open())
		throw MyException("File did not open", 1);
	while (!file.eof())
	{
		string line;
		getline(file, line);
		if (line == "")
			break;
		line.erase(line.size() - 1);
		cout << line << endl;
		line = "";
	}
	Sleep(5000);
	file.close();
}
