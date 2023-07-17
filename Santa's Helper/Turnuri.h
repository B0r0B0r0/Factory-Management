#pragma once
#include<iostream>
#include "Componenta.h"
#include<string>
class Turnuri :
    public Componenta
{
    int numarTurnuri;
public:
    Turnuri(string c, int n) : Componenta(c), numarTurnuri(n) {}
    ~Turnuri() { numarTurnuri = 0; }
    string getComponent() override;
};

