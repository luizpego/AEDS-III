#include <iostream>
#include <fstream>
#include <vector> //Acrescente um vetor dinâmico
#include <algorithm>
using namespace std;

void cria_arquivo(int *A, int n, char *nomeArquivo)
{
    ofstream fout;
    fout.open(nomeArquivo, ios::binary);

    if (!fout)
    {
        cout << "Erro ao criar o arquivo\n";
        return;
    }

    for (int i = 0; i < n; i++)
    {
        fout.write((char *)&A[i], sizeof(A[i]));
    }

    fout.close();
}

int main()
{
    int A[10] = {3, 5, 2, 7, 9, 1, 3, 10, 23, 8};
    cria_arquivo(A, 10, "Numeros.bin");
    ifstream fin;
    vector<int> bloco;
    fin.open("Numeros.bin", ios::binary);

    if (!fin)
    {
        cout << "Erro ao abir o arquivo\n";
        return 0;
    }

    int valor;
    // Enquanto ler processa o dado

    while (fin.read((char *)&valor, sizeof(valor)))
    {
        bloco.push_back(valor);
    }

    // Ordenando a lista
    sort(bloco.begin(), bloco.end());
    // Para cada elemento x do bloco
    for (int x : bloco)
    {
        cout << x << "\n";
    }

    ofstream fout;

    fout.open("numeros.bin", ios::binary);

    if (!fout)
    {
        cout << "Erro ao criar o arquivo\n";
        return 0;
    }
    else
    {
        for (int x : bloco)
        {
            fout.write((char *)&x, sizeof(x));
            cout << x << "";
        }
    }
    fin.close();
    return 0;
}