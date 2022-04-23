#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

void mostrar(vector<int> vet) {
    for(auto i : vet)
        cout << i << ' ';
}

void inverter(vector<int> vet) {
    for(int i = (int) vet.size() - 1; i >= 0; i--)
        cout << vet[i] << ' ';
}

int soma(vector<int> vet) {
    int somar{};

    for(int i : vet) {
        somar += i;
    }

    return somar;
}

int multiplica(vector<int> vet){
    int multiplicar {1};

    for(int i : vet){
        multiplicar *= i;
    }

    return multiplicar;
}

int menor_elemento(vector<int> vet) {
    int menor = vet[0];

    for(int i = 0; i < (int) vet.size(); i++){
        if(vet[i] < menor)
            menor = vet[i];
    }

    return menor;
}

vector<int> inverter_aux(vector<int>& vet){
    vector<int> aux(vet);
    reverse(aux.begin(), aux.end());
    mostrar(aux);
}

int main() {
    cout << "Digite os elementos do vetor: " << endl;

    string linha;
    getline(cin, linha);
    stringstream ss(linha);

    vector<int> vet;

    int elem{};
    while (ss >> elem){
        vet.push_back(elem);
    }

    cout << "Vetor: [ ";
    mostrar(vet);
    cout << "]" << endl;

    cout << "Vetor invertido: [ ";
    inverter(vet);
    cout << "]" << endl;

    cout << "Soma: " << soma(vet) << endl;

    cout << "Multiplicacao: " << multiplica(vet) << endl;

    cout << "Menor Elemento: : " << menor_elemento(vet) << endl;

    cout << "Vetor invertido (aux): [ " ;
    inverter_aux(vet);
    cout << "]";
}