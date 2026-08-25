#include <iostream>

using namespace std;

struct Node
{
    int x; //dado manipulado
    Node *next; //Endereco do proximo
};

class Stack
{
private:
    int n;
    Node *top;
public:
    //Construtor: inicializar um objeto
    //Ele executa automaticamente.
    Stack()
    {
        this->n = 0;
        this->top = nullptr;
    }
    //O destrutor é executado automaticamente
    //Quando o objeto é desalocado da memória.
    ~Stack()
    {
        cout<<"O objeto foi destruido\n";
        this->clear();
    }
    void push(int x) // Empilhar
    {
        Node *t = new Node; //Criar uma caixinha dinamica
        t->x=x;
        t->next = this->top;
        this->top=t;
        this->n++;
    }

    void pop() //Desempilha e retorna
    {
        if(this->isEmpty())
        {
            cout<<"Erro:pilha vazia \n";
        }

        Node *t = this->top;
        this->top = this->top->next;
        int x = t->x;
        delete t;
        this->n--;
        cout<<"o valor:"<<x<<" foi removido\n";
    }

    int get_top() // Retorna o topo
    {
        if(!this->isEmpty())
            return this->top->x;
        else
            cout<<"Erro: Pilha vazia";
    }

    bool isEmpty() //Retorna se esta vazia
    {
        if(this->n==0)
            return true;
        else
            return false;
    }

    int size() ///Retorna o tamanho
    {
        return this->n;
    }

    int clear()//Limpar a pilha
    {
        while( !this->isEmpty())
            this->pop();
    }

    void show()
    {
        Node *t = this->top;
        while(t !=NULL)
        {
            cout<<"\n"<<t->x;
            t=t->next;
        }
    }
};



int main()
{
    Stack s;
    int opcao = 1;
    while(opcao !=0)
    {
        int aux = 0;
        cout<<"*********************************";
        cout<<"*          TESTE PILHA          *";
        cout<<"*********************************\n";
        cout<<"1-Empilhar\n";
        cout<<"2-Desempilhar\n";
        cout<<"3-Limpar\n";
        cout<<"4-Tamanho\n";
        cout<<"5-Retornar topo\n";
        cout<<"6-Mostrar\n";
        cout<<"0-Sair\n";

        cout<<"Qual opcao voce deseja?\n";
        cin>>opcao;

        switch(opcao)
        {
        case 1:

            cout<<"Qual valor voce deseja inserir na pilha?\n";
            cin>>aux;
            s.push(aux);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.clear();
            break;
        case 4:
            s.size();
            break;
        case 5:
            s.get_top();
            break;
        case 6:
            s.show();
            break;
        case 0:
            cout<<"Encerrando...";
            break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}
