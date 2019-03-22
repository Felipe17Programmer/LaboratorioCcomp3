#include "Cesar.h"

#include <iostream>

using namespace std;

Cesar::Cesar(int _clave, string _alfabeto ){

    clave = _clave;
    alfabeto = _alfabeto;
}

string Cesar::cifrado(string M){

    string cifrado = "";
    string espacio = " ";

    for(int i=0; i < M.size(); i++){
        if(M[i] == espacio[0]){
            cifrado += " ";
        }
        for(int j=0; j< alfabeto.size();j++){
            if(M[i] == alfabeto[j]){
                int pos = j + clave;
                if(pos > alfabeto.size()-1){
                    int newPos = pos %(alfabeto.size());
                    cifrado.push_back(alfabeto[newPos]);
                }
                else{
                    cifrado.push_back(alfabeto[pos]);
                }
            }
        }
    }
    return cifrado;
}

string Cesar::descifrado(string MC){

    string descifrado = "";
    string espacio = " ";

    for(int i=0; i < MC.size(); i++){
        if(MC[i] == espacio[0]){
            descifrado += " ";
        }
        for(int j=0; j< alfabeto.size();j++){
            if(MC[i] == alfabeto[j]){
                int pos = j - clave;
                if(pos < 0){
                    int newPos = alfabeto.size() - (clave - j);
                    descifrado.push_back(alfabeto[newPos]);
                }
                else{
                    descifrado.push_back(alfabeto[pos]);
                }
            }
        }
    }
    return descifrado;

}


