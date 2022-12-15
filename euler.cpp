#include <iostream>
#include <iomanip>
using namespace std;

double fatorial (int x){
    double fatorial = 1;
    
    for (int i = x; i > 0; i--){
        fatorial = fatorial * i;
    }
    
    return fatorial;
}

double euler (int x){
    double soma = 1;
    
    for (int i = x; i > 0 ; i--){
        soma = soma + (1/fatorial(i));
    }
    
    return soma;
}

int main (){
    int n;
    
    cin >> n;
    cout << fixed << setprecision(6) << euler(n);

    return 0;
}