#include <iostream>
#include <sstream>
using namespace std;

struct Vector {
    int capacidade {4};
    int tamanho {0};
    int * data {nullptr};

    Vector(int capacidade) : capacidade(capacidade) {
        this->data = new int[capacidade];
    }

    ~Vector() {
        delete[] this->data;
    }

    void operator = (const Vector& other){
        this->capacidade = other.capacidade;
        this->tamanho = other.tamanho;

        if(this->data != nullptr) {
            delete[] this->data;
        }

        this->data = new int[other.capacidade];

        for(int i = 0; i < other.capacidade; i++) {
            this->data[i] = other.data[i];
        }
    }

    Vector(Vector& other) {
        *this = other;
    }

    void adicionar(int valor) {
        if(this->tamanho < this->capacidade) {
            this->data[this->tamanho] = valor;
            tamanho++;
        }
    }

    friend ostream& operator<<(ostream &os, Vector vector){
        os << "[ ";

        for(int i = 0; i < vector.tamanho; i++)
            os << vector.data[i] << " ";

        os << "]";
        
        return os;
    }
};

int main(){
    string linha, comando;
    int valor{};
    Vector vetor(4);

    while(true){
        getline(cin, linha);
        stringstream ss(linha);
        cin >> comando;

        if(comando == "end") {
            break;
        } else if (comando == "remover") {
            ss >> valor;
            vetor = Vector(valor);
        } else if (comando == "status") {
            cout << "Tamanho: " << vetor.tamanho << " || Capacidade: " << vetor.capacidade << endl;
        } else if (comando == "adicionar") {
            while(ss >> valor)
                vetor.adicionar(valor);
        } else if(comando == "mostrar") {
            cout << vetor << endl;
        } else {
            cout << "Comando invalido!!!" << endl;
        }
    }
}