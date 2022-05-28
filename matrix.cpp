#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

struct Pos {
    int linha {}, coluna {};
    Pos(int linha, int coluna) {} 
    bool operator == (Pos pos) {}
    bool operator != (Pos pos) {}
    string str() {}
};

ostream &operator<<(ostream& os, Pos pos) {
    return os << pos.str();
}

template <class T>

class matrix {
    int num_linha {}, num_coluna {};
    vector<vector<T>> data;

public:
    matrix(int num_linha, int num_coluna) {}
    matrix(int num_linha, int num_coluna, T def) {} 

    int n_linhas() {}
    int n_colunas() {}

    T& elem(Pos pos) {}
    T& operator[] (Pos pos) {}

    vector<T>& operator[] (int linha) {}

    bool verificar_pos(Pos pos) {}
    bool existe_pos(Pos pos, char valor) {}

    string str() {}
};

template <>
string matrix<char>::str() {}

template <class T>
ostream& operator<<(ostream& os, matrix<T>& matriz) {
    return os << matriz.str();
}

int main() {
    {
        matrix<int> matriz(3, 4, 5);
        cout << matriz;
    }

    {
        matrix<char> matriz(3, 4, 'a');
        cout << matriz;
    }

    {
        matrix<int> matriz(3, 4);

        matriz[0][0] = 1;
        matriz[{2, 2}] = 2;

        cout << matriz;
        cout << matriz.verificar_pos({-1, 2}) << endl;
        cout << matriz.existe_pos({2, 2}, 2) << endl;
        cout << matriz.existe_pos({-1, 2}, 0) << endl;
    }

}