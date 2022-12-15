#include <iostream>
#include <vector>

using namespace std;

vector<int> matchingStrings(vector<string>consultas, vector<string>busca){
    vector<int>ret;

    for (int i = 0; i < busca.size(); i++){
        int cont = 0;
        for (int j = 0; j < consultas.size(); j++){
            if (busca.at(i) == consultas.at(j)){
                cont++;
            }
        }
        ret.push_back(cont);
    }
    return ret;
}

int main (){
    int tam;
    string line;

    cin >> tam;
    vector<string> consultas;
    for (int i = 0; i < tam; i++){
        cin.ignore();
        cin >> line;
        consultas.push_back(line);
    }

    cin >> tam;
    vector<string> busca;
    for (int i = 0; i < tam; i++){
        cin.ignore();
        cin >> line;
        busca.push_back(line);
    }

    vector<int>ret =  matchingStrings(consultas, busca);
    
    for (int i = 0; i < ret.size(); i++){
        cout << ret[i];
        if (i < ret.size()-1){
            cout << ' ';
        }
        else {
            cout << endl;
        }
    }
}