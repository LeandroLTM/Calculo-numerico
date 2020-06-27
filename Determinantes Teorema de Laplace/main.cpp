#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

double determinante(double **m,int tamanho){
    double det = 0,**mat = new double*[tamanho-1];

    for(int i=0;i<tamanho-1;i++){
        mat[i] = new double[tamanho-1];
    }

    if(tamanho == 2){
        return (m[0][0]*m[1][1])-(m[0][1]*m[1][0]);
    }else{
        for(int i=0;i<tamanho;i++){
            for(int j=0;j<tamanho;j++){
                for(int k=0;k<tamanho;k++){
                    if((j!=0)&&(k!=i)){
                        if(k > i){
                            mat[j-1][k-1] = m[j][k];
                        }else{
                            mat[j-1][k] = m[j][k];
                        }
                    }
                }
            }
            cout<<"Matriz ordem: "<<tamanho-1<<endl;
            cout<<"Coeficiente matriz anterior: "<<m[0][i]<<endl;
            for(int i=0;i<tamanho-1;i++){
                    for(int j=0;j<tamanho-1;j++){

                        cout<<  mat[i][j] <<"\t";
                    }
                    cout<<endl;
            }
            cout<<endl;
            det += (pow(-1,(1+i+1))*(m[0][i])*(determinante(mat,tamanho -1)));
        }
    }
    return det;
}

int main()
{


    ifstream ler;
    ler.open("Dados.txt");
    if(!ler.is_open()){
        cout<<"Erro na leitura do arquivo"<<endl;
        return 0;
    }

    int tamanho;
    ler >> tamanho;
        cout<< "Tamanho da matriz: "<<tamanho<<endl;
    double **matriz = new double*[tamanho];

    for(int i=0;i<tamanho;i++){
        matriz[i] = new double[tamanho];
    }

    for(int i=0;i<tamanho;i++){
        for(int j=0;j<tamanho;j++){
            ler >> matriz[i][j];
        }
    }

    for(int i=0;i<tamanho;i++){
            for(int j=0;j<tamanho;j++){

                cout<<  matriz[i][j] <<"\t";
            }
            cout<<endl;
    }

    cout<<"###################Determinante: "<< determinante(matriz,tamanho)<<" ###################"<<endl;


    return 0;
}
