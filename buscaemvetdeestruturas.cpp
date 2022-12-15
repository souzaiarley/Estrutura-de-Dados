#include <iostream>
#include <iomanip>

using namespace std;

struct Aluno {
    int matricula;
    char nome[100];
    float media;
};

void leitura(Aluno & _aluno){
    cin >> _aluno.matricula;
    cin.ignore();
    cin.get(_aluno.nome, 100);
    cin >> _aluno.media;
}


int main (){
    int n, m;
    cin >> n;
    Aluno v[n];

    for (int i = 0; i < n; i++){
        leitura(v[i]);
    }

    cin >> m;

    for (int i = 0; i < n; i++){
        if (v[i].matricula == m){
            cout << v[i].nome << endl;
            cout << fixed << setprecision(1) << v[i].media << endl;
            return 0;
        }
    }

    cout << "NAO ENCONTRADA" << endl;
    
    return 0;
}