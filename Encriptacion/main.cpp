#include <iostream>
#include <fstream>
#include <cstdio>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

int sucesionP(int modulo, int arrayCocientes[],int tamanio){
	int p[20];
	p[0] = 0;
	p[1] = 1;

	int inverso = 0;
	int  i= 2;

	while(i != tamanio+1){
		int result=0;

		p[i] = p[i-2] - (p[i-1]*arrayCocientes[i-2]);
		if(p[i]<0){
			result = p[i];
			p[i]=modulo + result;
		}
		else{
			p[i] = p[i]%modulo;
		}
		i++;
	}
	inverso = p[tamanio];
	return inverso;

}


int inversoM(int valor, int modulo){
	if(valor == 0 || modulo == 0){
		cout<<"No hay inverso multiplicativo"<<endl;
	}
		else{
		int numero = 0, cociente = 0, residuo = 0, cont = 1;

		int cocientesArray[20];
		int residuosArray[20];

		numero = modulo;
		cociente = numero/valor;

		residuo = numero - (cociente * valor);

		int i = 0;
		cocientesArray[i] = cociente;
		residuosArray[i] = residuo;
		while(residuo != 0){
					i++;
					numero = valor;
					valor = residuo;
					cociente = numero/valor;
					residuo = numero - (cociente * valor);
					cocientesArray[i] = cociente;
					residuosArray[i] = residuo;
					cont++;
		}

		if(valor == 1){
				int res = 0;
				res = sucesionP(modulo,cocientesArray,cont);
				return res;
		}
		else{
			return 0;
		}
	}
}

int multiplicacionModular(int primerValor, int segundoValor,int modulo){

    int resultado = 0;

    int temp = 0;
    temp = primerValor * segundoValor;

    if(temp <= 0){
        while((temp*-1)>6){
            temp = temp % modulo;
        }
        resultado = modulo + temp;
        return resultado;
    }
    else{
        resultado = temp % modulo;
        return resultado;
    }

}

void encriptarDoc(){
	fstream archivo;
	fstream archivo2;

	archivo.open("Documento.txt",ios::in);
	archivo2.open("Encriptado.txt",ios::out);

	if(archivo.is_open() && archivo.is_open() ){
		char c;
		while(!archivo.eof() && !archivo2.eof() ){
			c = archivo.get();
			archivo2<<char(int(c)+10);
		}
    archivo2.close();
    archivo.close();

	}else{
		cout<<"No se encontro el archivo... ";
	}
}

void desencriptarDoc(){
	fstream archivo;
	fstream archivo2;

	archivo.open("Encriptado.txt",ios::in);
	archivo2.open("Desencriptado.txt",ios::out);

	if(archivo.is_open() && archivo.is_open() ){
		char c;
		while(!archivo.eof() && !archivo2.eof() ){
			c = archivo.get();
			archivo2<<char(int(c)-10);
		}
    archivo2.close();
    archivo.close();

	}else{
		cout<<"No se encontro el archivo... ";
	}
}

int main(){

    int opcion = 0;
    int numberRandom=0;
    int llavePrivada=0, llavePublica=0;

    int modulo = 65;
    cout << "\tCRIPTOGRAFIA" << endl;
    cout<< endl;
    cout << "1. Encriptar" << endl;
    cout << "2. Desencriptar" << endl;
    cout << "3. Salir" << endl;
    cout<<endl;
    cout<<"Ingrese su opcion: "; cin>>opcion;

    if(opcion == 1){
        cout<<endl;
        do{
            cout<<"Digite valor para llave privada: "; cin>>llavePrivada;
            llavePublica = inversoM(llavePrivada,modulo);
        }while(llavePublica == 0);
        cout<<"Tu llave publica es: "<<llavePublica<<endl;
        encriptarDoc();
    }
    else if(opcion == 2){
        int llavePrivadaV = 0;
        int llavePublicaI=0;
        int temporal = 0;
        while(true){
            cout<<"Ingrese su llave publica: "; cin>>llavePublicaI;
            llavePrivadaV = multiplicacionModular(llavePublicaI, inversoM(llavePublicaI,modulo) , modulo );
            if(llavePrivadaV == 1){
                break;
            }
        }
        desencriptarDoc();
    }
    else{
        system("pause");
    }
    return 0;
}
