/************************************************************************
 * Arquivo de implementacao da classe ForwardList
 * No final deste arquivo existem algumas funcoes que estao incompletas 
 * e voce precisa implementa-las para concluir a atividade
 ************************************************************************/
#include <vector>
#include <stdexcept>
#include <string>
#include "Node.h"
#include "ForwardList.h"
#include <iostream>
using namespace std;

/***************************************************
 * Implementacao das funcoes-membro da classe
 ***************************************************/

ForwardList::ForwardList() {
    m_head = new Node(0, nullptr);
    m_size = 0;
}

ForwardList::ForwardList(const ForwardList& lst) {
    m_head = new Node(0, nullptr);
    m_size = lst.m_size;
    Node *lstCurrent = lst.m_head->next;
    Node *thisLast = m_head;
    while(lstCurrent != nullptr) {
        thisLast->next = new Node(lstCurrent->value, nullptr);
        lstCurrent = lstCurrent->next;
        thisLast = thisLast->next;
    }
}

bool ForwardList::empty() const {
    return m_head->next == nullptr;
}

int ForwardList::size() const {
    return m_size;
}

void ForwardList::clear() {
    while(m_head->next != nullptr) {
        Node *aux = m_head->next;
        m_head->next = aux->next;
        delete aux;
    }
    m_size = 0;
}

ForwardList::~ForwardList() {
    clear();
    delete m_head;
}

Item& ForwardList::operator[](int index) {
    int count = 0;
    Node *current = m_head->next;
    while(count < index) {
        current = current->next;
        count++;
    }
    return current->value;
}

const Item& ForwardList::operator[](int index) const {
    int count = 0;
    Node *current = m_head->next;
    while(count < index) {
        current = current->next;
        count++;
    }
    return current->value;
}

void ForwardList::insert_at(int index, const Item& val) {
    int count = 0;
    Node *current = m_head;
    while(count < index) {
        current = current->next;
        count++;
    }
    Node *newNode = new Node(val, current->next);
    current->next = newNode;
    m_size++;
}

void ForwardList::remove_at(int index) {
    int count = 0;
    Node *current = m_head;
    while(count < index) {
        current = current->next;
        count++;
    }
    Node *temp = current->next;
    current->next = temp->next;
    delete temp;
    m_size--;
}

std::string ForwardList::toString() {
    std::string str = "[ ";
    Node *ptr = m_head->next;
    while(ptr != nullptr) {
        str += std::to_string(ptr->value) + " ";
        ptr = ptr->next;
    }
    str += "]";
    return str;
}

/***********************************************************
 * Funcoes adicionais - Parte 2
 ***********************************************************/

void ForwardList::concat(ForwardList& lst) {
    Node *aux = m_head;
    while(aux->next != nullptr){
        aux = aux->next;
    }
    
    aux->next = lst.m_head->next;
    Node *vazio = nullptr;
    lst.m_head->next = vazio;
}

void ForwardList::remove(const Item& val) {
    int tam = m_size;
    for (int i = 0; i < tam; i++){
        Node *aux = m_head;
        while (aux->next != nullptr){
            if (aux->next->value == val){
                Node *prev = aux;
                aux = aux->next;
                prev->next = aux->next;
                delete aux;
                m_size--;
                break;
            }
            aux = aux->next;
        }
    }
}

ForwardList* ForwardList::clone() {
    ForwardList *copia = new ForwardList();
    Node *aux = m_head;
    copia->m_size = m_size;
    while (aux->next != nullptr){
        Node *aux2 = copia->m_head;
        while (aux2->next != nullptr){
            aux2 = aux2->next;
        }

        Node *novo = new Node(aux->next->value, nullptr);
        aux2->next = novo;
        aux = aux->next;
    }

    return copia;
}

void ForwardList::appendVector(const std::vector<Item>& vec) {
    for (int i = 0; i < vec.size(); i++){
        Node *aux = m_head;
        while(aux->next != nullptr){
            aux = aux->next;
        }
        Node *novo = new Node(vec[i], nullptr);
        aux->next = novo;
        m_size++;
    }
}

void ForwardList::swap(ForwardList& lst) {
    Node *aux = m_head;
    m_head = lst.m_head;
    lst.m_head = aux;
}

bool ForwardList::equals(const ForwardList& lst) const {
    Node *aux1 = m_head;
    Node *aux2 = lst.m_head;

    if (m_size != lst.m_size){
        return false;
    }
    
    while (aux1->next != nullptr){
        if (aux1->value != aux2->value){
            return false;
        }
        aux1 = aux1->next;
        aux2 = aux2->next;
    }
    return true;
}

void ForwardList::reverse() {
    if (m_size == 1){
        return;
    }
    Node *aux = m_head;
    Node *last;
    while (aux->next != nullptr){
        if (aux->next->next == nullptr){
            last = aux->next;
            last->next = aux;
            aux->next = nullptr;
            break;
        }
        aux = aux->next;
    }
    for (int i = 0; i < m_size; i++){
        aux = m_head;
        if (aux->next->next == nullptr){
            break;
        }
        while (m_head->next != nullptr){
            if (aux->next->next == nullptr){
                aux->next->next = aux;
                aux->next = nullptr;
                break;
            }
            aux = aux->next;
        }
    }
    m_head->next = last;
}

Item& ForwardList::get(int index) {
    if (index < 0 || index >= m_size){
        throw std::range_error("index out of range");
    }
    Node *aux = m_head;
    for (int i = 0; i <= index; i++){
        aux = aux->next;
    }
    return aux->value;
}

const Item& ForwardList::get(int index) const {
    if (index < 0 || index >= m_size){
        throw std::range_error("index out of range");
    }
    Node *aux = m_head;
    for (int i = 0; i <= index; i++){
        aux = aux->next;
    }
    return aux->value;
}
