#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Fila {
    stack<int> deposito;
    stack<int> prateleira;
};

int main() {
    int tamanho, q;

    cin >> tamanho >> q;
    vector<Fila>filas(tamanho);

    for(int i = 0; i < q; i++) {
        int f, c;
        cin >> f >> c;
        filas[f].deposito.push(c);
    }

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int f, c;
        cin >> f >> c;
        filas[f].prateleira.push(c);
    }

    int j;
    cin >> j;
    
    int contador{};

    for(int i = 0; i < j; i++) {
        int f, c;
        cin >> f >> c;

        while(!filas[f].deposito.empty()) {
            if(filas[f].deposito.top() == c) {
                filas[f].deposito.pop();
                contador++;
                break;
            } else
                filas[f].deposito.pop();
        }
    }

    cout << contador;
}