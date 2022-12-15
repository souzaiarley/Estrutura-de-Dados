#include <stdexcept>
#include "Queue.h"

Queue::Queue(){
    m_front = nullptr;
    m_back = nullptr;
    m_size = 0;
}
Queue::~Queue(){
    delete m_front;
}
void Queue::push(const char value){
    Node *novo = new Node(value, nullptr);
    if (m_size == 0){
        m_front = m_back = novo;
    }
    else {
        m_back->next = novo;
        m_back = novo;
    }
    m_size++;
}
void Queue::pop(){
    if (m_size == 0){
        throw std::underflow_error("empty Queue");
    }
    else if (m_size == 1){
        Node *aux = m_front;
        m_front = m_back = nullptr;
        delete aux;
    }
    else {
        Node *aux = m_front;
        m_front = m_front->next;
        aux->next = nullptr;
        delete aux;
    }
    m_size--;
}
const int Queue::size(){
    return m_size;
}
Node* Queue::front(){
    return m_front;
}