#include "ManagerCD.h"
#include<vector>
#include<iostream>
#include<Windows.h>

void ManagerCD::create(string nume, int index)
{
	vector<string> linii;
	ifstream infile("BDCadouriDorite.txt");
	if (!infile.is_open())
		throw MyException("File did not open", 1);
	int i = 0;
	while (!infile.eof())
	{
		string linie;
		getline(infile, linie);
		linii.push_back(linie);
		linie = "";
		i++;
	}

	if (i >= index + 1)
	{
		linii.push_back(nume+" #");
	}
	else
	{
		linii[index].erase(linii[index].size() - 1);
		linii[index] += " " + nume+" #";
	}

	infile.close();
	ofstream outfile("BDCadouriDorite.txt");
	if (!outfile.is_open())
		throw MyException("File did not open", 1);
	for (int j = 0;j < linii.size() - 1;j++)
		outfile << linii[j] << "\n";
	outfile << linii[linii.size() - 1];
	outfile.close();
	linii.clear();
}

void ManagerCD::read()
{
	system("cls");
	ifstream file("BDCadouriDorite.txt");
	while (!file.eof())
	{
		string line;
		getline(file, line);
		if (line == "")
			break;
		if (line != "#")
		{
			line.erase(line.size() - 1);
			cout << line << endl;
		}
		line = "";
	}
	Sleep(5000);
	file.close();
}
