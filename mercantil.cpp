#include <iostream>
using namespace std;

int main (){
    int n, pontos_j1 = 0, pontos_j2 = 0;
    cin >> n;
    float preco[n], j1[n];
    char j2[n];

    for (int i = 0; i < n; i++){
        cin >> preco[i];
    }
    for (int i = 0; i < n; i++){
        cin >> j1[i];
    }

    for (int i = 0; i < n; i++){
        cin >> j2[i];
    }

    for (int i = 0; i < n; i++){
        if (j1[i] == preco[i] || (j1[i] < preco[i] && j2[i] == 'm') || (j1[i] > preco[i] && j2[i] == 'M')){
            pontos_j1++;
        }
        else {
            pontos_j2++;
        }
    }
    if (pontos_j1 == pontos_j2){
        cout << "empate";
    }
    else if (pontos_j1 > pontos_j2){
        cout << "primeiro";
    }
    else {
        cout << "segundo";
    }

    return 0;
}