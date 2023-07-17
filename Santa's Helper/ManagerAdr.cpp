#include "ManagerAdr.h"
#include<iostream>
#include<Windows.h>
#include <vector>
void ManagerAdr::create(string adr)
{
    ofstream file("BDAdrese.txt", ios::app);
    if (!file.is_open())
        throw MyException("File did not open", 1);
    file <<endl<< adr;
    file.close();
}

void ManagerAdr::update(int index,string adr)
{
    ifstream file("BDAdrese.txt");
    if (!file.is_open())
        throw MyException("File did not open", 1);
    vector<string> sfile;
    while (!file.eof())
    {
        string aux;
        getline(file, aux);
        sfile.push_back(aux);
    }
    file.close();
    sfile[index - 1] = adr;
    ofstream ofile("BDAdrese.txt");
    if (!ofile.is_open())
        throw MyException("File did not open", 1);
    for (int i = 0;i < sfile.size() - 1;i++)
        ofile << sfile[i] << endl;
    ofile << sfile[sfile.size()-1];
    ofile.close();
}

void ManagerAdr::read()
{
    system("cls");
    ifstream file("BDAdrese.txt");
    if (!file.is_open())
        throw MyException("File did not open", 1);
    while (!file.eof())
    {
        string line;
        getline(file, line);       
        cout << line << endl;
        line = "";
    }
    Sleep(5000);
    file.close();
}

int ManagerAdr::sameAdr(string adr,int i1)
{
    ifstream file("BDAdrese.txt");
    if (!file.is_open())
        throw MyException("File did not open", 1);
    int i = 1;
    while (!file.eof())
    {
        string aux;
        getline(file, aux);
        if (aux == adr)
            return i;
        i++;
    }
    ManagerAdr::create(adr);
    return i1 + 1;
}
