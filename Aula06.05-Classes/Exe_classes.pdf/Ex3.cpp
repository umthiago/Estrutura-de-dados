#include <iostream>
#include <string>
using namespace std;

class Produto {
private:
  string nome;
  double preco;
  int quantidadeEstoque;

public:
  Produto(string n, double p, int q) {
    nome = n;
    preco = p;
    quantidadeEstoque = q;
  }

  void venderProduto(int quantidade) {
    if (quantidade <= quantidadeEstoque && quantidade > 0) {
      quantidadeEstoque -= quantidade;
      cout << "Venda realizada. Estoque atual: " << quantidadeEstoque << endl;
    } else if(quantidade <= 0){
          cout << "Quantidade inválida." << endl;
    }
    else {
      cout << "Estoque insuficiente." << endl;
    }
  }

  void reporEstoque(int quantidade) {
    quantidadeEstoque += quantidade;
    cout << "Estoque reposto. Novo estoque: " << quantidadeEstoque << endl;
  }

  void exibirDados() {
    cout << "Nome: " << nome << endl;
    cout << "Preço: " << preco << endl;
    cout << "Quantidade em estoque: " << quantidadeEstoque << endl;
  }
};

int main() {
  Produto produto("Caneta", 2.50, 100);
  produto.exibirDados();

  produto.venderProduto(20);
  produto.exibirDados();

  produto.reporEstoque(50);
  produto.exibirDados();

    produto.venderProduto(150);
    produto.venderProduto(-10);

  return 0;
}
