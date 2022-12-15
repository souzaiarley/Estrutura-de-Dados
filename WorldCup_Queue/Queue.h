#ifndef QUEUE_H
#define QUEUE_H

struct Node {
    Node *next;
    char value;

    Node(const char _value, Node *_next){
        next = _next;
        value = _value;
    }
    ~Node(){
        delete next;
    }
};

class Queue {
    private:
        Node *m_front;
        Node *m_back;
        int m_size;

    public:
        Queue();
        ~Queue();
        void push(const char value);
        void pop();
        const int size();
        Node* front();
};

#endif