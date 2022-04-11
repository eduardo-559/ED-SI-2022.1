#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

bool existe(vector<int> fila, int x){
    for(int i = 0; i < (int) fila.size(); i++){
        if(fila[i] == x)
            return true;
    }

    return false;
}

int contar(vector<int> fila, int x){
    int contador {0};

    for(int i = 0; i < (int) fila.size(); i++){
        if(fila[i] == x)
            contador++;
    }

    return contador;
}

int procurar_valor(vector<int> fila, int x){
    for(int i = 0; i < (int) fila.size(); i++){
        if(fila[i] == x)
            return i;
    }

    return -1;
}

int procurar_valor_apartir(vector<int> fila, int x, int inicio){
    for(int i = inicio; i < (int) fila.size(); i++){
        if(fila[i] == x)
            return i;
    }

    return -1;
}

int procura_menor(vector<int> fila){
    int menor {fila[0]};

    for(int i = 0; i < (int) fila.size(); i++){
        if(fila[i] < menor)
            menor = fila[i];
    }

    return menor;
}

int procurar_menor_pos(vector<int> fila){
    int menor {fila[0]}, posicao {0};

    for(int i = 0; i < (int) fila.size(); i++){
        if(fila[i] < menor){
            menor = fila[i];
            posicao = i;
        }
    }

    return posicao;
}

int procurar_menor_pos_apartir(vector<int> fila, int inicio){
    int menor {fila[inicio]}, posicao {inicio};

    for(int i = inicio; i < (int) fila.size(); i++){
        if(fila[i] < menor){
            menor = fila[i];
            posicao = i;
        }
    }

    return posicao;
}

int procurar_melhor_se(vector<int> fila){
    int menor {fila[0]}, homen_calmo {-1};

    for(int i = 0; i < (int) fila.size(); i++){
        if((fila[i] < menor) && fila[i] > 0){
            menor = fila[i];
            homen_calmo = i;
        }
    }

    return homen_calmo;
}

float calcular_stress_medio(vector<int> fila){
    float soma {0};
    for(int i = 0; i < (int) fila.size(); i++){
        soma += abs(fila[i]);
    }

    return soma / fila.size();
}

string mais_homens_ou_mulheres(vector<int> fila){
    int conta_homem {0}, conta_mulher {0};

    for(int i = 0; i < (int) fila.size(); i++){
        if(fila[i] > 0)
            conta_homem++;
        else
            conta_mulher++;
    }

    if(conta_homem > conta_mulher)
        return "homens";
    
    if(conta_homem < conta_mulher)
        return "mulheres";
    
    return "empate";
}

string qual_metade_eh_mais_estressada(vector<int> fila){
    int soma_homem {0}, soma_mulher {0};

    for(int i = 0; i < (int) fila.size(); i++){
        if(fila[i] > 0)
            soma_homem += fila[i];
        if(fila[i] < 0)
            soma_mulher += abs(fila[i]);
    }

    if(soma_homem > soma_mulher)
        return "homens";

    if(soma_homem < soma_mulher)
        return "mulheres";

    return "empate";
}

int main(){
    vector <int> fila {5, 3, -1, -50, -1, -99};
    cout << existe(fila, 4) << endl;
    cout << contar(fila, 1) << endl;
    cout << procurar_valor(fila, 6) << endl;
    cout << procurar_valor_apartir(fila, 1, 2) << endl;
    cout << procura_menor(fila) << endl;
    cout << procurar_menor_pos(fila) << endl;
    cout << procurar_menor_pos_apartir(fila, 3) << endl;
    cout << procurar_melhor_se(fila) << endl;
    cout << calcular_stress_medio(fila) << endl;
    cout << mais_homens_ou_mulheres(fila) << endl;
    cout << qual_metade_eh_mais_estressada(fila) << endl;

    return 0;
}