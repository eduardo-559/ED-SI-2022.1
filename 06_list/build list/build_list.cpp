#include <iostream>
#include <sstream>

using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int data = 0, Node *next = nullptr) : data(data), next(next) {}
};

struct List {
    Node *head {nullptr};
    int tamanho {};

    List() {}

    ~List() {
        destrutor(head);
    }

    bool vazio() {
        return head == nullptr;
    }
    
    void destrutor(Node * node) {
        if(vazio())
            return;
        
        destrutor(node->next);
        delete(node);
    }

    void push_back(int valor) {
        if(vazio()) {
            this->head = new Node(valor);
            return;
        }

        auto node = this->head;

        while(node->next != nullptr) 
            node = node->next;

        node->next = new Node(valor);
        this->tamanho++;
    }

    void push_front(int valor) {
        auto node = new Node(valor);
        node->next = this->head;
        this->head = node;
        this->tamanho++;
    }

    Node * __pop_back(Node * node) {
        if (node->next == nullptr) {
            delete node;
            return nullptr;
        }
        
        node->next = __pop_back(node->next);

        return node;
    }

    void pop_back() {
        head = __pop_back(head);
    }

    void pop_front() {
        if (vazio())
            return;

        auto node = head;
        head = head->next;
        delete node;
        this->tamanho--;
    }

    int size() {
        return this->tamanho;
    }

    friend ostream& operator<<(ostream& os, List& list) {
        os << "[ ";
        
        auto node = list.head;

        while(node != nullptr) {
            os << node->data << " ";
            node = node->next;
        }

        os << "]" << endl;

        return os;
    }
};

int main () {
    List list;

    while (true) {
        string linha, comando;
        int valor;

        getline(cin, linha);

        stringstream ss(linha);
        cin >> comando;

        if(comando == "end")
            break;
        else if(comando == "show")
            cout << list << endl;
        else if(comando == "push_back") {
            while(ss >> valor)
                list.push_back(valor);
        } else if (comando == "push_front") {
            while(ss >> valor)
                list.push_front(valor);
        } else if (comando == "pop_back")
            list.pop_back();
        else if(comando == "pop_front")
            list.pop_front();
        else if(comando == "size")
            cout << list.size() << endl;
    }
}