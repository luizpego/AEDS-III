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
    Node *getNode(int pos){  //Função usada para obter um nó da lista pelo seu índice.
        int i = 0;
        Node *t = this->head;
        while(i < pos){
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
    void pushAt(int item, int pos)
    {
        if(pos < 0 || pos>this->n)
        {
            cout<<"Erro:Posição invalida. \n";
            return;
        }

        if(pos == 0)
           this->pushFront(item);
        else if (pos == n)
        {
            this->pushBack(item);
        }
        else //Neste caso existe pelo menos 2 elementos na lista
        {    //E não estou inserindo nem no inicio nem no fim.
            Node *nn = new Node();
            nn->item = item;

            //Posicionar o temporario na posição anterior.
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
            cout << "Erro:Lista vazia\n";
            return -1;
        }
        else
        {
            int item = this->head->item;
            if (this->n == 1)
            {
                delete this->head;
                this->head = NULL;
                this->tail == NULL;
                this->n--;
            }
            else
            {
                Node *t = this->head;
                this->head = this->head->next;
                this->n--;
                delete t;
            }
        }
    }

    // Remover do final
    int popBack()
    {
        if (this->isEmpty())
        {
            cout << "Erro: A lista esta vazia";
            return -1;
        }
        else
        {
            if (n == 1) 
            {
                delete this->head;
                this->head = NULL;
                this->tail == NULL;
                this->n--;
            }
            else
            {
             

            }
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
    }

    // Mostra todos os elementos da lista
    void show()
    {
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
