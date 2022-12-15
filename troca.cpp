#include <iostream>

using namespace std;

void troca(int *x, int *y){
    int aux = *x;
    *x = *y;
    *y = aux;
}

int main (){
    int a, b;

    cin >> a;
    cin >> b;

    int *x, *y;
    x = &a;
    y = &b;

    troca(x, y);

    cout << a << " " << b << endl;

    return 0;
}