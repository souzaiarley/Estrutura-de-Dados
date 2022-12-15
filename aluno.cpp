#include <iostream>
#include <string>

using namespace std;

//struct
struct Registro {
    string nome;
    int matricula;
    string disciplina;
    double nota;
};

//funcao leitura
void leitura(Registro & aluno){
    getline(cin, aluno.nome);
    cin >> aluno.matricula;
    cin.ignore();
    getline(cin, aluno.disciplina);
    cin >> aluno.nota;
}

//funcao imprimir
void imprimir(Registro aluno){
    cout << aluno.nome << ' ';
    if (aluno.nota >= 7){
        cout << "aprovado(a) em ";
    }
    else {
        cout << "reprovado(a) em ";
    }
    cout << aluno.disciplina;
}

int main (){
    Registro aluno;

    leitura(aluno);
    imprimir(aluno);

    return 0;
}