#pragma once
#include "Cont.h"
#include "ManagerAdr.h"
#include "ManagerCD.h"
#include "ManagerCP.h"
#include "ManagerDP.h"
#include "MyException.h"

class MosCraciun :
    public Cont
{
    MosCraciun(string usernume_p, string password_p) : Cont(usernume_p,password_p) {}
    bool verifyData(string data);
    bool verifyFlag(string flag);
public:
    static MosCraciun& getInstance() { static MosCraciun instance("MosCraciun","Parola"); return instance; }
    void adaugaCopil();
    void adaugaJucarie();
    void show();
    void modificaAdresa();
};

