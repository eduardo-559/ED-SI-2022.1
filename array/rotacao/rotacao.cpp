#include <iostream>
#include <vector>

using namespace std;

void mostrar(vector<int> lista) {
    cout << "[ ";
    for(int i : lista)
        cout << i;
    cout << " ]" << endl;
}

void mover_direita(vector<int>& lista, int rotacao) {
    if(rotacao <= 0)
        return;

    int tam = lista.size() - 1;
    int primeiro = lista[tam];

    for(int i = tam; i >= 0; i--)
        lista[i] = lista[i - 1];

    lista[0] = primeiro;
    mover_direita(lista, rotacao - 1);
}

int main() {
    int tam {};
    cout << "Digite quantos elementos tera o vetor: ";
    cin >> tam;

    vector<int> lista;
    for(int i = 0; i < tam; i++) {
        int elem;
        cout << "Digite o elemento " << i << " do vetor: ";
        cin >> elem;
        lista.push_back(elem);
    }

    int rotacao;
    cout << "Digite quantas vezes o vetor ira se mover a direita: ";
    cin >> rotacao;

    for(int i = 0; i < rotacao; i++) {
        mover_direita(lista, rotacao);
        mostrar(lista);
    }
}