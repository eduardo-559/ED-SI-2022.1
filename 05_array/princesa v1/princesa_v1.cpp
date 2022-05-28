#include <iostream>
#include <vector>

using namespace std;

void mostrar(vector<int> fila, int machado) {
    cout << "[";
    bool verifica_pos_prim = true;

    for(int i = 0; i < fila.size(); i++) {
        if(verifica_pos_prim)
            verifica_pos_prim = false;
        else
            cout << " ";
        
        if(fila[i] == machado)
            cout << fila[i] << ">";
        else
            cout << fila[i];
    }

    cout << "]" << endl;
}

void matar(vector<int>& fila, int machado) {
    fila.erase(fila.begin() + machado);
}

int prox_machado(vector<int>& fila, int vivo) {
    return *fila.begin() + 1;
}

int main() {
    int tamanho {};
    int machado {};

    cout << "Digite o tamanho: ";
    cin >> tamanho;

    cout << "Digite com quem comeca o machado: ";
    cin >> machado;

    vector<int> fila;

    for(int i = 0; i < tamanho; i++)
        fila.push_back(i + 1);

    mostrar(fila, machado);

    while(fila.size() > 1) {
        matar(fila, machado);
        machado = (machado + 1) % fila.size();
        mostrar(fila, machado);
    }
}