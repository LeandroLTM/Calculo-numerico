#include <iostream>
#include <fstream>

using namespace std;

double Li(double x,double xi,double xj){
    return ((x-xj)/(xi-xj));
}

int main()
{
    ifstream ler;
    ler.open("Dados1.txt");
    if(!ler.is_open()){
        cout<<"Erro na leitura do arquivo"<<endl;
        return 0;
    }

    int quantidade , dimencao;
    ler >> quantidade;
    cout<< "Quantidade de pontos: "<<quantidade<<endl;
    ler >> dimencao;
    cout<< "Dimencao dos pontos: "<<dimencao<<endl;

    double pontos[quantidade][dimencao],x,resultado = 0,aux;

    // lendo o arquivo de pontos para a matriz de pontos
    for(int i=0;i<quantidade;i++){
        for(int j=0;j<dimencao;j++){
            ler >> pontos[i][j];
        }
    }
    cout << "Digite o x: ";
    cin >> x;

    for(int i=0;i<quantidade;i++){
        aux = 1;
        for(int j=0;j<quantidade;j++){
            if(i !=  j){
                aux *= Li(x,pontos[i][0],pontos[j][0]);
            }
        }
        resultado += (pontos[i][1]*aux);
    }

    cout << "resultado: y = "<< resultado << endl;

//    for(int i=0;i<quantidade;i++){
//        cout<< "* ";
//        for(int j=0;j<dimencao;j++){
//           cout<< pontos[i][j] << "  ";
//        }
//        cout<<endl;
//    }
    return 0;
}
