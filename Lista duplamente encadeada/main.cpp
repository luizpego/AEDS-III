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

    // Funcao usada para obter um n� da lista
    Node *getNode(int pos)
    {
        int i = 0;         //Metodo de obter no mais eficiente que o anterior e com menor custo operacional
        if (pos > (n / 2)) // Se a posicao escolhida estiver depois da metade o método começa pela tail ao invés do head
        {
            i = n - 1;
            Node *t = this->tail;
            while (i != pos)
            {
                t = t->prev;
                i--;
            }
            return t;
        }
        else
        {
            i = 0;
            Node *t = this->head;
            while (i != pos)
            {
                t = t->next;
                i++;
            }
            return t;
        }
    }

public:
    // Construtor
    List()
    {
        this->head = NULL;
        this->tail = NULL;
        this->n = 0;
    }

    // Detrutor limpa a memoria quando o programa é encerrado
    ~List()
    {
        this->clear();
    }

    // Inserir no inicio
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

    // Inserir em uma posicao
    void pushAt(int item, int pos)
    {
        if (pos < 0 || pos > n) // Não permite a insercao de elementos em posicoes invalidas
        {                       
            cout << "Erro:Posicao invalida\n";
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
        else if (this->n == 1)  //Quando ha apenas um elemento
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
        else if (this->n == 1) // Se houver apenas 1 elemento
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

    // Remover de uma posicao
    int pop(int pos)
    {
        if (pos < 0 || pos > n - 1) // Não permite a insercao de elementos em posicoes invalidas
        {
            cout << "Erro:Posicao invalida\n";
            return -1;
        }
        else
        {
            if (pos == n - 1)
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
        else if(pos < 0 || pos > this->n - 1)
        {
            cout<<"Posicao invalida\n";
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
        if (this->isEmpty())
            cout << "A lista esta vazia\n";
        else
        {
            cout << "\nList -->";
            Node *t;
            t = this->head;
            while (t != NULL)       //Mostra os elementos da lista da esquerda para a direita
            {
                cout << t->item << " ";
                t = t->next;
            }
            cout << "\nList -->";
            t = this->tail;
            while (t != NULL)       //Mostra os elementos da lista da direita para a esquerda
            {
                cout << t->item << " ";
                t = t->prev;
            }
            cout << "\n = " << this->n;
        }
    }

    // Atribui um valor a elemento da lista
    void set(int item, int pos)
    {
        if (this->isEmpty())
        {
            cout << "Erro: a lista esta vazia\n";
        }
        else if(pos < 0 || pos > this->n - 1)
        {
            cout<<"Posição invalida\n";
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
    {
        List L; // Inicia o objeto

        int opcao = 1;  //Inicia em 1 para o condição do do while nao ser verdadeira e nao encerrar o main antes mesmo dele comecar
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
            if (!(cin >> opcao))
            {
                cout << "Entrada invalida ou encerrada.\n";
                return 0;
            }

            switch (opcao)
            {
            case 1:
                cout << "Digite o valor: ";
                if (!(cin >> item))
                {
                    cout << "Entrada invalida ou encerrada.\n";
                    return 0;
                }

                L.pushFront(item);
                break;

            case 2:
                cout << "Digite o valor: ";
                if (!(cin >> item))
                {
                    cout << "Entrada invalida ou encerrada.\n";
                    return 0;
                }

                L.pushBack(item);
                break;

            case 3:
                cout << "Digite o valor: ";
                if (!(cin >> item))
                {
                    cout << "Entrada invalida ou encerrada.\n";
                    return 0;
                }

                cout << "Digite a posicao: ";
                if (!(cin >> pos))
                {
                    cout << "Entrada invalida ou encerrada.\n";
                    return 0;
                }

                L.pushAt(item, pos);
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
                if (!(cin >> pos))
                {
                    cout << "Entrada invalida ou encerrada.\n";
                    return 0;
                }

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
                if (!(cin >> pos))
                {
                    cout << "Entrada invalida ou encerrada.\n";
                    return 0;
                }

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
                cout << "Programa encerrado.\n";        //Quando o usuario escolhe a opcao 0, ou seja, encerra o programa, a mensagem "Programa encerrado" é retornada
                break;

            default:
                cout << "Opcao invalida.\n"; // Caso o usuário escolha uma opcao que nao exista retorna opcao invalida.
            }
            system("pause");
            system("cls"); // Limpa o terminal apos cada operação.
        } while (opcao != 0);

        return 0;
    }
}