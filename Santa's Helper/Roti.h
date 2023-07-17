#pragma once
#include "Componenta.h"
#include<iostream>
#include<string>
class Roti :
    public Componenta
{
    int diametru;
public:
    Roti(string c, int d) : Componenta(c),diametru(d) {}
    ~Roti() { diametru = 0; }
    string getComponent() override { return to_string(diametru)+"cm"; }
};

