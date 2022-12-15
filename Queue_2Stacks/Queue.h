#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"

class Stack {
    private:
        Node *m_top;
        int m_size;

    public:
        Stack(); // Cria a pilha vazia
        ~Stack();
        void push(const int value); // Empilha um novo Node no topo
        void pop(); // Remove o Node que está no topo
        const int top(); // Retorna o valor do Node que está no topo 
        const int size(); // Retorna m_size
        Node* mtop(); // Retorna m_top
};

class Queue {
    private:
        Stack *pilha1;
        Stack *pilha2;

    public:
        Queue();
        ~Queue();
        void push_back(const int value); // Insere no final da fila 
        void pop_front(); // Remove o elemento da frente da fila
        const int front(); // Retorna o elemento da frente
};

#endif