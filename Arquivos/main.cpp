#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    //Criando o arquivo
    ofstream arquivo("Dados.txt");
    
    if(!arquivo)
    {
        cout<<"Erro ao tentar criar o arquivo\n";
        return 1;
    }
    char nome[50];
    float nota[10];
    for(int i=0; i<10;i++)
    {
        cout<<"Digite um nome\n";
        cin>>nome;
        cout<<"Digite uma nota\n";;
        cin>>nota[i];
        arquivo<<nome<<" tirou:"<<nota[i]<<"\n";
    }
   
    arquivo.close();
    
}