#include <iostream>
#include <fstream>
#include "stdlib.h"
#include <vector>

using namespace std;

int main()
{
    ifstream ler;
    ler.open("Dados1.txt");
    if(!ler.is_open()){
        cout<<"Erro na leitura do arquivo"<<endl;
        return 0;
    }

    int tamanho;
    ler >> tamanho;
        cout<< "tamanho: "<<tamanho<<endl;
    double U[tamanho][tamanho],L[tamanho][tamanho],vet[tamanho];
    double pivo = 0;

    // lendo o arquivo para a U e o vetor e inicialisando a L
    for(int i=0;i<tamanho;i++){
        for(int j=0;j<tamanho;j++){
            ler >> U[i][j];
            if(i == j){
                L[i][j] = 1;
            }else{
                L[i][j] = 0;
            }
        }
        ler >> vet[i];
    }


    for(int j=0;j<tamanho-1;j++){
        for(int i=tamanho-1;i>j;i--){
            cout<< U[i][j] << endl;
            cout<< U[j][j] << endl;
            pivo = -U[i][j]/U[j][j];
            L[i][j] = pivo;
            cout<<"Pivo: "<< pivo << endl;
            cout<< endl;
            for(int l=0;l<tamanho;l++){
                U[i][l] += (U[j][l]*pivo);
                 cout<< "resultado: "<<U[i][l] << endl;
            }
        }

    }

    cout<< "==================:" <<endl;
    cout<< "MATRIZ U:" <<endl;
    for(int i=0;i<tamanho;i++){
            for(int j=0;j<tamanho;j++){

                cout<<  U[i][j] <<"\t";
            }
            cout<<endl;
    }
    cout<< "==================:" <<endl;
    cout<< "MATRIZ L:" <<endl;

        for(int i=0;i<tamanho;i++){
            for(int j=0;j<tamanho;j++){

                cout<<  L[i][j] <<"\t";
            }
            cout<<endl;
    }


    return 0;
}
