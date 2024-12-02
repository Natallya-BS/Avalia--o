#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Produto {
    int id;
    string nome;
    int quantidade; // Adicionado para controlar o estoque
    float preco;
};

// Função para exibir o menu
void exibirMenu() {
    cout << "\n===== Menu =====" << endl;
    cout << "1. Cadastrar Produto" << endl;
    cout << "2. Consultar Produtos" << endl;
    cout << "3. Vender Produto" << endl;
    cout << "4. Sair" << endl;
    cout << "Escolha uma opcao: ";
}

// Função para cadastrar um produto
void cadastrarProduto(vector<Produto>& produtos) {
    Produto produto;
    cout << "\nDigite o ID do produto: ";
    cin >> produto.id;
    cin.ignore(); // Limpar o buffer
    cout << "Digite o nome do produto: ";
    getline(cin, produto.nome);
    cout << "Digite a quantidade do produto: ";
    cin >> produto.quantidade;
    cout << "Digite o preço do produto: ";
    cin >> produto.preco;

    produtos.push_back(produto);
    cout << "Produto cadastrado com sucesso!" << endl;
}

// Função para vender um produto
void venderProduto(vector<Produto>& produtos) {
    if (produtos.empty()) {
        cout << "\nNenhum produto disponível para venda!" << endl;
        return;
    }

    int id, quantidadeVenda;
    cout << "\nDigite o ID do produto a vender: ";
    cin >> id;

    bool encontrado = false;
    for (auto& produto : produtos) {
        if (produto.id == id) {
            encontrado = true;
            cout << "Quantidade disponível de '" << produto.nome << "': " << produto.quantidade << endl;
            cout << "Digite a quantidade a vender: ";
            cin >> quantidadeVenda;

            if (quantidadeVenda > produto.quantidade) {
                cout << "Erro: Quantidade insuficiente em estoque." << endl;
            } else {
                produto.quantidade -= quantidadeVenda;
                cout << "Venda concluída! Quantidade restante de '" << produto.nome << "': " << produto.quantidade << endl;
            }
            break;
        }
    }

    if (!encontrado) {
        cout << "Produto com ID " << id << " não encontrado." << endl;
    }
}

// Função para consultar produtos
void consultarProdutos(const vector<Produto>& produtos) {
    if (produtos.empty()) {
        cout << "\nNenhum produto cadastrado!" << endl;
        return;
    }

    cout << "\n===== Lista de Produtos =====" << endl;
    for (const auto& produto : produtos) {
        cout << "ID: " << produto.id
             << ", Nome: " << produto.nome
             << ", Quantidade: " << produto.quantidade
             << ", Preço: R$ " << produto.preco << endl;
    }
}

int main() {
    vector<Produto> produtos;
    int opcao;

    do {
        exibirMenu();
        cin >> opcao;

        switch (opcao) {
            case 1:
                cadastrarProduto(produtos);
                break;
            case 2:
                consultarProdutos(produtos);
                break;
            case 3:
                venderProduto(produtos);
                break;
            case 4:
                cout << "Saindo do programa..." << endl;
                break;
            default:
                cout << "Opcao inválida! Tente novamente." << endl;
        }
    } while (opcao != 4);

    return 0;
}
