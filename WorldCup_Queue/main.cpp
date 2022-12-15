#include <iostream>
#include "Queue.h"
using namespace std;

const char Winner(Node *A, Node *B){
    int GolsA, GolsB;
    cin >> GolsA >> GolsB;

    if (GolsA > GolsB){
        return A->value;
    }
    return B->value;
}

int main (){
    Queue *times = new Queue();
    for (int i = 0; i < 16; i++){
        times->push('A'+i);
    }

    while (times->size() != 1){
        times->push(Winner(times->front(), times->front()->next));
        times->pop();
        times->pop();
    }

    cout << times->front()->value << endl;
}