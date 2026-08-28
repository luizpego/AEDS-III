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
    Node *head;;
    Node *tail;

public:
    Queue()
    {
        this->head=NULL;
        this->tail=NULL;
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
        if(this->n==0) //Se a fila estiver vazia é necessário mover o head, senão apenas o tail
        {
            this->tail = t;
            this->head = t;
        }
        else
        {
            this->tail->next = t; //Faz com o que o valor da caixanha do tail aponte para a nova criada pelo t
            this->tail = t; //Move o ponteiro tail par ao endereço de memoria de t
        }
        this->n++;
    }
    int dequeue() // Desenfileira
    {

    }

    bool isEmpty() // Verifica se esta vazia
    {

    }

    int size() // Retorna o tamanho
    {
        return this->n;
    }

    void clear() // Limpa
    {

    }
    void show()
    {

    }
    int first()
    {

    }
};

int main()
{

}