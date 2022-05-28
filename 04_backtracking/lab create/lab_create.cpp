#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Posicao {
    int linha, coluna;
    Posicao(int linha, int coluna) : linha(linha), coluna(coluna) {}
};

void mostrar(vector<string>& labirinto) {
    for(auto elem : labirinto)
        cout << elem << endl;
}

Posicao definir_comeco(vector<string>& labirinto) {
    int pos_linha = rand() % (labirinto.size() - 2) + 1; 
    int pos_coluna = rand() % (labirinto[0].size() - 2) + 1;

    return {pos_linha, pos_coluna};
}

bool verificar_pos(vector<string>& labirinto, Posicao pos) {
    int num_linha = labirinto.size();
    int num_coluna = labirinto[0].size();
    auto [linha, coluna] = pos;
    
    if (linha >= num_linha - 1 || coluna >= num_coluna - 1 || linha < 1 || coluna < 1) 
        return false;

    return true;
}

vector<Posicao> pegar_vizinhos(const Posicao& pos) {
    auto [pos_linha, pos_coluna] = pos;
    return {{pos_linha, pos_coluna - 1}, {pos_linha + 1, pos_coluna}, {pos_linha, pos_coluna + 1}, {pos_linha - 1, pos_coluna}};
}

bool verificar_furar(vector<string>& labirinto, Posicao& pos) {
    int contador = 0;
    auto auxiliar = pegar_vizinhos(pos);

    if(labirinto[pos.linha][pos.coluna] == ' ')
        return false;

    for(auto [linha, coluna] : auxiliar) {
        if(linha >= int (labirinto.size()) || coluna >= int (labirinto[0].size()) || linha < 0 || coluna < 0)
            continue;

        if(labirinto[linha][coluna] == '#')
            contador++;
    }

    if(contador >= 3)
        return true;

    return false;
}

void eliminar_parede(vector<string>& labirinto, Posicao& pos) {
    auto [linha, coluna] = pos;
    
    if(!verificar_pos(labirinto, pos))
        return;
    
    if(verificar_furar(labirinto, pos)) {
        labirinto[linha][coluna] = ' ';
        auto vizinhos = pegar_vizinhos(pos);

        random_shuffle(vizinhos.begin(), vizinhos.end());

        for(auto elem : vizinhos)
            eliminar_parede(labirinto, elem);
    } 
}

int main() {
    int num_linhas {}, num_colunas{};

    cout << "Digite o numero de linhas: ";
    cin >> num_linhas;

    cout << "Digite o numero de colunas: ";
    cin >> num_colunas;

    vector<string> labirinto(num_linhas, string(num_colunas, '#'));

    auto inicio = definir_comeco(labirinto);

    eliminar_parede(labirinto, inicio);
    mostrar(labirinto);

    return 0;
}