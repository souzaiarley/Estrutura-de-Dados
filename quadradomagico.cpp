#include <iostream>
using namespace std;

int main (){
    int matriz[3][3];
    int soma, flag = 0, teste = 0;
    
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cin >> matriz[i][j];
        }
    }
    
    soma = matriz[0][2] + matriz[1][1] + matriz[2][0];
    
    if (soma != matriz[0][0] + matriz[1][1] + matriz[2][2]){
        flag = 1;
    }
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            teste = teste + matriz[i][j];
        }
        if (teste != soma){
            flag = 1;
            break;
        }
        teste = 0;
    }
    
    for (int j = 0; j < 3; j++){
        for (int i = 0; i < 3; i++){
            teste = teste + matriz[i][j];
        }
        if (teste != soma){
            flag = 1;
            break;
        }
        teste = 0;
    }
    
    if (flag == 1){
        cout << "nao";
    }
    else {
        cout << "sim";
    }
    
    return 0;
}