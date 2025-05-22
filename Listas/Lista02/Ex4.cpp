Crie uma classe chamada Produto que represente itens em um estoque de loja.
Atributos privados:
string nome
int codigo
int quantidade
float preco
Atributo static:
static int totalProdutos; → contador de quantos objetos da classe foram criados.
Requisitos:
Construtor para inicializar todos os atributos.
Métodos:
void entradaEstoque(int qtd) → adiciona itens ao estoque
bool saidaEstoque(int qtd) → remove itens, mas retorna false se não houver estoque suficiente
float calcularValorTotal() → retorna o valor total do estoque do produto (quantidade × preço)
static int getTotalProdutos() → retorna a quantidade total de produtos criados
No programa principal:
Crie três objetos Produto diferentes.
Faça entradas e saídas de estoque em cada um.
Exiba o valor total de cada item em estoque.
Mostre quantos produtos foram criados ao final usando o método getTotalProdutos().


#include <iostream>
#include <string>
using namespace std;

class Produto {
private:
    string nome;
    int codigo;
    int quantidade;
    float preco;

    // Atributo estático
    static int totalProdutos;

public:
    // Construtor
    Produto(string n, int c, int q, float p) {
        nome = n;
        codigo = c;
        quantidade = q;
        preco = p;
        totalProdutos++; // Incrementa quando um produto é criado
    }

    // Método para entrada no estoque
    void entradaEstoque(int qtd) {
        quantidade += qtd;
    }

    // Método para saída do estoque
    bool saidaEstoque(int qtd) {
        if (quantidade >= qtd) {
            quantidade -= qtd;
            return true;
        } else {
            cout << "Estoque insuficiente para " << nome << endl;
            return false;
        }
    }

    // Calcula valor total em estoque
    float calcularValorTotal() const {
        return quantidade * preco;
    }

    // Mostra dados do produto
    void exibir() const {
        cout << "Produto: " << nome 
             << " | Codigo: " << codigo
             << " | Quantidade: " << quantidade
             << " | Preco: R$ " << preco << endl;
    }

    // Método estático para pegar total de produtos criados
    static int getTotalProdutos() {
        return totalProdutos;
    }
};

// Inicializa o atributo estático
int Produto::totalProdutos = 0;

// Programa principal
int main() {
    // Cria três produtos
    Produto prod1("Camiseta", 101, 10, 50.0);
    Produto prod2("Calca Jeans", 102, 5, 120.0);
    Produto prod3("Tenis", 103, 8, 250.0);

    // Entrada de estoque
    prod1.entradaEstoque(5);    // +5 Camisetas
    prod2.entradaEstoque(2);    // +2 Calcas
    prod3.entradaEstoque(3);    // +3 Tenis

    // Saída de estoque
    prod1.saidaEstoque(3);      // -3 Camisetas
    prod2.saidaEstoque(1);      // -1 Calca
    prod3.saidaEstoque(10);     // tentativa inválida (excede o estoque)

    // Exibe informações e valores totais
    cout << "\n--- Estoque Atual ---\n";
    prod1.exibir();
    cout << "Valor total em estoque: R$ " << prod1.calcularValorTotal() << endl;

    prod2.exibir();
    cout << "Valor total em estoque: R$ " << prod2.calcularValorTotal() << endl;

    prod3.exibir();
    cout << "Valor total em estoque: R$ " << prod3.calcularValorTotal() << endl;

    // Exibe total de produtos criados
    cout << "\nTotal de produtos criados: " << Produto::getTotalProdutos() << endl;

    return 0;
}
