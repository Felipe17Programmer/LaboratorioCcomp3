#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

//Congruencia de Zeller
//Devuelve
//0 = Domingo , 1 = Lunes , 2 = Kartes, 3 = Miercoles,
//4 = Jueves , 5 = Viernes, 6 = Sabado

int zeller(int anio , int mes){
    int a = (14 - mes)  /12;
    int y = anio - a;
    int m = mes + 12 * a - 2 ;
    int dia = 1, d;
    d = (dia + y + y / 4 - y / 100 + y / 400 + (31 * m)/12) %7;

    return d;
}

string cambiarMes(int numero){
    string conversion = "";
    int temp = numero/1;
    switch(temp){
        case 1: conversion = "ENERO";break;
        case 2: conversion = "FEBRERO";break;
        case 3: conversion = "MARZO";break;
        case 4: conversion = "ABRIL";break;
        case 5: conversion = "MAYO";break;
        case 6: conversion = "JUNIO";break;
        case 7: conversion = "JULIO";break;
        case 8: conversion = "AGOSTO";break;
        case 9: conversion = "SEPTIEMBRE";break;
        case 10: conversion = "OCTUBRE";break;
        case 11: conversion = "NOVIEMBRE";break;
        case 12: conversion = "DICIEMBRE";break;
    }
    return conversion;
}

bool esBisiesto(int anio){
    if(anio % 4 != 0){return false;}
    if(anio % 100 != 0){return true;}
    if(anio % 400 != 0){return false;}
    return true;
}

int numeroDiasMes(int mes,int anio){
    int temp = mes/1;
    int res=0;
    int enero=31,febrero=0,marzo=31,abril=30,mayo=31,junio=30,julio=31,agosto=31,septiembre=30,octubre=31,noviembre=30,diciembre=31;
    if(esBisiesto(anio)){
        febrero=29;
    }
    else{
        febrero=28;
    }
    switch(temp){
        case 1: res= enero;break;
        case 2: res= febrero;break;
        case 3: res= marzo;break;
        case 4: res= abril;break;
        case 5: res= mayo;break;
        case 6: res= junio;break;
        case 7: res= julio;break;
        case 8: res= agosto;break;
        case 9: res= septiembre;break;
        case 10: res= octubre;break;
        case 11: res= noviembre;break;
        case 12: res= diciembre;break;
    }
    return res;
}

void printCalendario(int mes,int anio){

    int z = zeller(anio , mes);
    string nombreMes = "";
    nombreMes = cambiarMes(mes);

    cout<<"     "<<nombreMes<<" - "<<anio<<endl;
    cout<<"______________________"<<endl;
    cout<<"|D |L |M |M |J |V |S |"<<endl;
    cout<<"----------------------"<<endl;

    for(int i = 0; i<z; i++){
        cout<<"   ";
    }
    int diaMes = numeroDiasMes(mes,anio);

    for(int dia = 1; dia <= diaMes; dia++){
            printf("%3d",dia);
            z++;
            if(z % 7 == 0){cout <<"\n";}
    }
    cout<<"\n\n";
}

int main()
{

    int mes = 0;
    int anio = 0;

    cout << "Digite el mes: "; cin>>mes;
    cout << "Digite el anio: "; cin>>anio;

    cout<<endl;

    printCalendario(mes,anio);
    system("pause");

    return 0;
}
