#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

list<char> inicializar() {
    string linha {};
    getline(cin, linha);

    list<char> texto {};
    int contador {};

    for(auto i = linha.begin(); i != linha.end(); i++) {
        if(contador == 0) {
            if (*i == '<' || *i == '>' || *i == 'B' || *i == 'D') {
                texto.push_back('|');
                contador++;
            }
        }
         
        texto.push_back(*i);

        if ((i + 1) == linha.end()) {
            if (contador == 0) 
                texto.push_back('|');
            break;
        }
    }

    return texto;
}

void mostrar(list<char>& texto) {
    for(auto& elemento : texto)
        cout << elemento;
}

void editar(list<char>& texto) {
    auto cursor = texto.begin();
    int contador {};
    list<char> caracteres {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'x', 'y', 'w', 'z', '-'};

    for(auto i = texto.begin(); i != texto.end(); i++) {
        for(auto i = texto.begin(); i != texto.end(); i++) {
            if(*i == '|')
                cursor = i;
        }
        
        if(*i == 'R')
            *i = '\n';
        else if(*i == 'B') {
            if (*cursor != texto.front()) {
                cursor = texto.erase(--cursor);
                i = texto.erase(i);
                --i;
            } else {
                i = texto.erase(i);
                --i;
            }
        } else if (*i == 'D') {
            if (*cursor != texto.back()) {
                texto.erase(++cursor);
                i = texto.erase(i);
                --i;
            } else {
                i = texto.erase(i);
                --i;
            }
        } else if (*i == '>') {
            if(*cursor != texto.back()) {
                if(*(next(cursor)) == '>') {
                    while (i != prev(texto.end()))
                        i = texto.erase(i);
                    break;
                }
                
                auto elemento = ++cursor;
                cursor = texto.erase(cursor);
                texto.insert(--cursor, *elemento);
                i = texto.erase(i);
                --i;
                ++contador; 
            } else {
                i = texto.erase(i);
                --i;
            }
        } else if (*i == '<') {
            if(*cursor != texto.front()) {
                auto elemento = --cursor;
                cursor = texto.erase(cursor);
                texto.insert(++cursor, *elemento);
                i = texto.erase(i);
                --i;
                ++contador;
            } else {
                i = texto.erase(i);
                --i;
            }
        } else if (contador >= 1) {
            if (find(caracteres.begin(), caracteres.end(), *i) != caracteres.end()) {
                texto.insert(cursor, *i);
                i = texto.erase(i);
                --i;
            }
        }
    }

    mostrar(texto);
}

int main() {
    auto texto = inicializar();
    editar(texto);
}