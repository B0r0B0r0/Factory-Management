#pragma once
#include "Componenta.h"
#include<iostream>
#include<string>
class Motor :
    public Componenta
{
    int caiPutere;
public:
    Motor(string c,int cP) : Componenta(c), caiPutere(cP) {}
    ~Motor() { caiPutere = 0; }
    string getComponent() { return to_string(caiPutere)+"cp"; }
}; 

