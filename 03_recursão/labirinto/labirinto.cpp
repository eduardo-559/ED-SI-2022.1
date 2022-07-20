#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void mostrar(vector<string> labirinto) {
    for(auto elem : labirinto){
        cout << elem << endl;
    }
}

void andar(vector<string>& labirinto, int nl, int nc) {
    int nl_max = labirinto.size();
    int nc_max = labirinto[0].size();
    
    if(nl < 0 || nl >= nl_max || nc < 0 || nc >= nc_max)
        return;
        
    if(labirinto[nl][nc] != '_')
        return;

    labirinto[nl][nc] = '.';
    mostrar(labirinto);
    getchar();

    andar(labirinto, nl, nc - 1);
    andar(labirinto, nl - 1, nc);
    andar(labirinto, nl, nc + 1);
    andar(labirinto, nl + 1, nc);
}

int main(){
    ifstream entrada("entrada.txt");
    int nl{}, nc{}, li{}, ci{};
    
    entrada >> nl >> nc;
    vector<string> labirinto;
    
    for(int i = 0; i < nl; i++){
        string linha;
        entrada >> linha;
        labirinto.push_back(linha);
    }
    
    mostrar(labirinto);

    cout << "Linha: ";
    cin >> li;

    cout << "Coluna: ";
    cin >> ci;

    cin.ignore();

    andar(labirinto, li, ci);
}
