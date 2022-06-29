#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <time.h>
#include <unistd.h>

using namespace std;

struct Pos {
    int linha;
    int coluna;
    Pos(int linha, int coluna) : linha(linha), coluna(coluna) {};
};

void mostrar(vector<string> floresta) {
    for(auto elem : floresta)
        cout << elem << endl;
}

vector<Pos> vizinhos(Pos posicao) {
    return {{posicao.linha, posicao.coluna - 1}, {posicao.linha - 1, posicao.coluna}, {posicao.linha, posicao.coluna + 1}, {posicao.linha + 1, posicao.coluna}};
}

vector<Pos> verificar(vector<Pos> vizinho, vector<string> floresta) {
    vector<Pos> pode_queimar;
    int num_linhas = floresta.size();
    int num_colunas = floresta[0].size();

    for(int i = 0; i < (int) vizinho.size(); i++) {
        if(vizinho[i].linha < 0 || vizinho[i].linha >= num_linhas || vizinho[i].coluna < 0 || vizinho[i].coluna >= num_colunas)
            continue;

        if(floresta[vizinho[i].linha][vizinho[i].coluna] != '#')
            continue;

        pode_queimar.push_back(vizinho[i]);
    }

    return pode_queimar;
}

void queimar(vector<string>& floresta, Pos pos) {
    srand(time(NULL));

    if(floresta[pos.linha][pos.coluna] != '#')
        return;

    floresta[pos.linha][pos.coluna] = 'o';

    stack<Pos> pilha;
    pilha.push(pos);

    while(!pilha.empty()) {
        vector<Pos> pode_queimar{verificar(vizinhos(pilha.top()), floresta)};

        if(pode_queimar.empty())
            pilha.pop();
        else {
            int proximo{rand() % pode_queimar.size()};
            floresta[pode_queimar[proximo].linha][pode_queimar[proximo].coluna] = 'o';
            pilha.push(pode_queimar[proximo]);
        }
    }    
}

int main() {
    int num_linhas {}, num_colunas {}, linha_inicio {}, coluna_inicio {};
    cin >> num_linhas >> num_colunas >> linha_inicio >> coluna_inicio;

    vector<string> floresta;

    for(int i = 0; i < num_linhas; i++) {
        string linha;
        cin >> linha;
        floresta.push_back(linha);
    }

    queimar(floresta, Pos(linha_inicio, coluna_inicio));
    mostrar(floresta);
}