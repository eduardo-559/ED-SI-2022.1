#include <iostream>
#include <vector>
#include <list>

using namespace std;

void mostrar(list<int>& lista, int machado) {
    cout << "[ ";

    for(auto i = lista.begin(); i != lista.end(); i++) {
        if (*i == machado)
            cout << *i << "> ";
        else
            cout << *i << " ";
    }

    cout << "]" << endl;
}

void matar(list<int>& lista, int machado) {
    auto i = lista.begin();

    while(*i != machado)
        i++;

    if(i == lista.end())
        lista.front();
    else
        lista.remove(*next(i));
}

int main() {
    int tamanho {}, machado {};

    cout << "Digite quantas pessoas ira participar: ";
    cin >> tamanho;

    cout << "Digite quem ira comecar com o machado: ";
    cin >> machado;

    list<int> lista;

    for(int i = 0; i < tamanho; i++)
        lista.push_back(i + 1);

    int auxiliar = lista.size();

    while(auxiliar > 1) {
        mostrar(lista, machado);
        matar(lista, machado);
        machado = (machado + 1) % tamanho;
        auxiliar--;
    }

    mostrar(lista, machado);
}