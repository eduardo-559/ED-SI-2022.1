#include <iostream>
#include <vector>
#include <fstream>
#include <unistd.h>

using namespace std;

void mostrar_floresta(vector<string> mapa) {
    for(int i = 0; i < (int) mapa.size(); i++)
        cout << mapa[i] << endl;
}

bool verificacao(vector<string>& mapa, int l, int c) {
    int nl = mapa.size();
    int nc = mapa[0].size();

    if(l < 0 || l >= nl || c < 0 || c >= nc) {
        return true;
    }

    return false;
}

int queimar(vector<string>& mapa, int l, int c) {
    if(verificacao(mapa, l,c) || mapa[l][c] != '#') {
        return 0;
    }

    int total = 1;
    mapa[l][c] = 'o';

    total +=
    queimar(mapa, l-1,c) +
    queimar(mapa, l, c+1) +
    queimar(mapa, l+1, c) +
    queimar(mapa, l, c-1);

    mapa[l][c] = 'x';

    return total;
}

int main(){
    ifstream floresta("queimada.txt");

    int nl{}, nc{}, li{}, ci{};
    floresta >> nl >> nc >> li >> ci;

    vector<string> mapa;

    for(int l = 0; l < nl; l++) {
        string line;
        floresta >> line;
        mapa.push_back(line);
    }

    cout << "Floresta: " << endl;
    mostrar_floresta(mapa);

    cout << endl << "Queimando...." << endl;
    sleep(3);

    cout << endl << "Queimou!!!" << endl;
    int arvores_queimadas = queimar(mapa, li, ci);
    mostrar_floresta(mapa);

    cout << "Arvores Queimadas: " << arvores_queimadas << endl;
}
