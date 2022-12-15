#include <iostream>
using namespace std;

int main (){
    int matriz[3][3];
    int total = 0;
    
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cin >> matriz[i][j];
        }
    }
    
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 3; j++){
            if (matriz[i][j] > matriz[i+1][j]){
                total++;
            }
        }
    }
    
    cout << total;
    
    return 0;
}