#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Pos {
    int linha, coluna;

    Pos(int linha, int coluna) : linha(linha), coluna(coluna) {}

    bool operator==(Pos x) {
        if(x.linha == this->linha && x.coluna == this->coluna)
            return true;
        
        return false;
    }
};

void mostrar(vector<string>& labirinto) {
    for(auto elem : labirinto)
        cout << elem << endl;
}

vector<Pos> vizinhos(Pos pos) {
    auto [linha, coluna] = pos;
    return {{linha, coluna - 1}, {linha - 1, coluna}, {linha, coluna + 1}, {linha + 1, coluna}};
}

void inicio_fim(vector<string>& labirinto, Pos& inicio, Pos& final) {
    for(int i = 0; i < (int) (labirinto.size() - 1); i++) {
        for(int j = 0; j < (int) (labirinto[0].size() - 1); j++) {
            if(labirinto[i][j] == 'I') {
                labirinto[i][j] = ' ';
                inicio.linha = i;
                inicio.coluna = j;
            }

            if(labirinto[i][j] == 'F') {
                labirinto[i][j] = ' ';
                final.linha = i;
                final.coluna = j;
            }
        }
    }
}

void procurar_saida(vector<string>& labirinto, vector<vector<int>>& distancia, Pos& inicio, Pos& final) {
    bool verificar_achou {false};
    int num_linha {labirinto.size()};
    int num_coluna {labirinto[0].size()};

    queue<Pos> fila {};
    fila.push(inicio);
    distancia[inicio.linha][inicio.coluna] = 0;

    while(!verificar_achou) {
        Pos posicao_atual = fila.front();
        
        for(auto elem : vizinhos(posicao_atual)) {
            if (elem.linha < 0 || elem.coluna < 0 || elem.linha >= num_linha || elem.coluna >= num_coluna)
                continue;
            else if (labirinto[elem.linha][elem.coluna] == ' ' && distancia[elem.linha][elem.coluna] == -1) {
                distancia[elem.linha][elem.coluna] = distancia[posicao_atual.linha][posicao_atual.coluna] + 1;
                fila.push(elem);

                if(elem == final)
                    verificar_achou = true;         
            }
        }
        
        fila.pop(); 
    }

    verificar_caminho(labirinto, distancia, inicio, final);
    mostrar(labirinto);
}

void verificar_caminho(vector<string>& labirinto, vector<vector<int>>& distancia, Pos& inicio, Pos& final) {
    bool verificar_achou {false};
    Pos posicao_atual {final};

    while(!verificar_achou) {
        for(auto elem : vizinhos(posicao_atual)) {
            if(distancia[elem.linha][elem.coluna] == distancia[posicao_atual.linha][posicao_atual.coluna] - 1) {
                labirinto[posicao_atual.linha][posicao_atual.coluna] = '.';
                posicao_atual = elem;
                
                if (elem == inicio)
                    verificar_achou = true;
            }
        }
    }
}

int main() {
    int num_linha, num_coluna;

    cin >> num_linha >> num_coluna;
    cin.ignore();

    vector<string> labirinto(num_linha);
    vector<vector<int>> distancia(num_linha, vector<int>(num_coluna, -1));
    
    for(int linha = 0; linha < num_linha; linha++)
        getline(cin, labirinto[linha]);
    
    Pos inicio(0, 0), final(0, 0);

    inicio_fim(labirinto, inicio, final);
    procurar_saida(labirinto, distancia, inicio, final);
}