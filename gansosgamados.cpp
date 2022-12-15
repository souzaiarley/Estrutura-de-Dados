#include <iostream>
#include <string>

using namespace std;

int ContEspaco(string _str){
    int cont = 0;

    for (int i = 0; _str[i] != '\0'; i++){
        if (_str[i] == ' '){
            cont++;
        }
    }
    return cont; 
}

int IsOrder (string _str1, string _str2){
    for (int i = 0; _str1[i] != '\0' || _str2[i] != '\0'; i++){
        if (_str1[i] > _str2[i]){
            return false;
        }
        else if (_str1[i] < _str2[i]){
            return true;
        }
    }
}

int main (){
    int j = 0, k = 0;

    string str;
    getline(cin, str);

    char palavras[ContEspaco(str) + 1][50];

    //formando um array de strings
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] != ' '){
            palavras[j][k] = str[i];
            k++;
        }
        else {
            j++;
            k = 0;
        }
    }

    //verificando se as palavras estão na ordem
    for (int i = 0; i < ContEspaco(str); i++){
        if (IsOrder(palavras[i], palavras[i+1])){
            continue;
        }
        else {
            cout << "nao";
            return 0;
        }
    }
    cout << "sim";

    return 0;
}