#include <iostream>
#include <vector>

using namespace  std;

void mostrar(vector<string>& labirinto) {
    for(auto elem : labirinto) {  
        cout << elem << endl;
    }
}

void verificar(vector<string>& labirinto, pair<int, int>& inicio, pair<int, int>& final) {
    for (int linha = 0; linha < int (labirinto.size() - 1); linha++) {
        for (int coluna = 0; coluna < int (labirinto[0].size() - 1); coluna++) {
            if (labirinto[linha][coluna] == 'I') {
                labirinto[linha][coluna] = '_';
                inicio.first = linha;
                inicio.second = coluna;
            }

            if (labirinto[linha][coluna] == 'F') {
                labirinto[linha][coluna] = '_';
                final.first = linha;
                final.second = coluna;
            }
        }
    }
}

bool resolver(vector<string>& labirinto, int pos_linha, int pos_coluna, pair<int, int>& final) {
    int num_linha = labirinto.size();
    int num_coluna = labirinto[0].size();

    if(pos_linha >= num_linha || pos_coluna >= num_coluna || pos_linha < 0 || pos_coluna < 0) 
        return false;
    else if(labirinto[pos_linha][pos_coluna] == '#' || labirinto[pos_linha][pos_coluna] == '.')
        return false;
    else if(pos_linha == final.first && pos_coluna == final.second) {
        labirinto[pos_linha][pos_coluna] = '.';
        return true;
    }

    labirinto[pos_linha][pos_coluna] = '.';

    if(resolver(labirinto, pos_linha, pos_coluna - 1, final)) {
        labirinto[pos_linha][pos_coluna] = '.';
        return true;
    }

    if(resolver(labirinto, pos_linha + 1, pos_coluna, final)) {
        labirinto[pos_linha][pos_coluna] = '.';
        return true;
    }

    if(resolver(labirinto, pos_linha, pos_coluna + 1, final)) {
        labirinto[pos_linha][pos_coluna] = '.';
        return true;
    }

    if(resolver(labirinto, pos_linha - 1, pos_coluna, final)) {
        labirinto[pos_linha][pos_coluna] = '.';
        return true;
    }

    labirinto[pos_linha][pos_coluna] = '_';
    return false;
}

int main() {
    int num_linha {}, num_coluna {};

    auto inicio = make_pair(0,0);
    auto final = make_pair(0,0);

    cout << "Digite o numero de linhas: ";
    cin >> num_linha;

    cout << "Digite o numero de colunas: ";
    cin >> num_coluna;

    cin.ignore();

    vector<string> labirinto(num_linha);

    for(int linha = 0; linha < num_linha; linha++) {
        cout << "Elemento " << linha << " da linha: ";
        cin >> labirinto[linha];
    }

    verificar(labirinto, inicio, final);
    resolver(labirinto, inicio.first, inicio.second, final);

    mostrar(labirinto);
}