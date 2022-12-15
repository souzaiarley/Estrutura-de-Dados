#include <iostream>
#include "Queue.h"
using namespace std;

int main (){
    int qnty, i = 0;
    Queue *fila = new Queue();
    cin >> qnty;

    while (i < qnty){
        int op;
        cin >> op;

        if (op == 1){
            int value;
            cin >> value;
            fila->push_back(value);
        }
        else if (op == 2){
            fila->pop_front();
        }
        else if (op == 3){
           cout << fila->front() << endl;
        }
        i++;
    }
}