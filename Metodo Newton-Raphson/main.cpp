#include <iostream>
#include <math.h>

using namespace std;

double funcao(double x){
    return (4*cos(x)- pow(M_E,2*x));
    //return (x - cos(x));
    //return (log(x)- pow(M_E,-3*x));
}

double funcaoD(double x){
    return (-sin(x)-2*exp(2*x));
    //return (1 + sin(x));
    //return ((1/x)+3*pow(M_E,-3*x));
}

double funcaoX1(double x){
    return (x - (funcao(x)/funcaoD(x)));
}

int main()
{
    double x,fxD,fx1,fxanti = 0,fxnovo = 0,erro = 100;
    int i=0;


    cout<< "Digite o valor de X:"<<endl;
    cout<< "x: ";
    cin >> x;


    while(erro > (1e-15)){
        cout<< "##### INTERACAO " << i << " #####"<<endl<<endl;
        fxanti = fxnovo;
        fxnovo = funcao(x);
        fxD = funcaoD(x);
        fx1 = funcaoX1(x);
        cout<< "valor de x: "<< x <<endl;
        cout<< "valor de f(x): "<< fxnovo <<endl;
        cout<< "valor de f(x)': "<< fxD <<endl;
        cout<< "valor de f(x+1): "<< fx1 <<endl;
        x = fx1;


        erro = fabs(fabs(fxanti) - fabs(fxnovo));

        cout<< "valor de erro "<< erro <<endl;
        cout<< "##################################################################" <<endl<<endl;
        i++;

    }

    return 0;
}
