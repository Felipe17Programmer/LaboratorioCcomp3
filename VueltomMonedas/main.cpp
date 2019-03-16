#include <iostream>

using namespace std;

int main()
{
    float dinero = 0;
    int dineroSoles = 0;
    int dineroCentimos = 0;
    int temp1 = 0;
    int temp2 = 0;

    int valor05 = 0.5*100;
    int valor02 = 0.2*100;
    int valor01 = 0.1*100;
    int valor005 = 0.05*100;
    int valor001 = 0.01*100;

    int cont200 = 0, cont100 = 0, cont50 = 0, cont20 = 0, cont10 = 0, cont5 = 0, cont2 = 0, cont1 = 0, cont05 = 0, cont02 = 0, cont01 = 0, cont005 = 0, cont001 = 0;

    cout << "Digita el valor a dar vuelto: "; cin>>dinero;

    temp1 = dinero * 100;
    temp2 = temp1 % 100;

    dineroSoles = (temp1 - temp2)/100;
    dineroCentimos = temp2;

    cont200 = dineroSoles/200;
    dineroSoles %= 200;
    cont100 = dineroSoles/100;
    dineroSoles %= 100;
    cont50 = dineroSoles/50;
    dineroSoles %= 50;
    cont20 = dineroSoles/20;
    dineroSoles %= 20;
    cont10 = dineroSoles/10;
    dineroSoles %= 10;
    cont5 = dineroSoles/5;
    dineroSoles %= 5;
    cont2 = dineroSoles/2;
    dineroSoles %= 2;
    cont1 = dineroSoles/1;
    dineroSoles %= 1;

    cont05 = dineroCentimos/valor05;
    dineroCentimos %= valor05;
    cont02 = dineroCentimos/valor02;
    dineroCentimos %= valor02;
    cont01 = dineroCentimos/valor01;
    dineroCentimos %= valor01;
    cont005 = dineroCentimos/valor005;
    dineroCentimos %= valor005;
    cont001 = dineroCentimos/valor001;

    cout<<endl;
    cout<<" -> "<<cont200<<" de S/."<<200<<endl;
    cout<<" -> "<<cont100<<" de S/."<<100<<endl;
    cout<<" -> "<<cont50<<" de S/."<<50<<endl;
    cout<<" -> "<<cont20<<" de S/."<<20<<endl;
    cout<<" -> "<<cont10<<" de S/."<<10<<endl;
    cout<<" -> "<<cont5<<" de S/."<<5<<endl;
    cout<<" -> "<<cont2<<" de S/."<<2<<endl;
    cout<<" -> "<<cont1<<" de S/."<<1<<endl;
    cout<<" -> "<<cont05<<" de S/."<<0.5<<endl;
    cout<<" -> "<<cont02<<" de S/."<<0.2<<endl;
    cout<<" -> "<<cont01<<" de S/."<<0.1<<endl;
    cout<<" -> "<<cont005<<" de S/."<<0.05<<endl;
    cout<<" -> "<<cont001<<" de S/."<<0.01<<endl;

    return 0;
}
