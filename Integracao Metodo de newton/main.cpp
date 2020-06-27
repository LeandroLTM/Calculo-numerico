#include <iostream>
#include "math.h"

using namespace std;

double Fx(double x){
    return exp(-pow(x,2));
}

double calulo_integral(double a, double b,double precisao){
    double h = (b-a)/precisao, aux = 0;
    for(int i=1;i<=precisao-1;i++){
        aux += Fx(a+(i*h));
    }
    return (h/2)*((2*aux)+Fx(a)+Fx(b));
}

int main()
{
    double a,b,precisao;
    cout<<"Digite os limites da funcao: "<<endl;
    cout<<"a: ";
    cin>>a;
    cout<<"b: ";
    cin>>b;
    cout<<"Digite a precisao do calculo: "<<endl;
    cin>>precisao;

    cout<<"Resultado da integral: "<< calulo_integral(a,b,precisao) <<endl;


    return 0;
}
