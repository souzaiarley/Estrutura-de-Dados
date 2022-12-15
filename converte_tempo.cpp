#include <iostream>

using namespace std;


void converte_tempo(int tempo, int *hora, int *minuto, int *segundo){
    *hora = tempo/3600;
    tempo = tempo % 3600;
    *minuto = tempo/60;
    tempo = tempo % 60;
    *segundo = tempo;
}



int main (){
    int H, M, S;
    int *h, *m, *s;

    cin >> S;

    h = &H;
    m = &M;
    s = &S;

    converte_tempo(S, h, m, s);
    cout << H << ":" << M << ":" << S;


    return 0;
}