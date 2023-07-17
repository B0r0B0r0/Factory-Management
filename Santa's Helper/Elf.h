#pragma once
#include "Cont.h"
class Elf :
    public Cont
{
    static Elf* instance;
    Elf(string username_p, string password_p) : Cont(username_p,password_p) {}
public:
    static Elf& getInstance(string username_p, string password_p);
    static Elf& getInstance();
    static void destroyInstance();
    void construireCadou();
    
};

