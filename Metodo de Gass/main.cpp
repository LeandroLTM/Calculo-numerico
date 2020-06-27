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

    int tamanho, diagonal;
    ler >> tamanho;
        cout<< "tamanho: "<<tamanho<<endl;
    double matriz[tamanho][tamanho],vet[tamanho];
    double pivo = 0;

    // lendo o arquivo para a matriz e o vetor
    for(int i=0;i<tamanho;i++){
        for(int j=0;j<tamanho;j++){
            ler >> matriz[i][j];
        }
        ler >> vet[i];
    }


    for(int j=tamanho-1,diagonal = tamanho-1;j>0;j--,diagonal--){
        for(int i=0;i<diagonal;i++){
            cout<< matriz[i][j] << endl;
            cout<< matriz[diagonal][diagonal] << endl;
            pivo = -matriz[i][j]/matriz[diagonal][diagonal];
            cout<<"Pivo: "<< pivo << endl;
            cout<< endl;
            for(int l=0;l<tamanho;l++){
                matriz[i][l] += (matriz[diagonal][l]*pivo);
                 cout<< "resultado: "<<matriz[i][l] << endl;
            }
            vet[i] += (vet[diagonal]*pivo);
        }

    }



    for(int i=0;i<tamanho;i++){
            for(int j=0;j<tamanho;j++){

                cout<<  matriz[i][j] <<"\t";
            }
            cout<<" = "<<  vet[i] <<"\t";
            cout<<endl;
    }


    return 0;
}
