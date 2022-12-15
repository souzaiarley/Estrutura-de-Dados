#include <stdexcept>
#include "Queue.h"

Stack::Stack(){
    m_top = nullptr;
    m_size = 0;
}
Stack::~Stack(){
    delete m_top;
}
void Stack::push(const int value){
    Node *novo = new Node(value, m_top);
    m_top = novo;
    m_size++;
}
void Stack::pop(){
    if (m_top == nullptr){
        throw std::underflow_error("empy stack");
    }
    Node *aux = m_top;
    m_top = m_top->down;
    aux->down = nullptr;
    delete aux;
    m_size--;
}
const int Stack::top(){
    return m_top->value;
}
const int Stack::size(){
    return m_size;
}
Node* Stack::mtop(){
    return m_top;
}

Queue::Queue(){
    pilha1 = new Stack();
    pilha2 = new Stack();
}
Queue::~Queue(){
    delete pilha1;
    delete pilha2;
}
void Queue::push_back(const int value){
    if (pilha1->size() == 0){
            Node *aux = pilha2->mtop();
            while (aux != nullptr){
                pilha1->push(aux->value);
                aux = aux->down;
            }
            while (pilha2->size() != 0){
                pilha2->pop();
            }
        }
        pilha1->push(value);
}
void Queue::pop_front(){
    if (pilha2->size() == 0){
            Node *aux = pilha1->mtop();
            while (aux != nullptr){
                pilha2->push(aux->value);
                aux = aux->down;
            }
            while (pilha1->size() != 0){
                pilha1->pop();
            }
        }
        pilha2->pop();
}
const int Queue::front(){
    if (pilha2->size() == 0){
            Node *aux = pilha1->mtop();
            while (aux != nullptr){
                pilha2->push(aux->value);
                aux = aux->down;
            }
            while (pilha1->size() != 0){
                pilha1->pop();
            }
        }
        return pilha2->top();
}