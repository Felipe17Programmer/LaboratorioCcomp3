#include <iostream>
#include "Cesar.h"


using namespace std;

int main(){

    string texto = "";
    string cifradoT = "";
    string descrifradoT = "";

    Cesar emisor(3);
    cout<<"Ingrese un texto: "; getline(cin,texto);

    cifradoT = emisor.cifrado(texto);
    cout<<cifradoT<<endl;

    Cesar receptor(3);
    descrifradoT = receptor.descifrado(cifradoT);
    cout<<descrifradoT;

    return 0;
}
