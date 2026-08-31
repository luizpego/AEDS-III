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
            int x = t->x;
            this->head = this->head->next;
            delete t;
            this->n--;
            cout << "O valor:" << x << " foi removido\n";
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

    void size() // Retorna o tamanho
    {
        cout << "O tamanho da fila e:" << this->n;
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
                cout << "" << t->x;
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
            cout << "O valor do primeiro elemento e:" << t->x;
        }
    }
};

int main()
{
    int opcao = 1;
    Queue f;
    int x = 0;
    while (opcao != 0)
    {
        cout << "1-Enfileirar\n";
        cout << "2-Desenfileirar\n";
        cout << "3-Limpar fila\n";
        cout << "4-Retornar tamanho da fila\n";
        cout << "5-Verificar se esta vazio\n";
        cout << "6-Mostrar fila\n";
        cout << "7-Retornar tamanho\n";
        cout << "0-Sair";
        cout << "Qual opcao voce deseja?\n";
        cin >> opcao;
        switch (opcao)
        {
        case 1:
            cout << "Qual valor voce deseja inserir na fila\?";
            cin >> x;
            f.enqueue(x);
            break;
        case 2:
            f.dequeue();
            break;
        case 3:
            f.clear();
            break;
        case 4:
            f.size();
            break;
        case 5:
            if (f.isEmpty())
                cout << "A fila esta vazia\n";
            else
                cout << "A fila NAO esta vazia\n";
            break;
        case 6:
            f.show();
            break;
        case 7:
            f.size();
            break;
        case 0:
            cout << "Encerrando...";
        default:
            cout << "Opcao invalida\n";
        }
        system("pause");
        system("cls");
    }
}