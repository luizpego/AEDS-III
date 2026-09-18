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
    Node *getNode(int pos)
    {
        Node *t;
        int i = 0;
        if (pos > (n / 2)) // Se a posicao escolhida estiver depois da metade o método começa pela tail ao invés do head
        {
            i = n; // i = n pois prefiro que lista começa com o indice 1.
            Node *t = this->tail;
            while (i != pos)
            {
                t = t->prev;
                i--;
            }
        }
        else
        {
            i = 1; // Faz com que a lista comece pelo indice 1
            Node *t = this->head;
            while (i != pos)
            {
                t = t->next;
                i++;
            }
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
        if (pos < 0 || pos > n) // Não permite a insercao de elementos em posicoes invalidas
        {
            cout << "Erro:Posicao invalida\n";
            return;
        }
        else
        {
            if (pos == n)
            {
                this->pushBack(item);
            }
            else if (pos == 0)
            {
                this->pushFront(item);
            }
            else
            {

                Node *t = new Node(); // Cria uma nova caixinha
                t->item = item;
                t->prev = NULL;
                t->next = NULL;
                Node *aux = this->getNode(pos);    // Pega a posicao desejada
                Node *nn = this->getNode(pos - 1); // Pega a posicao anterior
                t->next = aux;
                t->prev = nn;
                aux->prev = t;
                nn->next = t;
                this->n++;
            }
        }
    }

    // Remover do inicio
    int popFront()
    {
        if (this->isEmpty())
        {
            cout << "Erro:A lista esta vazia\n";
            return -1;
        }
        else if (this->n == 1)
        {
            int item = 0;
            Node *t = this->head;
            this->tail = NULL;
            this->head = NULL;
            this->n--;
            item = t->item;
            delete t;
            return item;
        }
        else
        {
            int item = 0;
            Node *t = this->head;
            this->head = this->head->next;
            this->head->prev = NULL;
            item = t->item;
            delete t;
            this->n--;
            return item;
        }
    }

    // Remover do final
    int popBack()
    {
        if (this->isEmpty())
        {
            cout << "Erro:A lista esta vazia\n";
            return -1;
        }
        else if (this->n == 1) // Quando a lista so tem 1 elemento
        {
            int item = 0;
            Node *t = this->head;
            item = t->item;
            this->head = NULL;
            this->tail = NULL;
            this->n--;
            delete t;
            return item;
        }
        else
        {
            int item = 0;
            Node *t = this->tail;
            this->tail = t->prev;
            item = t->item;
            this->tail->next = NULL;
            delete t;
            this->n--;
            return item;
        }
    }

    // Remover de uma posi��o
    int pop(int pos)
    {
        if (pos < 0 || pos > n) // Não permite a insercao de elementos em posicoes invalidas
        {
            cout << "Erro:Posicao invalida\n";
        }
        else
        {
            if (pos == n)
            {
                return this->popBack();
            }
            else if (pos == 0)
            {
                return this->popFront();
            }
            else
            {
                int item = 0;
                Node *t = this->getNode(pos);
                t->prev->next = t->next;
                t->next->prev = t->prev; // Faz com que o prev da caxinha depois de t aponte para a anterior a t;
                item = t->item;
                delete t;
                this->n--;
                return item;
            }
        }
    }

    // Retorna o item do in�cio
    int getFront()
    {
        if (isEmpty())
        {
            cout << "A lista esta vazia\n";
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
        if (isEmpty())
        {
            cout << "A lista esta vazia\n";
            return -1;
        }
        else
        {
            return this->tail->item;
        }
    }

    // Retorna o item de uma posi��o
    int get(int pos)
    {
        if (isEmpty())
        {
            cout << "A lista esta vazia\n";
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

    // Verifica se est� vazia
    bool isEmpty()
    {
        return this->n == 0;
    }

    // Apaga todos os elementos da lista
    void clear()
    {
        Node *t = this->head;
        while (t != NULL)
        {
            t = t->next;
            this->popFront();
        }
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
        if (isEmpty())
        {
            cout << "Erro: a lista esta vazia\n";
        }
        else
        {
            Node *t = this->getNode(pos);
            t->item = item;
        }
    }
}; 

int main()
{
}