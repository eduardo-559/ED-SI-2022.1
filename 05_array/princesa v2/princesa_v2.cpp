#include <iostream>
#include <vector>

using namespace std;

ostream& operator<<(ostream& os, const vector<int>& fila) {
    os << "[";

    for(int i = 0; i < (int) fila.size(); i++) {
        os << fila[i];
        if (i != (int) fila.size() -1)
            os << ", ";
    }
;
    os << "]";
    return os;
}

void inicializar(vector<int>& fila, int sinal, int size) {
    if(sinal < 0) {
        int contador = 1;

        for (int i = 0; i < size; i++) {
            if (contador % 2 == 0)
                fila.push_back(contador);
            else
                fila.push_back(-contador);

            contador++;
        }
    } else {
        int contador = 1;

        for (int i = 0; i < size; i++) {
            if ((contador%2) == 0)
                fila.push_back(-contador);
            else
                fila.push_back(contador);

            contador++;
        }
    }
}

void mostrar(vector<int>& fila, int machado) {
    cout << "[";

    for (int i = 0; i < (int) fila.size(); i++) {
        if (i == machado && fila[i] > 0)
            cout << fila[i] << ">";
        else if (i == machado && fila[i] < 0)
            cout << "<" << fila[i];
        else
            cout << fila[i];
        if(i != (int) fila.size() -1)
            cout << ", ";
    }

    cout << " ]" << endl; 
}

void matar(vector<int>& fila, int posicao) {
    fila.erase(fila.begin() + posicao);
}

int main() 
{
    int tamanho{}, posicao{}, sinal{};

    cout << "Digite o tamanho: ";
    cin >> tamanho;

    cout << "Digite a posicao de quem vai iniciar com o machado: ";
    cin >> posicao;

    cout << "Digite o sinal: ";
    cin >> sinal;

    vector<int> fila;
    inicializar(fila, sinal, tamanho);
    posicao--;

    while((int) fila.size() != 1) {
        if(posicao < 0)
            posicao = (int)fila.size() - 1;

        mostrar(fila, posicao);
        posicao = posicao % (int)fila.size();

        if(fila[posicao] < 0) {
            if (posicao - 1 < 0) {
                matar(fila, (int)fila.size() - 1);
                posicao = (int)fila.size() - 1;
            } else {
                posicao--;
                matar(fila, posicao);
                posicao--;
                posicao = posicao % (int)fila.size();
            }
        } else {
            posicao++;
            posicao = posicao % (int)fila.size();
            matar(fila, posicao);    
        }
    }
    cout << fila;
}