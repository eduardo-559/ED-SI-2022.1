#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;

struct Pos{
    int linha, coluna;

    Pos(int linha, int coluna) : linha(linha), coluna(coluna) {}

    bool operator==(Pos pos) {
        if(pos.linha == this->linha && pos.coluna == this->coluna)
            return true;
        
        return false;
    }
};

void mostrar(vector<string>& matriz) {
    for(auto elem : matriz)
        cout << elem << endl;
}

vector<Pos> pegar_vizinhos(Pos pos) {
    auto [linha, coluna] = pos;

    return {{linha, coluna - 1}, {linha - 1, coluna}, {linha, coluna + 1}, {linha + 1, coluna}};
}

void inicio_fim(vector<string>& matriz, Pos& inicio, Pos& fim) {
    for(int i = 0; i < (int) (matriz.size() - 1); i++) {
        for (int j = 0; j < (int) (matriz[0].size() - 1); j++) {
            if(matriz[i][j] == 'I') {
                matriz[i][j] = ' ';
                inicio.linha = i;
                inicio.coluna = j;
            }

            if(matriz[i][j] == 'F') {
                matriz[i][j] = ' ';
                fim.linha = i;
                fim.coluna = j;
            }
        }
    }
}

void avancar(vector<string>& matriz, Pos& inicio, Pos& fim) {
    int num_linhas = matriz.size();
    int num_colunas = matriz[0].size();

    auto [linha,coluna] = inicio;

    stack<Pos> pos_caminho;
    stack<list<Pos>> neigs;

    matriz[linha][coluna] = '.';
    pos_caminho.push(inicio);

    while(pos_caminho.empty() != true) {
        list<Pos> vizinhos {};
        
        if(pos_caminho.top() == fim)
            return;

        for(auto elem : pegar_vizinhos(pos_caminho.top())) {
            if(elem.linha >= num_linhas || elem.coluna >= num_colunas || elem.linha < 0 || elem.coluna < 0)
                continue;
            else if (matriz[elem.linha][elem.coluna] == ' ') {
                vizinhos.push_back(elem);
            }
        }
        
        if(vizinhos.empty()) {
            matriz[pos_caminho.top().linha][pos_caminho.top().coluna] = ' ';
            pos_caminho.pop();

            while(neigs.top().empty() == true) {
                neigs.pop();
                matriz[pos_caminho.top().linha][pos_caminho.top().coluna] = ' ';
                pos_caminho.pop();
            }
            
            pos_caminho.push(neigs.top().back());
            neigs.top().pop_back();
            matriz[pos_caminho.top().linha][pos_caminho.top().coluna] = '.';
        } else {
            pos_caminho.push(vizinhos.back());
            vizinhos.pop_back();
            neigs.push(vizinhos);
            matriz[pos_caminho.top().linha][pos_caminho.top().coluna] = '.';
        }

        mostrar(matriz);
        getchar();
    }
}

int main() {
    int num_linhas, num_colunas;

    cin >> num_linhas >> num_colunas;
    cin.ignore();

    vector<string> matriz(num_linhas);

    for(int i = 0; i < num_linhas; i++)
        getline(cin, matriz[i]);

    Pos inicio(0, 0);
    Pos fim(0, 0);

    inicio_fim(matriz, inicio, fim);
    avancar(matriz, inicio, fim);
    mostrar(matriz);
}