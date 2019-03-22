#ifndef CESAR_H
#define CESAR_H

#include <iostream>

using namespace std;

class Cesar
{
    public:
        Cesar(int _clave, string _alfabeto = "abcdefghijklmnopqrstuvwxyz");
        string cifrado(string M);
        string descifrado(string MC);

    private:
        string alfabeto = "";
        int clave=0;
};

#endif // CESAR_H
