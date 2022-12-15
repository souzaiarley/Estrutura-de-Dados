#include <iostream>
#include <string>

using namespace std;

bool vogal(char _c){
    char vogais[5] = {'a', 'e', 'i', 'o', 'u'};

    for (int i = 0; i < 5; i++){
        if (_c == vogais[i]){
            return true;
        }
    }
    return false;
}

int main (){
    string str;
    getline(cin, str);

    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == ' ' && str[i+1] == str[i-1]){
            if (vogal(str[i+1])){
                continue;
            }
        }
        else if (str[i-1] == ' ' && str[i] == str[i-2]){
            continue;
        }
        else {
            cout << str[i];
        }
    }
    
    return 0;
}