#include "App.h"
#include<iostream>
#include<conio.h>
#include<Windows.h>
App& App::getInstance()
{
    static App instance; 
    return instance;
}

void App::startProgram()
{
    cout << "Introduceti numele de utilizator: ";
    string username; 
    string password;
    cin >> username;
    password = getInstance().verificareCont(username);
    if(password!="")
    {
        autentificare(username, password);
    }
    else
    {
        inregistrare(username);
        Elf::getInstance(username, password);
        ManagerLogger::write("Elful " + Elf::getInstance().getUsername() + " s-a inregistrat");
        rulareProgram(Elf::getInstance());
    }
    
}

void App::rulareProgram(MosCraciun mc)
{
    bool appOpened = true;
    while (appOpened)
    {
        try 
        {
            system("cls");
            cout << "Ce doriti sa faceti?\n1)Doresc sa adaug un copil\n2)Doresc sa adaug un cadou\n3)Doresc sa vad date\n4)Doresc sa modific o adresa\n5)Exit\n";
            int c;
            c = _getch() - '0';

            switch (c)
            {
            case 1:
                MosCraciun::getInstance().adaugaCopil();
                ManagerLogger::write("Mos Craciun a adaugat un copil");
                break;
            case 2:
                MosCraciun::getInstance().adaugaJucarie();
                ManagerLogger::write("Mos Craciun a adaugat o jucarie");
                break;
            case 3:
                MosCraciun::getInstance().show();
                ManagerLogger::write("Mos Craciun a verificat datele introduse");
                break;
            case 4:
                MosCraciun::getInstance().modificaAdresa();
                ManagerLogger::write("Mos Craciun a modificat o adresa");
                break;
            case 5:
                appOpened = false;
                ManagerLogger::write("Mos Craciun s-a deconectat");
                break;
            }
        }
        catch (MyException e)
        {
            system("cls");
            cerr << "A aparut eroarea " << e.getCode() << " \"" << e.getTitlu() << "\"";
            Sleep(3000);
        }
    }

}

void App::rulareProgram(Elf user)
{
    bool appOpened = true;
    while (appOpened)
    {
        system("cls");
        cout << "Ce doriti sa faceti?\n1)Doresc sa vad lista de jucarii dorite\n2)Doresc sa construiesc un cadou\n3)Exit\n";
        int c;
        c = _getch() - '0';

        switch (c)
        {
        case 1:
            ManagerCD::read();
            ManagerLogger::write("Elful "+user.getUsername()+" a verificat lista de jucarii dorite");
            break;
        case 2:
            Elf::getInstance().construireCadou();
            ManagerLogger::write("Elful " + user.getUsername() + " a construit un cadou");
            break;
        case 3:
            appOpened = false;
            ManagerLogger::write("Elful " + user.getUsername() + " s-a deconectat");

            break;
        }
    }
}

string App::verificareCont(string username_p)
{
    ifstream f("Conturi.txt");
    string aux;
    while (!f.eof())
    {
        f >> aux;
        if (aux == username_p)
        {
            f >> aux;
            return aux;
        }
        f >> aux;        
    }
    f.close();
    return "";
}

void App::autentificare(string username, string password)
{
    cout << "Introduceti parola pentru a va putea autentifica: ";
    string aux;
    for (int i = 0;i < 3;i++)
    {
        cin >> aux;
        if (aux == password)
        {
            i = 3;
            if (username != "MosCraciun")
            {
                Elf::getInstance(username, password);
                ManagerLogger::write("Elful " + Elf::getInstance().getUsername() + " s-a autentificat");
                rulareProgram(Elf::getInstance());
              
            }
            else
            {
                ManagerLogger::write("Mos Craciun s-a autentificat");
                rulareProgram(MosCraciun::getInstance());
                
            }
        }
        else
            if (i < 2)
            {
                system("cls");
                cout << "Parola incorecta! Mai incercati odata: ";
            }
            else
            {
                system("cls");
                cout << "Ati incercat de trei ori, sunteti scos din aplicatie.";
                ManagerLogger::write("S-a incercat o autentificare gresita");
                exit(1);
            }
    }
}

void App::inregistrare(string username)
{
    string password,aux;
    system("cls");
    cout << "Introduceti o parola: ";
    cin >> password;
    cout << "Confirmati-va parola: ";
    cin >> aux;
    if (password != aux)
    {
        inregistrare(username);
        return;
    }
    else
    {
        ofstream f("Conturi.txt", ios::app);
        f <<endl<< username << " " << password;
    }
}
