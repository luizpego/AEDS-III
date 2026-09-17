#include <iostream>

using namespace std;

struct Node
{
    int item;
    Node *next;
};

class List
{
private:
    Node *head;
    Node *tail;
    int n;

    // Função usada para obter um nó da lista
    // pelo seu índice (0 .. n-1).
    Node *getNode(int pos)
    {
        int i = 0;
        Node *t = this->head;

        while (i < pos)
        {
            t = t->next;
            i++;
        }

        return t;
    }

public:
    // Construtor
    List()
    {
        cout<<"A lista foi inicializada\n";
        this->head = NULL;
        this->tail = NULL;
        this->n = 0;
    }

    // Destrutor
    ~List()
    {
        this->clear();
    }

    // Inserir no início
    void pushFront(int item)
    {
        Node *t = new Node();
        t->item = item;
        t->next = NULL;

        if (this->isEmpty())
        {
            this->head = t;
            this->tail = t;
        }
        else
        {
            t->next = this->head;
            this->head = t;
        }

        this->n++;
    }

    // Inserir no final
    void pushBack(int item)
    {
        if (this->isEmpty())
        {
            this->pushFront(item);
        }
        else
        {
            Node *t = new Node();
            t->item = item;
            t->next = NULL;

            this->tail->next = t;
            this->tail = t;

            this->n++;
        }
    }

    // Inserir em uma posição
    void push(int item, int pos)
    {
        if (pos < 0 || pos > this->n)
        {
            cout << "Erro: indice invalido.\n";
            return;
        }

        if (pos == 0)
        {
            this->pushFront(item);
        }
        else if (pos == this->n)
        {
            this->pushBack(item);
        }
        else
        {
            // Neste caso existem pelo menos 2 elementos na lista
            // e não estou inserindo nem no início nem no fim
            Node *nn = new Node();
            nn->item = item;

            // Posicionar um temporário na posição anterior
            Node *t1 = this->getNode(pos - 1);
            Node *t2 = t1->next;

            t1->next = nn;
            nn->next = t2;

            this->n++;
        }
    }

    // Remover do início
    int popFront()
    {
        if (this->isEmpty())
        {
            cout << "Erro: Lista vazia.\n";
            return -1;
        }
        else
        {
            int item = this->head->item;

            if (this->n == 1)
            {
                delete this->head;
                this->head = NULL;
                this->tail = NULL;
            }
            else
            {
                Node *t = this->head;
                this->head = this->head->next;
                delete t;
            }

            this->n--;

            return item;
        }
    }

    // Remover do final
    int popBack()
    {
        if (this->isEmpty())
        {
            cout << "Erro: Lista vazia.\n";
            return -1;
        }
        else if (this->n == 1)
        {
            return this->popFront();
        }
        else
        {
            Node *t = this->getNode(this->n - 2);

            int item = this->tail->item;

            delete this->tail;

            t->next = NULL;
            this->tail = t;

            this->n--;

            return item;
        }
    }

    // Remover de uma posição
    int pop(int pos)
    {
        if (this->isEmpty())
        {
            cout << "Erro: Lista vazia.\n";
            return -1;
        }

        if (pos < 0 || pos >= this->n)
        {
            cout << "Erro: Posicao invalida.\n";
            return -1;
        }

        if (pos == 0)
        {
            return this->popFront();
        }
        else if (pos == this->n - 1)
        {
            return this->popBack();
        }
        else
        {
            // t1 aponta para a posição anterior
            Node *t1 = this->getNode(pos - 1);

            // t2 aponta para a posição que será removida
            Node *t2 = t1->next;

            int item = t2->item;

            t1->next = t2->next;

            delete t2;

            this->n--;

            return item;
        }
    }

    // Retorna o item do início
    int getFront()
    {
        if (this->isEmpty())
        {
            cout << "Erro: A lista esta vazia.\n";
            return -1;
        }
        else
        {
            return this->head->item;
        }
    }

    // Retorna o item do final
    int getBack()
    {
        if (this->isEmpty())
        {
            cout << "Erro: A lista esta vazia.\n";
            return -1;
        }
        else
        {
            return this->tail->item;
        }
    }

    // Retorna o item de uma posição
    int get(int pos)
    {
        if (pos < 0 || pos >= this->n)
        {
            cout << "Erro: Posicao invalida.\n";
            return -1;
        }
        else
        {
            Node *t = this->getNode(pos);

            return t->item;
        }
    }

    // Tamanho da lista
    int size()
    {
        return this->n;
    }

    // Verifica se está vazia
    bool isEmpty()
    {
        return this->n == 0;
    }

    // Apaga todos os elementos da lista
    void clear()
    {
        while (!this->isEmpty())
        {
            this->popFront();
        }
    }

    // Mostra todos os elementos da lista
    void show()
    {
        if (this->isEmpty())
        {
            cout << "Lista vazia." << endl;
            return;
        }

        int n = 0;

        for (Node *t = this->head; t != NULL; t = t->next)
        {
            cout << t->item << " Item na Posicao " << n << endl;
            n++;
        }

        cout << endl;
    }
};

int main()
{
    List L; // Inicia o objeto

    int opcao;
    int item;
    int pos;

    do
    { // Mantem a lista em looping até o usuário decidir encerrar.
        cout << "\n===== MENU =====\n";
        cout << "1 - Inserir elemento no inicio\n";
        cout << "2 - Inserir elemento no final\n";
        cout << "3 - Inserir elemento em uma posicao\n";
        cout << "4 - Remover elemento do inicio\n";
        cout << "5 - Remover elemento do final\n";
        cout << "6 - Remover elemento de uma posicao\n";
        cout << "7 - Consultar elemento do inicio\n";
        cout << "8 - Consultar elemento do final\n";
        cout << "9 - Consultar elemento de uma posicao\n";
        cout << "10 - Obter tamanho da lista\n";
        cout << "11 - Verificar se a lista esta vazia\n";
        cout << "12 - Mostrar lista\n";
        cout << "13 - Remover todos os elementos\n";
        cout << "0 - Sair\n";

        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            cout << "Digite o valor: ";
            cin >> item;

            L.pushFront(item);
            break;

        case 2:
            cout << "Digite o valor: ";
            cin >> item;

            L.pushBack(item);
            break;

        case 3:
            cout << "Digite o valor: ";
            cin >> item;

            cout << "Digite a posicao: ";
            cin >> pos;

            L.push(item, pos);
            break;

        case 4:
            if (!L.isEmpty())
            {
                item = L.popFront();
                cout << "Valor removido: " << item << endl;
            }
            else
            {
                L.popFront();
            }
            break;

        case 5:
            if (!L.isEmpty())
            {
                item = L.popBack();
                cout << "Valor removido: " << item << endl;
            }
            else
            {
                L.popBack();
            }
            break;

        case 6:
            cout << "Digite a posicao: ";
            cin >> pos;

            if (pos >= 0 && pos < L.size())
            {
                item = L.pop(pos);
                cout << "Valor removido: " << item << endl;
            }
            else
            {
                L.pop(pos);
            }
            break;

        case 7:
            if (!L.isEmpty())
            {
                cout << "Primeiro elemento: " << L.getFront() << endl;
            }
            else
            {
                L.getFront();
            }
            break;

        case 8:
            if (!L.isEmpty())
            {
                cout << "Ultimo elemento: " << L.getBack() << endl;
            }
            else
            {
                L.getBack();
            }
            break;

        case 9:
            cout << "Digite a posicao: ";
            cin >> pos;

            if (pos >= 0 && pos < L.size())
            {
                cout << "Elemento: " << L.get(pos) << endl;
            }
            else
            {
                L.get(pos);
            }
            break;

        case 10:
            cout << "Tamanho da lista: " << L.size() << endl;
            break;

        case 11:
            if (L.isEmpty())
            {
                cout << "A lista esta vazia.\n";
            }
            else
            {
                cout << "A lista nao esta vazia.\n";
            }
            break;

        case 12:
            L.show();
            break;

        case 13:
            L.clear();
            cout << "Todos os elementos foram removidos.\n";
            break;

        case 0:
            cout << "Programa encerrado.\n";
            break;

        default:
            cout << "Opcao invalida.\n"; // Caso o usuário escolha uma opcao que nao exista retorna opcao invalida.
        }
        system("pause");
        system("cls"); // Limpa o terminal apos cada operação.
    } while (opcao != 0);

    return 0;
}