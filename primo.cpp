#include <iostream>
using namespace std;

char primo (int x){
    for (int i = 2; i < x; i++){
        if (x % i == 0){
            return 'f';
        }
    }
    return 't';
}

int main (){
    int a, b;

    cin >> a >> b;
    
    for (int i = a; i <= b; i++){
        if (primo(i) == 't'){
            cout << i << "\n";
        }
    }

    return 0;
}