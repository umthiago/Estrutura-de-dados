#include <iostream>
#include <string>
using namespace std;

class Cliente {
private:
  string nome;
  string cpf;
  string telefone;

public:
  Cliente(string n, string c, string t) {
    nome = n;
    cpf = c;
    telefone = t;
  }

  void mostrarDados() {
    cout << "Nome: " << nome << endl;
    cout << "CPF: " << cpf << endl;
    cout << "Telefone: " << telefone << endl;
  }

  void atualizarTelefone(string novoTelefone) {
    telefone = novoTelefone;
    cout << "Telefone atualizado para: " << telefone << endl;
  }
};

int main() {
  Cliente cliente("João da Silva", "123.456.789-00", "45987654321");
  cliente.mostrarDados();

  cliente.atualizarTelefone("45912345678");
  cliente.mostrarDados();

  return 0;
}
