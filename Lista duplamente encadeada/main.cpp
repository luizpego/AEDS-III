#include <iostream>

using namespace std;

struct Node
{
    int item;
    Node *prev;
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
        t->prev = NULL;
        t->next = NULL;

        if (this->isEmpty())
        {
            this->tail = t;
            this->head = t;
        }
        else
        {
            t->next = this->head;
            this->head->prev = t;
            this->head = t;
        }
        this->n++;
    }

    // Inserir no final
    void pushBack(int item)
    {
        Node *t = new Node();
        t->item = item;
        t->prev = NULL;
        t->next = NULL;

        if (this->isEmpty())
        {
            this->tail = t;
            this->head = t;
        }
        else
        {
            this->tail->next = t;
            t->prev = this->tail;
            this->tail = t;
        }
        this->n++;
    }

    // Insrir em uma posi��o
    void pushAt(int item, int pos)
    {
    }

    // Remover do in�cio
    int popFront()
    {
    }

    // Remover do final
    int popBack()
    {
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
    }

    // Mostra todos os elementos da lista
    void show()
    {
        cout << "\nList -->";
        Node *t;
        t = this->head;
        while (t != NULL)
        {
            cout << t->item << " ";
            t = t->next;
        }
        cout << "\nList -->";
        t = this->tail;
        while (t != NULL)
        {
            cout << t->item << " ";
            t = t->prev;
        }
        cout << "\n = " << this->n;
    }

    // Atribui um valor a elemento da lista
    void set(int item, int pos)
    {
    }
};

int main()
{
    List L;

    L.pushFront(10);
    L.pushFront(20);
    L.show();
    return 0;
}
