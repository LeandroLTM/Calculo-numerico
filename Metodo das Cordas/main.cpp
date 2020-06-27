#include <iostream>
#include <math.h>

using namespace std;

double funcao(double x){
    return (4*cos(x)- pow(M_E,2*x));
    //return (sqrt(x) - 5 * pow(M_E,x));
}

double xk(double a,double b){

    return (((a*funcao(b)) - (b*funcao(a)))/(funcao(b)-funcao(a)));
}

int main()
{
    double a,b,fa,fb,x,fxanti = 0,fxnovo = 0,erro = 100;
    int i=0;

    while(true){
        cout<< "Digite os limetes a e b:"<<endl;
        cout<< "a: ";
        cin >> a;
        cout<< "b: ";
        cin >> b;
        if(funcao(a)*funcao(b)<0){
            break;
        }
        cout<< "Valores de a e b invalidos"<<endl;
    }

    while(erro > (1e-15)){
        cout<< "##### INTERACAO " << i << " #####"<<endl<<endl;
        fa = funcao(a);
        fb = funcao(b);
        x = xk(a,b);
        fxanti = fxnovo;
        fxnovo = funcao(x);
        cout<< "valor de a: "<< a <<endl;
        cout<< "valor de b: "<< b <<endl;
        cout<< "valor de x: "<< x <<endl;
        cout<< "valor de f(a): "<< fa <<endl;
        cout<< "valor de f(b): "<< fb <<endl;
        if(fxnovo < 0){
            a = x;
        }else{
            b = x;
        }


        erro = fabs(fabs(fxanti) - fabs(fxnovo));

        cout<< "valor de f(x): "<< fxnovo <<endl;
        cout<< "valor de erro "<< erro <<endl;
        cout<< "##################################################################" <<endl<<endl;
        i++;

    }

    return 0;
}
