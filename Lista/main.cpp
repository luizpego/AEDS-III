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
    List()
    {
        this->head = NULL;
        this->tail = NULL;
        this->n = 0;
    }

    ~List()
    {
        this->clear();
    }

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

    void push(int item, int pos)
    {
        if (pos < 0 || pos > this->n)
        {
            cout << "Erro: posicao invalida.\n";
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
            Node *t = new Node();

            t->item = item;

            Node *anterior = this->getNode(pos - 1);

            t->next = anterior->next;
            anterior->next = t;

            this->n++;
        }
    }

    int popFront()
    {
        if (this->isEmpty())
        {
            cout << "Erro: Lista vazia.\n";
            return -1;
        }

        int item = this->head->item;

        Node *t = this->head;

        this->head = this->head->next;

        delete t;

        this->n--;

        if (this->n == 0)
        {
            this->head = NULL;
            this->tail = NULL;
        }

        return item;
    }

    int popBack()
    {
        if (this->isEmpty())
        {
            cout << "Erro: Lista vazia.\n";
            return -1;
        }

        if (this->n == 1)
        {
            return this->popFront();
        }

        Node *anterior = this->getNode(this->n - 2);

        int item = this->tail->item;

        delete this->tail;

        anterior->next = NULL;
        this->tail = anterior;

        this->n--;

        return item;
    }

    int pop(int pos)
    {
        if (this->isEmpty())
        {
            cout << "Erro: Lista vazia.\n";
            return -1;
        }

        if (pos < 0 || pos >= this->n)
        {
            cout << "Erro: posicao invalida.\n";
            return -1;
        }

        if (pos == 0)
        {
            return this->popFront();
        }

        if (pos == this->n - 1)
        {
            return this->popBack();
        }

        Node *anterior = this->getNode(pos - 1);
        Node *remover = anterior->next;

        int item = remover->item;

        anterior->next = remover->next;

        delete remover;

        this->n--;

        return item;
    }

    int getFront()
    {
        if (this->isEmpty())
        {
            cout << "Erro: Lista vazia.\n";
            return -1;
        }

        return this->head->item;
    }

    int getBack()
    {
        if (this->isEmpty())
        {
            cout << "Erro: Lista vazia.\n";
            return -1;
        }

        return this->tail->item;
    }

    int get(int pos)
    {
        if (pos < 0 || pos >= this->n)
        {
            cout << "Erro: posicao invalida.\n";
            return -1;
        }

        Node *t = this->getNode(pos);

        return t->item;
    }

    int size()
    {
        return this->n;
    }

    bool isEmpty()
    {
        return this->n == 0;
    }

    void clear()
    {
        while (!this->isEmpty())
        {
            this->popFront();
        }
    }

    void show()
    {
        if (this->isEmpty())
        {
            cout << "Lista vazia.\n";
            return;
        }

        int pos = 0;
        Node *t = this->head;

        while (t != NULL)
        {
            cout << "Posicao " << pos << ": " << t->item << endl;

            t = t->next;
            pos++;
        }
    }
};

int main()
{
    List L;

    int opcao;
    int item;
    int pos;

    do
    {
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
            cout << "Opcao invalida.\n";
        }
        system("pause");
        system("cls");
    } while (opcao != 0);

    return 0;
}