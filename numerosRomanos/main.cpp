//Convertir numeros menores de mil en romanos
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

string principalNumerosRomanos(int numero){

	string conversion = "";

	switch(numero){
		case 1: conversion = "I"; break;
		case 2: conversion = "II"; break;
		case 3: conversion = "III";	break;
		case 4: conversion = "IV"; break;
		case 5: conversion = "V"; break;
		case 6: conversion = "VI"; break;
		case 7: conversion = "VII"; break;
		case 8: conversion = "VIII"; break;
		case 9: conversion = "IX"; break;
	}
	return conversion;
}

string numRomanoDiez(int numero){

    string conversion = "";
    int temp = (numero/10)*10;
    int temp1 = (numero/100)*100;
    int temp2 = temp - temp1;

    switch(temp2){
 		case 10: conversion = "X"; break;
		case 20: conversion = "XX"; break;
		case 30: conversion = "XXX";	break;
		case 40: conversion = "XL"; break;
		case 50: conversion = "L"; break;
		case 60: conversion = "LX"; break;
		case 70: conversion = "LXX"; break;
		case 80: conversion = "LXXX"; break;
		case 90: conversion = "XC"; break;
    }
    return conversion;
}

string numRomanoCien(int numero){

    string conversion = "";
    int temp = (numero/100)*100;

    switch(temp){
 		case 100: conversion = "C"; break;
		case 200: conversion = "CC"; break;
		case 300: conversion = "CCC";	break;
		case 400: conversion = "CD"; break;
		case 500: conversion = "D"; break;
		case 600: conversion = "DC"; break;
		case 700: conversion = "DCC"; break;
		case 800: conversion = "DCCC"; break;
		case 900: conversion = "CM"; break;
    }
    return conversion;

}

string numRomano(int numero){

	string conversion = "";
    conversion = numRomanoCien(numero)+ numRomanoDiez(numero)+ principalNumerosRomanos(numero%10);
    return conversion;
}

int main(){

	int num = 0;
	cout<<"Ingrese un numero: "; cin>>num;
	cout<<"Su numero en romanos es: "<<numRomano(num);

	getch();

	return 0;
}
