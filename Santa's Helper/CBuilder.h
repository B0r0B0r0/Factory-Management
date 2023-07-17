#pragma once
#include "IBuilder.h"
#include"Cadou.h"
class CBuilder :
    public IBuilder
{
    Cadou* cadouComplet;
    void reset() { cadouComplet = new Cadou; }
public:
    CBuilder() { reset(); }
    ~CBuilder() { delete cadouComplet; }
    void construiesteMasina() override;
    void construiesteBicicleta() override;
    void construiesteCastel() override;
    Cadou* getCadou();
};

