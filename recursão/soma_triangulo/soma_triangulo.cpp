#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void mostrar(vector<int> vet) {
    cout << "[";

    for(auto i : vet)
        cout << i;

    cout << "]" << endl;
}

void calcular(vector<int> vet) {
    if((int) vet.size() == 1)
        return;

    vector<int> aux;

    for(size_t i = 0; i < (int) vet.size() - 1; i++)
        aux.push_back(vet[i] + vet[i + 1]);

    calcular(aux);
    mostrar(aux);
}

int main() {
    cout << "Insira os elementos: " << endl;

    string linha;
    getline(cin, linha);
    stringstream ss(linha);

    vector<int> vet;
    int value;

    while(ss >> value)
        vet.push_back(value);

    calcular(vet);
    mostrar(vet);
}