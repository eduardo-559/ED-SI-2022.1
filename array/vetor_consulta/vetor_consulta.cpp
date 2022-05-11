#include <iostream>
#include <vector>

using namespace std;

ostream& operator<<(ostream& os, const vector<int>& vetor) {
    os << "[ ";
    for(int i = 0; i < (int) vetor.size(); i++) {
        os << vetor[i];
        if(i != (int) vetor.size() - 1) {
            os << ", ";
        }
    }  
    os << " ]";

    return os;
}

int conta_elementosr(vector<string> entrada, string sequencia) {
    int contador {};
    for(auto elem : entrada) {
        if(sequencia == elem)
            contador++;
    }

    return contador;
}

vector<int> verificar(vector<string> vetor, vector<string> consulta) {
    vector<int> vet;

    for(auto elem : consulta) {
        vet.push_back(conta_elementosr(vetor, elem));
    }

    return vet;
}

void inicializar(vector<string>& vetor, int tam) {
    for(int i = 0; i < tam; i++){
        string linha;
        cout << "Digite o elemento " << i << ": ";
        cin >> linha;
        vetor.push_back(linha);
    }
}

int main()
{
    int tam_vetor {};
    cout << "Digite o tamanho do vetor: ";
    cin >> tam_vetor;

    vector<string> vetor;
    vetor.reserve(tam_vetor);
    inicializar(vetor, tam_vetor);

    int tam_consulta {};
    cout << "Digite o tamanho do vetor de consulta: ";
    cin >> tam_consulta;

    vector<string> consulta;
    consulta.reserve(tam_consulta);
    inicializar(consulta, tam_consulta);

    vector<int> resultado {verificar(vetor, consulta)};
    cout << resultado << endl;

    return 0;
}