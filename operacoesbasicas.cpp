#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

void imprimir_vetor(vector<int> vet, int a){
    if (a == 1){
        cout << vet[a-a] << " ";
    }
    else{
        imprimir_vetor(vet, a-1);
        cout << vet[a-1] << " ";
    }
}

void imprimir_vetorinv(vector<int> vet, int a){
    if (a == 1){
        cout << vet[a-1] << " ";
    }
    else{
        cout << vet.at(a-1) << " ";
        imprimir_vetorinv(vet, a-1);
    }
}

int sum(vector<int> vet, int a){
    int soma = vet[a-1];

    if (a == 1){
        return soma;
    }
    else {
        return soma + sum(vet, a-1);
    }
}

int multi(vector<int> vet, int a){
    int mult = vet[a-1];

    if (a == 1){
        return mult;
    }
    else {
        return mult * multi(vet, a-1);
    }
}

int min(vector<int> vet, int a){
    int menor = vet[a-1];

    if (a == 1){
        return menor;
    }
    else {
        if (menor < min(vet, a-1)){
            return menor;
        }
        else {
            return min(vet, a-1);
        }
    }
    
}

void inverte(vector<int> & vet, int a, int b){
    int aux = vet[a];
    vet[a] = vet[b];
    vet[b] = aux;
    if (b-1 > a+1){
        inverte(vet, a+1, b-1);
    }
}

int main (){
    string str;
    getline(cin, str);
    stringstream ss;
    ss << str;
    vector<int> v;
    int valor;
    while (ss >> valor){
        v.push_back(valor);
    }

    //imprimindo o vetor
    cout << "vet : [ ";
    imprimir_vetor(v, v.size());
    cout << "]" << endl;

    //imprimindo o vetor ao contrário
    cout << "rvet: [ ";
    imprimir_vetorinv(v, v.size());
    cout << "]" << endl;

    //soma
    cout << "sum : " << sum(v, v.size()) << endl;

    //produto
    cout << "mult: " << multi(v, v.size()) << endl;

    //menor
    cout << "min : " << min(v, v.size()) << endl;

    //invertendo o vetor
    inverte(v, 0, v.size()-1);
    cout << "inv : [ ";
    imprimir_vetor(v, v.size());
    cout << "]" << endl;

    return 0;
}