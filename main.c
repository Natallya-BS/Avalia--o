#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Produto {
    int id;
    string nome;
    float preco;
};

// Função menu

void exibirMenu() {
    cout << "\n===== Menu =====" << endl;
    cout << "1. Cadastrar Produto" << endl;
    cout << "2. Consultar Produtos" << endl;
    cout << "3. Sair" << endl;
    cout << "Escolha uma opção: ";
}
