#ifndef NODE_H
#define NODE_H

struct Node {
    int value;
    Node *down;

    Node(const int &_value, Node *_down){
        value = _value;
        down = _down;
    }
    ~Node(){
        delete down;
    }
};

#endif