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
    Stack(){
        cout<<"Criei um objeto novo\n";
        this->n = 0;
        this->top = nullptr;
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
    if(this->isEmpty()){
        cout<<"Erro:pilha vazia \n";
    }

    Node *t = this->top;
    this->top = this->top->next;
    int x = t->x;
    delete t;
    this->n--;
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
};



int main()
{
    Stack s;
    cout<<s.size();


    return 0;
}
