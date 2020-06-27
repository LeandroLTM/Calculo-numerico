#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream ler;
    ler.open("Dados1.txt");
    if(!ler.is_open()){
        cout<<"Erro na leitura do arquivo"<<endl;
        return 0;
    }

    int quantidade;
    ler >> quantidade;
    cout<< "Quantidade de pontos: "<<quantidade<<endl;

    double pontos[quantidade][quantidade+1];

    // lendo o arquivo de pontos para a matriz de pontos
    for(int i=0;i<quantidade;i++){
        for(int j=0;j<2;j++){
            ler >> pontos[i][j];
        }
    }
    // setando o resto das posiçoes como 0.
    for(int i=0;i<quantidade;i++){
        for(int j=2;j<quantidade+1;j++){
            pontos[i][j] = 0;
        }
    }

    for(int j=2,aux=quantidade-1,intera = 1;j<quantidade+1;j++,aux--,intera++){
        for(int i=0;i<aux;i++){
            //cout<< pontos[i+1][j-1] << "-" << pontos[i][j-1] << "/" << pontos[i+intera][0]<<"-" <<pontos[i][0]<<endl;
            pontos[i][j] = (pontos[i+1][j-1]-pontos[i][j-1])/(pontos[i+intera][0]-pontos[i][0]);
        }
    }

    for(int i=0;i<quantidade;i++){
        for(int j=0;j<quantidade+1;j++){
            cout<< pontos[i][j] << "\t";
        }
        cout<<endl;
    }
    return 0;
}
