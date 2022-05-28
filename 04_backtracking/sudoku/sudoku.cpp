#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

void mostrar(const vector<vector<int>>& vetor) {
    for(auto& linha : vetor) {
        cout << "[ ";
        
        for (auto& elemento : linha) {
            cout << elemento << " ";
        }
        
        cout << "]" << endl;
    }
}

bool validar_posicao(int linha, int coluna, int tamanho) {  
    if (linha >= 0 && coluna >= 0 && linha < tamanho && coluna < tamanho) {
        return true;
    }

    return false;
}

bool validar_elemento(const vector<vector<int>>& quadro, int linha, int coluna) {
    int tamanho = quadro.size();
    int valor = quadro[linha][coluna];  

    for(int index = 0; index < tamanho; index++) {
        if (index != linha && index != coluna && (quadro[index][coluna] == valor || quadro[linha][index] == valor)) {
            return false;
        }
    }

    return true;
}

bool validar_numero(const vector<vector<int>>& quadro, int linha, int coluna) {
    int tamanho = quadro.size();
    int valor = quadro[linha][coluna];
    int tamanho_quadrante = sqrt(tamanho);
    int inicio_linha = linha - (linha % tamanho_quadrante);
    int inicio_coluna = coluna - (coluna % tamanho_quadrante);

    for(int i = inicio_linha; i < inicio_linha + tamanho_quadrante; i++) {
        for(int j = inicio_coluna; j < inicio_coluna + tamanho_quadrante; j++) {
            if (i != linha && j != coluna && quadro[i][j] == valor) {
                return false;
            }
        }
    }

    return true;
}

pair<int, int> proximo(int linha, int coluna, int tamanho) {
    if (coluna == tamanho - 1) {
        return {linha + 1, 0};
    }
    
    return {linha, coluna + 1};
}

bool resolver(vector<vector<int>>& quadro, int linha, int coluna) {
    static vector<int> valores = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int tamanho = quadro.size();

    if(linha == tamanho || coluna == tamanho)
        return true;
    else if(!validar_posicao(linha, coluna, tamanho))
        return false;
    
    random_shuffle(valores.begin(), valores.end());

    for(auto escolha : valores) {
        quadro[linha][coluna] = escolha;
        
        if (!validar_elemento(quadro, linha, coluna) || !validar_numero(quadro, linha, coluna)) {
            quadro[linha][coluna] = 0;
            continue;
        }
        
        auto [prox_l, prox_c] = proximo(linha, coluna, tamanho);

        if (resolver(quadro, prox_l, prox_c)) {
            return true;
        }
    }

    return false;
}

vector<vector<int>> sudoku(int tamanho) {
    vector<vector<int>> resultado(tamanho, vector<int>(tamanho, 0));
    resolver(resultado, 0, 0);

    return resultado;
}

int main() {
    srand(time(0));

    auto resolucao = sudoku(4);

    mostrar(resolucao);
}