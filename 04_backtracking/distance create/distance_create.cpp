#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

bool forma(string data, int limite, int index, char value) {
    int tamanho = data.size();
    int inicio = max(index - limite, 0);
    int final = min(index + limite + 1, tamanho);

    for(int i = inicio; i < final; i++) {
        if(data[i] == value)
            return false;
    }

    return true;
}

int proximo(string data, int index) {
    int size = data.size();

    for(int i = index + 1; i < size; i++) {
        if(data[i] == '_')
            return i;
    }

    return size;
}

char dig(int dig) {
    return dig + '0';
}

bool distance_create(string& data, int limite, int index) {
    if(index == (int) data.size())
        return true;

    if(data[index] != '_')
        distance_create(data, limite, index + 1);

    for(char value = '0'; value <= dig(limite); value++) {
        if(forma(data, limite, index, value)){
            data[index] = value;
            cout << data << endl;

            if(distance_create(data, limite, index + 1))
                return true;
        }
    }

    data[index] = '_';
    return false;
}

int main() {
    string sequencia;
    int limite{};
  
    cin >> sequencia;
    cin >> limite;

    distance_create(sequencia, limite, 0);
}