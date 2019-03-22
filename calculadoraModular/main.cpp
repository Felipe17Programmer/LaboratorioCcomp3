#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

int getModulo(int numero,int modulo){
    return numero%modulo;
}

void sumaModular(int primerValor, int segundoValor,int modulo){

    int resultado = 0;

    resultado = getModulo(primerValor,modulo) + getModulo(segundoValor,modulo);
    cout<<"Resultado: "<<resultado<<endl;
    getch();
}

void restaModular(int primerValor, int segundoValor,int modulo){

    int resultado = 0;

    int temp2 = 0;
    temp2 = primerValor - segundoValor;

    if(temp2 <= 0){
        resultado = modulo + temp2;
        cout<<"Resultado: "<<resultado<<endl;
    }
    else{
        resultado = temp2;
        cout<<"Resultado: "<<resultado<<endl;
    }
    system("pause");
}

void multiplicacionModular(int primerValor, int segundoValor,int modulo){

    int resultado = 0;

    int temp = 0;
    temp = primerValor * segundoValor;

    if(temp <= 0){
        while((temp*-1)>6){
            temp = temp % modulo;
        }
        resultado = modulo + temp;
        cout<<"Resultado: "<<resultado<<endl;
    }
    else{
        resultado = temp % modulo;
        cout<<"Resultado: "<<resultado<<endl;
    }
    getch();
}

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


void inversoM(int valor, int modulo){
	if(valor == 0 || modulo == 0){
		cout<<"No hay inverso multiplicativo";
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
				cout<<"Inverso Multiplicativo: "<<res;
		}
		else{
			cout<<"No hay inverso multiplicativo";
		}
	}
}

int menuPrincipal(){

    bool repite = true;
    int opcion = 0;

    cout<<"\tCALCULADORA MODULAR\n"<<endl;
    cout<<"1. Sumar"<<endl;
    cout<<"2. Restar"<<endl;
    cout<<"3. Multiplicar"<<endl;
    cout<<"4. Inverso Multiplicativo"<<endl;
    cout<<"5. Salir"<<endl;
    cout<<endl;
    cout<<"Ingrese el numero de su opcion: "; cin>>opcion;

    return opcion;
}

int main()
{
    int temp = 0;

    temp = menuPrincipal();

    if(temp == 1 || temp == 2 || temp == 3){
        int modulo = 0, primerValor = 0,segundoValor = 0;
        system("cls");
        cout<<"Ingresa valor del modulo: "; cin>>modulo;
        cout<<"Ingresa primer valor: "; cin>>primerValor;
        cout<<"Ingresa segundo valor: "; cin>>segundoValor;
        cout<<endl;

        if(temp == 1){
            sumaModular(primerValor,segundoValor,modulo);
        }
        else if(temp == 2){
            restaModular(primerValor,segundoValor,modulo);
        }
        else if(temp == 3){
            multiplicacionModular(primerValor,segundoValor,modulo);
        }
    }
    else if(temp == 4){
        int modulo = 0, numero = 0;
        system("cls");
        cout<<"Ingrese valor: "; cin>>numero;
        cout<<"Ingrese modulo: "; cin>>modulo;
        cout<<endl;
        inversoM(numero,modulo);
    }
    else{
        system("pause");
    }
    return 0;
}
