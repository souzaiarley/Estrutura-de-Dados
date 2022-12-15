#include <iostream>
using namespace std;

int main (){
    int tam, flag = 0;
    cin >> tam;
    int vet[tam];

    for (int i = 0; i < tam; i++){
        cin >> vet[i];
    }

    for (int i = 1; i < tam; i++){
        if (vet[i] < vet[i-1]){
            flag = 1;
            break;
        }
    }

    if (flag == 1){
        cout << "precisa de ajuste";
    }
    else {
        cout << "ok";    
    }

    return 0;
}