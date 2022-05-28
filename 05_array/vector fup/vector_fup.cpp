#include <iostream>
#include <sstream>

using namespace std;

struct Vector{
    int capacidade;
    int tamanho;
    int * data;
};

Vector * construtor(int capacidade) {
    Vector * vetor = new (Vector);
    vetor->data = new int [capacidade];
    vetor->tamanho = 0;
    vetor->capacidade = capacidade;

    return vetor; 
}

void destrutor(Vector * vector) {
    delete[] vector->data;
    delete[] vector;
}

void adicionar(Vector * vector, int valor) {
    if (vector->tamanho < vector->capacidade) {
        vector->data[vector->tamanho] = valor;
        vector->tamanho++;
    }
}

string mostrar(Vector * vector) {
    stringstream ss;
    ss << '[';

    for (int i = 0; i < vector->tamanho; i++) {
        ss << " " << vector->data[i];
    }

    ss << " ]";

    return ss.str();
}

int main(){
    string linha, comando;
    int valor {};
    Vector * vetor = construtor(4);

    while(true) {
        getline(cin, linha);
        stringstream ss(linha);
        cin >> comando;

        if(comando == "end") {
            break;
        } else if(comando == "remover"){
            ss >> valor;

            if(vetor != nullptr)
                destrutor(vetor);

            vetor = construtor(valor);
        } else if(comando == "status"){
            cout << "Tamanho: " << vetor->tamanho << " || Capacidade:" << vetor->capacidade << endl;
        } else if(comando == "adicionar"){
            while(ss >> valor)
                adicionar(vetor, valor);
        } else if (comando == "mostrar") {
            cout << mostrar(vetor) << endl;
        } else {
            cout << "Comando invalido!!!" << endl;
        }
    }

    destrutor(vetor);
}