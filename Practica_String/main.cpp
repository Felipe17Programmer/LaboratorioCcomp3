#include <iostream>
#include <iomanip>
#include <string.h>
#include <math.h>

using namespace std;

string reverseString(string cadena){
    string temp = "";
    for(int i = cadena.size()-1  ; i>=0 ; i--){
        temp.push_back(cadena[i]);
    }
    return temp;
}

int buscarCadenas(string cadena, string cadenaBuscada){

    int cont=0;
    string temp = "";
    while(true){
        int pos = cadena.find(cadenaBuscada);
        if(pos == string::npos){
            break;
        }
        else{
            temp = cadena.substr(pos,cadenaBuscada.size());
            if(cadenaBuscada.compare(temp) == 0){
                cont++;
            }
            cadena.replace(pos,1,"x");
        }
    }
    return cont;
}

void espaciar(int veces){
    string temp = "";
    for(int i = 0; i< veces;i++){
        temp += " ";
    }
    cout<<temp;
}


void imprimirRombo(int numero){
    string figura = "*";
    int valorEspacio = numero/2;
    int valorEspacioBM = 0;
    int cont = 1;
    int i=0;

    while(i < numero ){
        if(i <= numero/2){
            int valorI = (2*i)+1;
            string temp2 = "";
            for(int j=1; j<=valorI; j++){
                temp2 += figura;
            }
            if(valorEspacio == 0){  cout<<temp2<<endl; valorEspacio++;}
            else{espaciar(valorEspacio--); cout<<temp2<<endl;}
        }
        else{
            int valorI = ((2*i)+1)- (4*cont++);
            string temp2 = "";
            for(int j=valorI; j>=1; j--){
                temp2 += figura;
            }
            espaciar(valorEspacio++);
            cout<<temp2<<endl;
        }
        i++;
    }
}

void separandoStrings(string cadena, string separador){
    string temp = "";
    string contenedor = "";
    while(true){
        int pos = cadena.find(separador);
        if(pos == string::npos){
            break;
        }
        else{
            cadena.replace(pos,separador.size(),"\n");
        }
    }
    cout<<cadena<<endl;
}

void ordenarStrings(string cadena,int n){
    int i=0;
    while(i<n){
        string palabra;
        string temp = " ";
        cout<<"Ingrese palabra: "; cin>>palabra;
        temp+=palabra;
        cadena.append(temp);
        i++;
    }

    string cadenaS[3+n];
    for(int i=0;i<3;i++){
        int pos = cadena.find(" ");
        if(pos == string::npos){
            cadenaS[i]= cadena.substr(0,pos);
            break;
        }
        else{

            cadenaS[i]= cadena.substr(0,pos);
            cadena.replace(0,pos+1,"");
            cout<<cadena<<endl;
        }
    }

    for(int i=0;i<3+n;i++){
        cout<<cadenaS[i]<<" ";
    }
    cout<<endl;
   /* for(int i=0;i<n;i++){
        cout<<arrayS[i]<<" ";
    }*/

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
    if(cantidad % 2 == 0){
        cout<<"No es un numero impar!!!"<<endl;
    }else{imprimirRombo(cantidad);}
    cout<<endl;

    cout<<"-> 4.PALABRAS SEPARADAS POR PALABRAS"<<endl;
    string separador = "";
    cadena = "";
    cin.ignore(255,'\n');
    cout<<"Ingrese una cadena de texto: ";
    getline(cin,cadena);
    cout<<"Ingrese un separador de texto: ";
    getline(cin,separador);
    separandoStrings(cadena,separador);
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
    int n=0;
    cout<<"Ingrese una cadena de texto ordenada: ";
    getline(cin,cadena);
    cout<<"Ingrese la cantidad de palabras a agregar: "; cin>>n;
    ordenarStrings(cadena,n);
    cout<<endl;

    return 0;
}
