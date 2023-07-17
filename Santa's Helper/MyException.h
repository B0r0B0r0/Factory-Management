#pragma once
#include<string>
using namespace std;
class MyException
{
	string titlu;
	int code;
public:
	MyException(string titlu_p,int code_p) : titlu(titlu_p), code(code_p) {}
	string getTitlu() { return titlu; }
	int getCode() { return code; }
}; 

