#include <iostream>
#include <fstream>
#include "math.h"

using namespace std;

double Fx(double x){
    //return sin(3*x);
    return pow(x,2)+3*x;// resposta 5,3333333 limites -2 a 2
}

int main()
{
    ifstream ler;
    ler.open("Dados.txt");
    if(!ler.is_open()){
        cout<<"Erro na leitura do arquivo"<<endl;
        return 0;
    }

    double tabela[36][3],a,b,tamanho_tabela = 36;
    int x;

    // lendo o arquivo de pontos para a matriz de pontos
    for(int i=0;i<tamanho_tabela;i++){
        for(int j=0;j<3;j++){
            ler >> tabela[i][j];
        }
    }
    cout<< "Digite os limites da funcao: "<<endl;
    cout<< "a: ";
    cin>> a;
    cout<< "b: ";
    cin>> b;
    cout<< "Digite quantos pontos: "<<endl;
    cin>> x;

    double controle[x][3],aux = 0;

    for(int i=0,j=0;i<tamanho_tabela;i++){
        if(tabela[i][0] == x){
            controle[j][0] = (((b-a)/2)*tabela[i][2])+((b+a)/2);
            controle[j][1] = Fx(controle[j][0]);
            controle[j][2] = tabela[i][1];
            j++;
        }
    }

    for(int i=0;i<x;i++){
        aux += controle[i][1]*controle[i][2];
    }

    cout<< "Resultado da integral: "<< ((b-a)/2)*aux << endl;

//    for(int i=0;i<x;i++){
//        cout<< "* ";
//        for(int j=0;j<3;j++){
//           cout<< controle[i][j] << "  ";
//        }
//        cout<<endl;
//    }

//
//    for(int i=0;i<tamanho_tabela;i++){
//        cout<< "* ";
//        for(int j=0;j<3;j++){
//           cout<< tabela[i][j] << "  ";
//        }
//        cout<<endl;
//    }
    return 0;
}
