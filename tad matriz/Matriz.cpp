        // Arquivo de Implementacao do TAD Matriz
        #include <iostream>
        #include <iomanip>
        #include "Matriz.h"
        using namespace std;

        // Aloca espaco dinamicamente para matriz com m linhas e n colunas
        Matriz::Matriz(int m, int n) {
            lin = m;
            col = n;
            mat = new int*[m];
            for(int i = 0; i < m; i++) {
                mat[i] = new int[n]{0}; // ja inicializa com zeros
            }
        }   

        // Destrutor: Libera a memoria que foi alocada dinamicamente no construtor
        Matriz::~Matriz() {
            for(int i = 0; i < lin; i++) {
                    delete[] mat[i];
                }
                delete[] mat;
                cout << "matriz liberada" << endl;
        }   

        // Retorna o numero de linhas da matriz
        int Matriz::linhas() {
            return lin;
        } 

        // Retorna o numero de colunas da matriz
        int Matriz::colunas() { 
            return col;
        }

        // Retorna o valor da celula [i][j] da matriz
        int Matriz::getValor(int i, int j) {
            return mat[i][j];
        } 

        // Atribui valor a celula [i][j] da matriz
        void Matriz::setValor(int valor, int i, int j) {
            this->mat[i][j] = valor;
        }

        // Imprimir a matriz 
        void Matriz::print() {
            for(int i = 0; i < lin; ++i) {
                for(int j = 0; j < col; ++j) {
                    cout << setw(7) << mat[i][j];
                }
                cout << "\n";
            }
        } 

        // Soma matrizes
        Matriz *Matriz::soma(Matriz& B) {
            if (this->lin == B.lin && this->col == B.col){
                Matriz *tres = new Matriz(lin,col);
                int **c;
                c = new int*[this->lin];
                for (int i = 0; i < this->lin; i++){
                    c[i] = new int[col];
                }
                for (int i = 0; i < lin; i++){
                    for (int j = 0; j < col; j++){
                        c[i][j] = this->mat[i][j] + B.mat[i][j];
                    }
                }
                tres->mat = c;
                return tres;
            }
            else {
                return nullptr;
            }
        }

        // Multiplica matrizes
        Matriz *Matriz::multiplica(Matriz& B) {
            if (this->colunas() == B.linhas()){
                Matriz *tres = new Matriz(lin,B.col);
                int **c;
                c = new int*[this->lin];
                for (int i = 0; i < this->lin; i++){
                    c[i] = new int[col];
                }
                for (int i = 0; i < lin; i++){
                    for (int j = 0; j < B.col; j++){
                        for (int k = 0; k < B.lin; k++){
                            c[i][j] = mat[i][k] * B.mat[k][j] + c[i][j];
                        }
                    }
                }
                tres->mat = c;
                return tres;
            }
                return nullptr;

        }