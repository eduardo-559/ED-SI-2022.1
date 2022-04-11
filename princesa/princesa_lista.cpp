#include <iostream>
#include <list>

using namespace std;

void jogar(list<int>& roda, list<int>::iterator& machado) {
    for (auto it = roda.begin(); it != roda.end(); it++)
        cout << *it << (it == machado ? "> " : "  ");
    cout << endl;
}

int main() {
    int total {}, machado {};

    cout << "Digite quantos participantes ira jogar: ";
    cin >> total;

    cout << "Digite quem comecara com o machado: ";
    cin >> machado;

    list<int> roda;

    for(int i = 1; i <= total; i++)
        roda.push_back(i);
        
    auto it_machado = next(roda.begin(), machado - 1);

    auto voltar_primeiro = [&roda](auto it) {
        return it == roda.end() ? roda.begin() : it;
    };

    while(roda.size() > 1) {
        jogar(roda, it_machado);
        it_machado = voltar_primeiro(next(it_machado, 1));
        it_machado = voltar_primeiro(roda.erase(it_machado));
    }

    jogar(roda, it_machado);
}