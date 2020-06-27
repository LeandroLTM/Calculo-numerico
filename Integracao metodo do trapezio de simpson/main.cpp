#include <iostream>
#include "math.h"

using namespace std;

double Fx(double x){
    cout<< "Resultado de " << x << " :" << exp(-pow(x,2)) <<endl;
    return exp(-pow(x,2));
}

//double calulo_integral(double a, double b,double precisao){
//    double h = (b-a)/(2*precisao), aux = 0;
//    for(int i=1;i<=precisao-1;i++){
//        aux += Fx(a+(2*i*h));
//    }
//    return (h/3)*((2*aux)+Fx(a)+Fx(b));
//}

double calulo_integral(double a, double b,double precisao){
    double h = (b-a)/(2*precisao), aux = 0;
    cout<< "h: "<< h<< endl;
    cout<< "a: "<< a<< endl;
    cout<< "b: "<< b<< endl;

    for(double i=(a+h);i<=(b-h);i += 2*h){
            cout<<"     i: " << i <<endl;
        aux += (Fx(i-h)+(4*Fx(i))+ Fx(i+h));
    }
    return (h/3)*aux;
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
