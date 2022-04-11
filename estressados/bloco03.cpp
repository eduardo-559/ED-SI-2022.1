#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

bool existe(vector<int> fila, int x){
    for(int i = 0; i < (int) fila.size(); i++){
        if(fila[i] == x)
            return true;
    }

    return false;
}

bool existe_apartir(const vector<int>& vet, int value, size_t pos) {
    for (size_t i{pos}; i < vet.size(); i++) {
        if (vet[i] == value)
            return true;
    }
    return false;
}

template <class... v_pack>
bool existe_algum_apartir(const vector<int>& vet, size_t pos, v_pack&& ...value) {
    vector<bool> flags;
    ((flags.push_back(existe_apartir(vet, value, pos))), ...);
    for (auto i : flags) {
        if (i) {
            return true;
        }
    }
    return false;
}

vector<int> sozinhos(const vector<int>& vet){
    vector<int> sozinho {};
    vector<int> seforam {};

    for (size_t i{0}; i < vet.size(); i++) {
        int elemento{(vet[i] < 0) ? -vet[i] : vet[i]};

        if (!existe(seforam, elemento)) {
            if (!existe_algum_apartir(vet, i+1, elemento, -elemento)) {
                sozinho.push_back(vet[i]);
            }

            seforam.push_back(elemento);   
        }
    }
    return sozinho;
}

int mais_ocorrencias(const vector<int>& vet) {
    int maior_ocorrencia{0};

    for (size_t i{0}; i < (int) vet.size(); i++) {
        int elem = (vet[i] < 0) ? -vet[i] : vet[i];
        int occur{1};

        for (size_t j{i + 1}; j < (int) vet.size(); j++) {
            int elem2 = (vet[j] < 0) ? -vet[j] : vet[j];

            if (elem == elem2) {
                occur++;
            }
        }

        if (occur > maior_ocorrencia) {
            maior_ocorrencia = occur;
        }
    }

    return maior_ocorrencia;
}

vector<int> mais_recorrentes(const vector<int>& vet) {
    int maior_ocorrencia{mais_ocorrencias(vet)};
    vector<int> recorrentes;

    for (size_t i{0}; i < (int) vet.size(); i++) {
        int elem = (vet[i] < 0) ? -vet[i] : vet[i];
        int occur{1};

        for (size_t j{i + 1}; j < (int) vet.size(); j++) {
            int elem2 = (vet[j] < 0) ? -vet[j] : vet[j];

            if (elem == elem2) {
                occur++;
            }
        }

        if (occur == maior_ocorrencia) {
            recorrentes.push_back(elem);
        }
    }

    return recorrentes;
}

int briga(const vector<int>& vet) {
    if (vet.empty()) {
        return 0;
    }

    int brigas{0};

    for (size_t i{1}; i < (int) vet.size() - 1; i++) {
        int elem{abs(vet[i])};
        int elem_esquerda{abs(vet[i - 1])};
        int elem_direita{abs(vet[i + 1])};

        if (elem > 50 && elem_esquerda > 30 && elem_direita > 30) {
            brigas++;
        }
    }

    return brigas;
}

vector<size_t> apaziguado(const vector<int>& vet) {
    if (vet.empty()) {
        return {};
    }
    
    vector<size_t> apaziguados;

    for (size_t i{0}; i < (int) vet.size(); i++) {
        int elem{abs(vet[i])};

        if (elem > 80) {
            if (i > 0 && i < vet.size() - 1) {
                if (std::abs(vet[i - 1] < 10 || std::abs(vet[i + 1]) < 10)) {
                    apaziguados.push_back(i);
                }
            } else if (i == 0 && std::abs(vet[i + 1])) {
                apaziguados.push_back(i);
            } else if (std::abs(vet[i - 1] < 10)) {
                    apaziguados.push_back(i);
            }
        }
    }

    return apaziguados;
}

int main(){
    vector <int> fila {83, -4, 65, 8, -99, 12};

    vector<int> sozinho = sozinhos(fila);
    for(int i = 0; i < (int) sozinho.size(); i++){
        cout << sozinho[i] << " ";
    }

    cout << endl;

    cout << mais_ocorrencias(fila) << endl;

    vector<int> recor = mais_recorrentes(fila);
    for(int i = 0; i < (int) recor.size(); i++){
        cout << recor[i] << " ";
    }

    cout << endl << briga(fila) << endl;

    vector<size_t> paz = apaziguado(fila);
    for(int i = 0; i < (int) paz.size(); i++){
        cout << paz[i] << " ";
    }

    return 0;
}