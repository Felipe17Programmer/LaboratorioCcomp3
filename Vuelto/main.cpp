//Convertir numeros a letras menores a diez millones
#include <iostream>
#include <conio.h>

using namespace std;

string mainNumbers(int numero){

    string conversion = "";

    switch(numero){
        case 1: conversion = "uno "; break;
        case 2: conversion = "dos "; break;
        case 3: conversion = "tres "; break;
        case 4: conversion = "cuatro "; break;
        case 5: conversion = "cinco "; break;
        case 6: conversion = "seis "; break;
        case 7: conversion = "siete "; break;
        case 8: conversion = "ocho "; break;
        case 9: conversion = "nueve "; break;
        case 0: conversion = "cero "; break;
    }
    return conversion;
}

string specialNumbers(int numero){

    string conversion = "";

    switch(numero){
        case 11: conversion = "once "; break;
        case 12: conversion = "doce "; break;
        case 13: conversion = "trece "; break;
        case 14: conversion = "catorce "; break;
        case 15: conversion = "quince "; break;
        case 16: conversion = "dieciseis "; break;
        case 17: conversion = "diecisiete "; break;
        case 18: conversion = "dieciocho "; break;
        case 19: conversion = "diecinueve "; break;
    }
    return conversion;
}

string numbersDiez(int numero){

    string conversion = "";

    switch(numero){
        case 10: conversion = "diez "; break;
        case 20: conversion = "veinte "; break;
        case 30: conversion = "treinta "; break;
        case 40: conversion = "cuarenta "; break;
        case 50: conversion = "cincuenta "; break;
        case 60: conversion = "sesenta "; break;
        case 70: conversion = "setenta "; break;
        case 80: conversion = "ochenta "; break;
        case 90: conversion = "noventa "; break;
    }
    return conversion;
}

string numbersCien(int numero){

    string conversion = "";

    switch(numero){
        case 100: conversion = "cien "; break;
        case 200: conversion = "doscientos "; break;
        case 300: conversion = "trescientos "; break;
        case 400: conversion = "cuatroscientos "; break;
        case 500: conversion = "quinientos "; break;
        case 600: conversion = "seicientos "; break;
        case 700: conversion = "setecientos "; break;
        case 800: conversion = "ochocientos "; break;
        case 900: conversion = "novecientos "; break;
    }
    return conversion;
}

string numbersMil(int numero){

    string conversion = "";

    switch(numero){
        case 1000: conversion = "mil "; break;
        case 2000: conversion = "dos mil "; break;
        case 3000: conversion = "tres mil "; break;
        case 4000: conversion = "cuatro mil "; break;
        case 5000: conversion = "cinco mil "; break;
        case 6000: conversion = "seis mil "; break;
        case 7000: conversion = "siete mil "; break;
        case 8000: conversion = "ocho mil "; break;
        case 9000: conversion = "nueve mil "; break;
    }
    return conversion;
}

string numbersMillones(int numero){

    string conversion = "";

    switch(numero){
        case 1000000: conversion = "un millon "; break;
        case 2000000: conversion = "dos millones "; break;
        case 3000000: conversion = "tres millones "; break;
        case 4000000: conversion = "cuatro millones "; break;
        case 5000000: conversion = "cinco millones "; break;
        case 6000000: conversion = "seis millones "; break;
        case 7000000: conversion = "siete millones "; break;
        case 8000000: conversion = "ocho millones "; break;
        case 9000000: conversion = "nueve millones "; break;
    }
    return conversion;
}

string numbersLessHundred(int numero){

        int temp1 = numero % 100;
        int temp2 = numero % 10;
        string conversion = "";

        if(temp2 == 0){
            conversion = numbersDiez(numero);
        }
        else if(numero < 10){
            conversion = mainNumbers(numero);
        }
        else if(numero < 20){
            conversion = specialNumbers(numero);
        }
        else if(numero  < 30){
            conversion = "venti " + mainNumbers(temp2);
        }
        else{
            conversion = numbersDiez(temp1- temp2) + " y " + mainNumbers(temp2);
        }
        return conversion;
}

string numbersLessThousand(int numero){

        int temp1 = numero % 1000;
        int temp2 = numero % 100;
        int temp3 = numero % 10;
        string conversion = "";

        if(temp3 == 0 && temp2 == 0){
            conversion = numbersCien(numero);
        }
        else if(numero < 200){
            conversion = "ciento " + numbersLessHundred(temp2);
        }
        else{
            conversion = numbersCien(temp1 - temp2) + numbersLessHundred(temp2);
        }

    return conversion;
}

string numbersLessTenThousand(int numero){

        int temp1 = numero % 10000;
        int temp2 = numero % 1000;
        int temp3 = numero % 100;
        int temp4 = numero % 10;
        string conversion = "";

        if(temp2 == 0 && temp3 == 0 && temp4 == 0){
            conversion = numbersMil(numero);
        }
        else if(numero < 2000){
            conversion = "mil " + numbersLessThousand(temp2);
        }
        else{
            conversion = numbersMil(temp1 - temp2) + numbersLessThousand(temp2);
        }

    return conversion;

}

string numbersLessHundredThousand(int numero){

        int temp1 = numero % 100000;
        int temp2 = numero % 10000;
        int temp3 = numero % 1000;
        int temp4 = numero % 100;
        int temp5 = numero % 10;
        string conversion = "";


            if(temp2 == 0 && temp3 == 0 && temp4 == 0 && temp5 == 0){
                conversion = numbersDiez((temp1 - temp3)/1000) + " mil ";
            }
            else if(numero < 20000){
                conversion = specialNumbers((temp1 - temp3)/1000) + " mil " + numbersLessThousand(temp3);
            }
            else if(numero  < 30000){
                if((temp1 - temp3)/1000 == 21){
                    conversion = "venti y un mil " + numbersLessThousand(temp3);
                }
                else{
                    conversion = "venti " + mainNumbers((temp2 - temp3)/1000) + " mil " + numbersLessThousand(temp3);
                }
            }
            else{
                if((temp1 - temp3)/1000 == 31){conversion = numbersDiez((temp1 - temp2)/1000) + " y un mil " + numbersLessThousand(temp3);}
                else if((temp1 - temp3)/1000 == 41){conversion = numbersDiez((temp1 - temp2)/1000) + " y un mil " + numbersLessThousand(temp3);}
                else if((temp1 - temp3)/1000 == 51){conversion = numbersDiez((temp1 - temp2)/1000) + " y un mil " + numbersLessThousand(temp3); }
                else if((temp1 - temp3)/1000 == 61){conversion = numbersDiez((temp1 - temp2)/1000) + " y un mil " + numbersLessThousand(temp3); }
                else if((temp1 - temp3)/1000 == 71){conversion = numbersDiez((temp1 - temp2)/1000) + " y un mil " + numbersLessThousand(temp3);}
                else if((temp1 - temp3)/1000 == 81){conversion = numbersDiez((temp1 - temp2)/1000) + " y un mil " + numbersLessThousand(temp3); }
                else if((temp1 - temp3)/1000 == 91){conversion = numbersDiez((temp1 - temp2)/1000) + " y un mil " + numbersLessThousand(temp3);}
                else{
                    conversion = numbersDiez((temp1 - temp2)/1000) + " y " + mainNumbers((temp2 - temp3)/1000) + " mil " + numbersLessThousand(temp3);
                }

            }

    return conversion;
}

string numbersLessMillion(int numero){

        int temp1 = numero % 1000000;
        int temp2 = numero % 100000;
        int temp3 = numero % 10000;
        int temp4 = numero % 1000;
        int temp5 = numero % 100;
        int temp6 = numero % 10;
        string conversion = "";

        if(temp2 == 0 && temp3 == 0 && temp4 == 0 && temp5 == 0 && temp6 == 0){
            conversion = numbersCien((temp1 - temp2)/1000) + " mil ";
        }
        else if(numero < 200000){
            conversion = "ciento " + numbersLessHundredThousand(temp2);
        }
        else{
            conversion = numbersCien((temp1 - temp2)/1000) + numbersLessHundredThousand(temp2);
        }

        return conversion;
}

string numbersLessTenMillion(int numero){

        int temp1 = numero % 10000000;
        int temp2 = numero % 1000000;
        int temp3 = numero % 100000;
        int temp4 = numero % 10000;
        int temp5 = numero % 1000;
        int temp6 = numero % 100;
        int temp7 = numero % 10;
        string conversion = "";

        if(temp2 == 0 && temp3 == 0 && temp4 == 0 && temp5 == 0 && temp6 == 0 && temp7 == 0){
            conversion = numbersMillones(numero);
        }
        else if(numero < 2000000){
            conversion = "un millon " + numbersLessMillion(temp2);
        }
        else{
            conversion = numbersMillones(temp1 - temp2) + numbersLessMillion(temp2);
        }

        return conversion;

}

string imprimirNumber(int numero){

    string conversion = "";

    if(numero  < 100){
        conversion = numbersLessHundred(numero);
    }
    else if(numero < 1000){
        conversion = numbersLessThousand(numero);
    }
    else if(numero < 10000){
        conversion = numbersLessTenThousand(numero);
    }
    else if(numero < 100000){
        conversion = numbersLessHundredThousand(numero);
    }
    else if(numero < 1000000){
        conversion = numbersLessMillion(numero);
    }
    else if(numero < 10000000){
        conversion = numbersLessTenMillion(numero);
    }
    return conversion;
}

int main()
{
    int numero = 0;
    cout<<"Digite un numero: "; cin>>numero;
    cout<<"Tu numero es: ";
    cout<<imprimirNumber(numero);

    getch();
    return 0;
}
