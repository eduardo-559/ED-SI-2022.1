#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

ostream& operator<<(ostream& os, const vector<int>& fila) {
    os << "[ ";
    for(int i = 0; i < (int) fila.size(); i++) {
        os << fila[i];
        if(i != (int) fila.size() - 1) {
            os << ", ";
        }
    }
    os << " ]";

    return os;
}

void quem_sobrou_maneira_errada(vector<int>& fila, int desistiu) {
    for(int i = 0; i < (int) fila.size(); i++) {
        if(fila[i] == desistiu){
            fila.erase(fila.begin() + i);
            return;
        }
    }
}

vector<int> quem_sobrou_maneira_correta(vector<int> fila, vector<int> sairam) {
    vector<int> sobraram;
    unordered_set<int> sairam_set(begin(sairam), end(sairam));

    for(auto i : fila) {
        if(sairam_set.find(i) == sairam_set.end()) {
            sobraram.push_back(i);
        }
    }

    return sobraram;
}

void enfileirar(vector<int>& fila, int tam) {
    for(int i = 0; i < tam; i++){
        int linha;
        cout << "Digite o elemento " << i << " : ";
        cin >> linha;
        fila.push_back(linha);
    }
}

int main() {
    int grupo {};
    cout << "Digite quantos elementos tera o grupo: ";
    cin >> grupo;

    vector<int> fila;
    fila.reserve(grupo);
    enfileirar(fila, grupo);

    int desistiu {};
    cout << "Digite quantos elementos ira desistir do grupo: ";
    cin >> desistiu;

    vector<int> desistentes;
    desistentes.reserve(desistiu);
    enfileirar(desistentes, desistiu);
    
    cout << "Maneira correta: " << endl;
    cout <<  quem_sobrou_maneira_correta(fila, desistentes) << endl;

    cout << "Maneira errada: " << endl;
    for(int i = 0; i < desistiu; i++) {
        quem_sobrou_maneira_errada(fila, desistentes[i]);
    }
    cout << fila;

    return 0;
}