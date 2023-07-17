#pragma once
#include<string>
#include<fstream>
#include"MyException.h"
namespace ManagerAdr
{
    void create(string adr);
    void update(int index,string adr);
    void read();
    int sameAdr(string adr,int i1);
};

