#include <iostream>
#include <string>

using namespace std;

// Retorna o números de ocorrências do caractere 'c' na string 'str' (com 'n' caracteres).
// Algoritmo deve ser recursivo e sem comandos de repetição.
int contaCaracteres(string str, int n, char c){
    int cont = 0;

    if (n < 0){                           
        return cont;
    }
    else {
        if (str[n] == c){
            cont++; 
        }
        return cont + contaCaracteres(str, n-1, c);
    }

}

int tamanhostr(string str){
    int tam = 0;

    for (int i = 0; str[i] != '\0'; i++){
        tam++;
    }
    return tam;
}

int main() {
    string str;
    getline(cin, str);
    
    char c;
    cin >> c;

    cout << contaCaracteres(str, tamanhostr(str)-1, c);
    
}