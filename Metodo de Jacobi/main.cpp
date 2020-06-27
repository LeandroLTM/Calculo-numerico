#include <iostream>
#include <fstream>
#include "stdlib.h"
#include <math.h>

using namespace std;

int main()
{
    ifstream ler;
    ler.open("Dados2.txt");
    if(!ler.is_open()){
        cout<<"Erro na leitura do arquivo"<<endl;
        return 0;
    }

    int tamanho,k = 0;
    ler >> tamanho;
        cout<< "tamanho: "<<tamanho<<endl;
    double matriz[tamanho][tamanho],vetX[tamanho],vetXanti[tamanho],vetTermo[tamanho];
    double erro = 1,aux = 0,divisor;

    for(int i=0;i<tamanho;i++){
        vetX[i] = 0;
        vetXanti[i] = 0;
    }

    // lendo o arquivo para a matriz e o vetor
    for(int i=0;i<tamanho;i++){
        for(int j=0;j<tamanho;j++){
            ler >> matriz[i][j];
        }
        ler >> vetTermo[i];
    }

    for(int i=0;i<tamanho;i++){
            for(int j=0;j<tamanho;j++){

                cout<<  matriz[i][j] <<"\t";
            }
            cout<<" = "<<  vetTermo[i] <<"\t";
            cout<<endl;
    }
    cout<<"Valores inseridos com sucesso"<<endl;

    while(erro > 1e-15){
            cout<< "Intecao: "<< k <<endl;
        for(int i=0;i<tamanho;i++){
            vetXanti[i] = vetX[i];
        }
        for(int i=0;i<tamanho;i++){
            aux=0;
            for(int j=0;j<tamanho;j++){
                if(i != j){
                    aux += vetXanti[j]*matriz[i][j];
                }else{
                    divisor = matriz[i][j];
                }
            }
            aux += vetTermo[i];
            aux /= divisor;
            vetX[i] = aux;

        }
        erro = 0;
        for(int i=0;i<tamanho;i++){
            erro = erro + fabs(fabs(vetXanti[i]) - fabs(vetX[i]));
            cout<<  vetX[i] <<"\t";
        }
        cout<<endl;
        cout<< "erro: " << erro <<endl;
        k++;
    }



//    for(int i=0;i<tamanho;i++){
//            for(int j=0;j<tamanho;j++){
//
//                cout<<  matriz[i][j] <<"\t";
//            }
//            cout<<" = "<<  vetX[i] <<"\t";
//            cout<<endl;
//    }


    return 0;
}
