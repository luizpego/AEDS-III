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

    // Fun��o usada para obter um n� da lista
    // pelo seu �ndice (0 .. n-1).
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
        this->head = NULL;
        this->tail = NULL;
        this->n = 0;
    }

    // Detrutor
    ~List()
    {
        this->clear();
    }

    // Inserir no in�cio
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

    // Insrir em uma posi��o
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
        else if (pos == n)
        {
            this->pushBack(item);
        }
        else
        { // Neste caso exitem pelo menos 2 elementos na lista
          // e n�o estou inserindo nem no in�cio nem no fim
            Node *nn = new Node();
            nn->item = item;

            // Posicionar um tempor�rio na posi��o anterior
            Node *t1 = this->getNode(pos - 1);
            Node *t2 = t1->next;
            t1->next = nn;
            nn->next = t2;
            this->n++;
        }
    }

    // Remover do in�cio
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

    // Remover de uma posi��o
    int pop(int pos)
    {
    }

    // Retorna o item do in�cio
    int getFront()
    {
    }

    // Retorna o item do final
    int getBack()
    {
    }

    // Retorna o item de uma posi��o
    int get(int pos)
    {
    }

    // Tamanho da lista
    int size()
    {
        return this->n;
    }

    // Verifica se est� vazia
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
    List L;
    L.pushFront(10);
    L.show();

    List *MyList = new List();
    
    cout << "Hello world!" << endl;
    return 0;
}