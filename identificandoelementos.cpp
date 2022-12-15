#include <iostream>
#include <string>

using namespace std;

int main (){
    int j, ponto = 0, c = 0;

    string str; 
    getline(cin, str);

    for (int i = 0; str[i] != '\0'; i++){
        for (j = i; str[j] != ' '; j++){
            if (str[j] == '.'){
                ponto = 1;
            }
            if (str[j] >= 'a' && str[j] <= 'z'){
                c = 1;
            }
            if (str[j+1] == '\0'){
                break;
            }
        }

        if (ponto == 0 && c == 0){
            cout << "int";
        }

        if (c == 1){
            cout << "str";
        }

        if (ponto == 1 && c == 0){
            cout << "float";
        }

        i = j;
        c = 0;
        ponto = 0;

        if (str[i] == ' '){
            cout << str[i];
        }
    }
    
    return 0;
}