#include <iostream>

using namespace std;

int main (){
    string str;
    getline(cin, str);

    char tipo;
    cin >> tipo;

    //todo maiusculo
    if (tipo == 'M'){
        for (int i = 0; str[i] != '\0'; i++){
            if (str[i] >= 'a' && str[i] <= 'z'){
                str[i] = str[i] - 32;
            }
        }
    }

    //todo minusculo
    if (tipo == 'm'){
        for (int i = 0; str[i] != '\0'; i++){
            if (str[i] >= 'A' && str[i] <= 'Z'){
                str[i] = str[i] + 32;
            }
        }
    }

    //primeiro maiusculo
    if (tipo == 'p'){
        for (int i = 0; str[i] != '\0'; i++){
            if (i == 0 && (str[i] >= 'A' && str[i] <= 'Z') && str[i+1] == ' '){
                str[i] = str[i] + 32;
            }
            else if ((str[i] >= 'a' && str[i] <= 'z') && (str[i-1] == ' ' && str[i+1] != ' ')){
                str[i] = str[i] - 32;
            }
        }
    }

    //inverter
    if (tipo == 'i'){
        for (int i = 0; str[i] != '\0'; i++){
            if (str[i] >= 'A' && str[i] <= 'Z'){
                str[i] = str[i] + 32;
            }
            else if (str[i] >= 'a' && str[i] <= 'z'){
                str[i] = str[i] - 32;
            }
        }
    }

    //imprimindo
    for (int i = 0; str[i] != '\0'; i++){
        cout << str[i];
    }

    return 0;
}