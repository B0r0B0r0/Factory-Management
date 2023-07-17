#pragma once
#include "MosCraciun.h"
#include "Elf.h"
#include "ManagerLogger.h"
#include <fstream>
class App
{
	App() {}
	void rulareProgram(MosCraciun mc);
	void rulareProgram(Elf user);
	string verificareCont(string username_p);
	void autentificare(string username, string password);
	void inregistrare(string username);
public:
	static App& getInstance();
	void startProgram();
	
};

