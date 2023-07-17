#pragma once
#include<string>
using namespace std;
class Cont
{
	string username;
	string password;
public:
	Cont(string username_p,string password_p) : username(username_p),password(password_p){}
	string getUsername() { return username; }
};

