#include <iostream>
using namespace std;
struct Node
{
    int x;
    Node *next;
};

class Queue
{
private:
    int n;
    Node *head;
    ;
    Node *tail;

public:
    Queue()
    {
        this->head = NULL;
        this->tail = NULL;
        this->n = 0;
    }
    ~Queue()
    {
    }
    void enqueue(int x) // Enfileirar
    {
        Node *t = new Node();
        t->x = x;
        t->next = NULL;
        if (this->n == 0) // Se a fila estiver vazia é necessário mover o head, senão apenas o tail
        {
            this->tail = t;
            this->head = t;
        }
        else
        {
            this->tail->next = t; // Faz com o que o valor da caixanha do tail aponte para a nova criada pelo t
            this->tail = t;       // Move o ponteiro tail par ao endereço de memoria de t
        }
        this->n++;
    }
    int dequeue() // Desenfileira
    {
        if (this->isEmpty())
        {
            cout << "A fila esta vazia\n";
            ;
        }
        else
        {
            Node *t = this->head;
            this->head = this->head->next;
            delete t;
            this->n--;
        }
        if (this->n == 0)
        {
            this->tail = NULL; // Faz com que quando a lista estiver vazia o tail vire null, asimm como o head.
        }
    }

    bool isEmpty() // Verifica se esta vazia
    {
        if (this->head == NULL)
            return true;
        else
            return false;
    }

    int size() // Retorna o tamanho
    {
        return this->n;
    }

    void clear() // Limpa
    {
        if (isEmpty())
        {
            cout << "A fila esta vazia";
        }
        else
        {
            while (this->head != NULL)
            {
                this->dequeue();
            }
        }
    }
    void show()
    {
        if (isEmpty())
        {
            cout << "A fila esta vazia";
        }
        else
        {
            Node *t = this->head;
            while (t != NULL)
            {
                cout<< "" << t->x;
                t = t->next;
            }
        }
    }
    void first()
    {
        if (isEmpty())
        {
            cout << "A fila esta vazia";
        }
        else
        {
            Node *t = this->head;
            cout<<"O valor do primeiro elemento e:"<<t->x;
        }
    }
};

int main()
{
}