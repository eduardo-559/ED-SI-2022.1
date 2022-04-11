#include <iostream>
#include <vector>

using namespace std;

void jogar(vector<int> roda, int machado) {
    for (int i = 0; i < (int) roda.size(); i++)
        cout << i << (i == machado ? "> " : "  ");

    cout << endl;
}

int achar_vivo(vector<int>& roda, int pos) {
    do {
        pos = (pos + 1) % roda.size();
    } while(roda[pos] == false);

    return pos;
}

int main() {
    int total {}, machado {};

    cout << "Digite quantos participantes ira jogar: ";
    cin >> total;

    cout << "Digite quem comecara com o machado: ";
    cin >> machado;
    
    vector<int> roda(total, true);
    machado--;
    int qtd = roda.size() - 1;

    while(qtd--) {
        jogar(roda, machado);
        machado = achar_vivo(roda, machado);
        roda[machado] = false;
        machado = achar_vivo(roda, machado);
    }
}