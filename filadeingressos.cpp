#include <iostream>
#include <vector>

using namespace std;

int main (){
    int num;
    cin >> num;
    vector<int> fila;

    for (int i = 0; i < num; i++){
        static int elemento;
        cin >> elemento;
        fila.push_back(elemento);
    }

    cin >> num;

    for (int i = 0; i < num; i++){
        static int elemento;
        cin >> elemento;

        for (int j = 0; j < fila.size(); j++){
            if (fila[j] == elemento){
                fila.erase(fila.begin()+j);
                break;
            }
        }
    }

    for (int i = 0; i < fila.size(); i++){
        cout << fila[i] <<" ";
    }
    cout << endl;

    return 0;
}