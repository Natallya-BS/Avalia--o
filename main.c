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
// Função de cadastro do produto 

void cadastrarProduto(vector<Produto>& produtos) {
    Produto produto;
    cout << "\nDigite o ID do produto: ";
    cin >> produto.id;
    cin.ignore(); // Limpar o buffer
    cout << "Digite o nome do produto: ";
    getline(cin, produto.nome);
    cout << "Digite o preço do produto: ";
    cin >> produto.preco;

    produtos.push_back(produto);
    cout << "Produto cadastrado com sucesso!" << endl;
}
