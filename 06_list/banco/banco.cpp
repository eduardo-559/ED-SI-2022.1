#include <iostream>
#include <list>
#include <vector>
#include <sstream>

using namespace std;

struct Cliente {
    string id;
    int docs;
    int pac;

    Cliente(string id, int docs, int pac) : id(id), docs(docs), pac(pac) {}

    string str() {
        return id + ":" + to_string(docs) + ":" + to_string(pac); 
    }
};

class Banco {
private:
    vector<Cliente*> caixas {};
    list<Cliente*> fila_entrada {};
    list<Cliente*> fila_saida {};
    int docs_reservado {};
    int docs_perdido {};
    int tics {};
    int quantidade {};
    
public:
    Banco(int caixas) : caixas(caixas) {}

    void inserir(Cliente* cliente) {
        this->fila_entrada.push_back(cliente);
        ++quantidade;
    }

    bool verificar_vazio() {
        if(this->quantidade == 0)
            return true;

        return false;
    }

    void passar_tempo() {
        if(!this->fila_saida.empty()) {
            for(auto i = fila_saida.begin(); i != fila_saida.end(); i++) {
                this->docs_perdido += (*i)->docs;
                auto backup = i;
                i = this->fila_saida.erase(i);
                delete *backup;
            }
            --quantidade;
        }

        for(auto& elem : this->caixas) {
            if(elem != nullptr) {
                if (elem->docs > 0) {
                    --elem->docs;
                    this->docs_reservado++;
                } else {
                    auto pessoa = elem;
                    this->fila_saida.push_back(pessoa);
                    elem = nullptr;
                }
            } else {
                if (fila_entrada.empty())
                    break;
                
                elem = this->fila_entrada.front();
                this->fila_entrada.pop_front();
            }
        }

        if(!fila_entrada.empty()) {
            for(auto i = fila_entrada.begin(); i != fila_entrada.end(); i++) {
                if ((*i)->pac > 0)
                   (*i)->pac--;
                else {
                    auto pessoa = (*i);
                    fila_saida.push_back(pessoa);
                    i = fila_entrada.erase(i);
                }
            }
        }
        ++tics;
    }

    void mostrar() {
        for(auto& cliente : this->caixas)
            cout << "[" << (cliente == nullptr ? "" : cliente->str()) << "]";
        
        cout << "Inseridos: { ";
        
        for(auto &cliente : this->fila_entrada)
            cout << (cliente == nullptr ? " " : cliente->str()) << " ";
        
        cout << "}" << endl;
        
        cout <<  "nout:{ ";
        
        for(auto &cliente : this->fila_saida)
            cout << (cliente == nullptr ? " " : cliente->str()) << " ";
        
        cout << "}" << endl;
    }

    int get_recebido() {
        return this->docs_reservado;
    }

    int get_perdido() {
        return this->docs_perdido;
    }

    int get_tics() {
        return this->tics;
    }
};

int main() {
    Banco* banco;
    
    while(true) {
        string linha, comando;
        
        getline(cin, linha);
        stringstream ss(linha);
        ss >> comando;
        
        if(comando == "end")
            break;
        else if (comando == "iniciar") {
            int mostrar;
            ss >> mostrar;
            banco = new Banco(mostrar);
        } else if (comando == "mostrar")
            banco->mostrar();
        else if (comando == "inserir") {
            string nome;
            int docs, pacience;
            ss >> nome >> docs >> pacience;
            banco->inserir(new Cliente(nome, docs, pacience));
        } else if (comando == "tic")
            banco->passar_tempo();
        else if (comando == "status") {
            while (!banco->verificar_vazio())
                banco->passar_tempo();
            
            cout << "Documentos recebidos: " << banco->get_recebido() << endl;
            cout << "Documentos perdidos: " << banco->get_perdido() << endl;
            cout << "Tics: " << banco->get_tics() << endl;
        } else
            cout << "Comando Invalido!!!" << endl;
    }
}