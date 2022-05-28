#include <iostream>
#include <vector>

using namespace std;

void jogar(vector<int> roda, int machado) {
    for (int i = 0; i < (int) roda.size(); i++)
        cout << roda[i] << (i == machado ? "> " : "  ");

    cout << endl;
}

int main() {
    int total {}, machado {};

    cout << "Digite quantos participantes ira jogar: ";
    cin >> total;

    cout << "Digite quem comecara com o machado: ";
    cin >> machado;

    vector<int> roda(total);

    for (int i = 0; i < total; i++)
        roda[i] = i + 1;
        
    machado--;
    int qtd = roda.size() - 1;

    while(qtd--) {
        jogar(roda, machado);
        machado = (machado + 1) % roda.size();
        roda.erase(roda.begin() + machado);
        machado = machado % roda.size();
    }

    jogar(roda, machado);
}