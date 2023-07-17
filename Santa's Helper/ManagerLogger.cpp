#include "ManagerLogger.h"
#include<fstream>
#include "MyException.h"

void ManagerLogger::write(string s)
{
	ofstream file("Logger.log",ios::app);
	if (!file.is_open())
		throw MyException("Logger did not open properly", 3);
	file << s << "\n";
	file.close();
}
