#include <iostream>
#include <list>

using namespace std;

void mostrar(list<int>& lista, int machado) {
    cout << "[ ";

    for(auto i = lista.begin(); i != lista.end(); i++) {
        if (*i > 0 && *i == machado)
            cout << *i << "> ";
        else if(*i < 0 && *i == (-machado))
            cout << "<" << *i << " ";
        else
            cout << *i << " ";
    }

    cout << "]" << endl;
}

void matar(list<int>& lista, int machado) {
    auto i = lista.begin();

    while(*i != machado)
        i++;

    if(i == lista.end() && *i > 0)
        lista.front();
    else if(i == lista.begin() && *i < 0)
        lista.pop_back();
    else if(*i > 0)
        lista.remove(*next(i));
    else if(*i < 0)
        lista.remove(*prev(i));
}

void inicializar(list<int>& lista, int tamanho, int sinal) {
    for(int i = 0; i < tamanho; i++) {
        lista.push_back((i + 1) * sinal);
        sinal *= -1;
    }
}

int main() {
    int tamanho {}, machado {}, sinal {};

    cout << "Digite quantas pessoas ira participar: ";
    cin >> tamanho;

    cout << "Digite com quem ira comecar o machado";
    cin >> machado;

    cout << "Digite o sinal: ";
    cin >> sinal;

    list<int> lista;

    inicializar(lista, tamanho, sinal);
    mostrar(lista, machado);

    while(lista.size() > 1){
        matar(lista, machado);
        machado = (machado + 1) % lista.size();
        mostrar(lista, machado);
    }
}