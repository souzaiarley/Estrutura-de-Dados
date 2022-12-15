#include <iostream>
#include <string>
#include <sstream>

using namespace std;

bool vogal(char c){
    char vogal[5] = {'a', 'e', 'i', 'o', 'u'};
    int i = 0;

    while (i < 5){
        if (vogal[i] == c){
            return true;
        }
        i++;
    }
    return false;
}

int contpalavra(string str){
    int c = 0;
    
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == ' '){
            c++;
        }
    }
    return c+1;
}

int contsilaba(string str){
    int s = 0;

    for (int i = 0; str[i] != '\0'; i++){
        if (vogal(str[i]) && !vogal(str[i+1]) && str[i+1]){
            s++;
        }
    }
    return s+1;
}

int main (){
    string str;
    getline(cin, str);

    stringstream ss;
    ss << str;
    string palavra;

    int fimsil, silabaid = 0, palavraid = 0;

    while(ss >> palavra){
        palavraid++;
        
        for (int i = 0; palavra[i]; i++){
            cout << palavra[i];
            if (vogal(palavra[i]) && !vogal(palavra[i+1]) && silabaid == 0 && (contsilaba(palavra) > 1)){
                fimsil = i;
                for (int j = 0; j < 2; j++){
                    for (int q = 0; q <= fimsil; q++){
                        cout << palavra[q];
                    }
                }
                silabaid++;
            }
        }
        silabaid = 0;
        if (palavraid != contpalavra(str)){
            cout << " ";
        }
    }

    return 0;
}