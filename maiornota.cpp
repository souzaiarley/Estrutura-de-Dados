#include <iostream>
#include <string>
#include <iomanip>

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
void imprimir(Registro aluno1, Registro aluno2){
    if (aluno1.nota > aluno2.nota){
        cout << aluno1.nome << " , " << fixed << setprecision(1) << aluno1.nota;
    }
    if (aluno1.nota < aluno2.nota){
        cout << aluno2.nome << " , " << fixed << setprecision(1) << aluno2.nota;
    }
    if (aluno1.nota == aluno2.nota) {
        cout << aluno1.nome << " e " << aluno2.nome << " , " << fixed << setprecision(1) << aluno1.nota;
    }
}

int main (){
    Registro aluno1, aluno2;

    leitura(aluno1);
    cin.ignore();
    leitura(aluno2);

    imprimir(aluno1, aluno2);

    return 0;
}