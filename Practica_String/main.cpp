#include <iostream>
#include <string.h>

using namespace std;

string reverseString(string cadena){
    string temp = "";
    for(int i = cadena.size()-1  ; i>=0 ; i--){
        temp.push_back(cadena[i]);
    }
    return temp;
}

int buscarCadenas(string cadena, string cadenaBuscada){
    int cont = 0;
    int temp;
    string cadTemp;
    int i=0;
    while(i<cadena.size()-1){
        temp = cadena.find_first_of(cadenaBuscada,cadenaBuscada.size());
        cont++;
        i += cadenaBuscada.size();
        cadTemp = cadena.substr(temp,cadena.size()-1);
    }
    return cont;
}

void imprimirLinea(int veces, string figura, int espacio){
        string temp = " ";
        string temp2 = "";
        for(int j=0; j<espacio; j++){
            temp += temp;
        }
        for(int j=0; j<veces; j++){
            temp2 += figura;
        }
        temp += temp2;
        cout<<temp<<endl;
}

void imprimirRombo(int numero){
    string figura = "*";
    int i=1;
    int j = 1;
    int t = numero-2;
    int mitad = numero/2;
    int j1 = mitad;
    int t1 = 1;

    while(i <= numero){
        if(i<mitad+1){
            if(i == 1){
               imprimirLinea(j,"*",2);
               j+=2;
               j1--;
            }else{
                imprimirLinea(j,figura,j1);
                j+=2;
                j1--;
            }

        }
        else if(i == mitad+1){
            imprimirLinea(numero,figura,0);
        }
        else if(i>mitad+1){
            imprimirLinea(t,figura,t1);
            t-=2;
            t1++;
        }
        i++;
    }
}

int main()
{
    cout<<"\tPRACTICA DE STRINGS"<<endl;
    cout<<endl;

    cout<<"-> 1.CADENAS AL REVES"<<endl;
    string cadenaReverse, cadena;
    cout<<"Ingrese una cadena de texto: ";
    getline(cin,cadena);
    cadenaReverse = reverseString(cadena);
    cout<<cadenaReverse<<endl;
    cout<<endl;

    cout<<"-> 2.CADENAS EN CADENAS"<<endl;
    string cadena1, cadenaBuscada;
    int cantidadApariciones;
    cout<<"Ingrese una cadena de texto: ";
    cin>>cadena1;
    cout<<"Ingrese la cadena a buscar: ";
    cin>>cadenaBuscada;
    cantidadApariciones = buscarCadenas(cadena1,cadenaBuscada);
    cout<<cantidadApariciones<<endl;
    cout<<endl;

    cout<<"-> 3.IMPRIMIENDO ROMBOS"<<endl;
    int cantidad = 0;
    cout<<"Ingrese un valor impar: ";
    cin>>cantidad;
    imprimirRombo(cantidad);
    cout<<endl;

    cout<<"-> 4.PALABRAS SEPARADAS POR PALABRAS"<<endl;
    string separador = "";
    cadena = "";
    cin.ignore(255,'\n');
    cout<<"Ingrese una cadena de texto: ";
    getline(cin,cadena);
    cout<<"Ingrese un separador de texto: ";
    getline(cin,separador);
    cout<<endl;

    cout<<"-> 5.PALABRAS PALINDROMES"<<endl;
    cadenaReverse = "";
    cadena = "";
    cout<<"Ingrese una cadena de texto: ";
    getline(cin,cadena);
    cadenaReverse = reverseString(cadena);
    if(cadena.compare(cadenaReverse) == 0 ){cout<<"SI"<<endl;}
    else{cout<<"NO"<<endl;}
    cout<<endl;

    cout<<"-> 6.ORDENANDO CADENAS"<<endl;
    cadena = "";
    cout<<"Ingrese una cadena de texto: ";
    getline(cin,cadena);
    cout<<endl;

    return 0;
}
