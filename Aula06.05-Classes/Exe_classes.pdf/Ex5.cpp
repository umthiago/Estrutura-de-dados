#include <iostream>
#include <string>
using namespace std;

class ContaBancaria {
private:
  string numeroConta;
  string nomeTitular;
  double saldo;

public:
  ContaBancaria(string numero, string nome, double saldoInicial) {
    numeroConta = numero;
    nomeTitular = nome;
    saldo = saldoInicial;
  }

  void depositar(double valor) {
    saldo += valor;
    cout << "Depósito de " << valor << " realizado. Novo saldo: " << saldo << endl;
  }

  void sacar(double valor) {
    if (saldo >= valor) {
      saldo -= valor;
      cout << "Saque de " << valor << " realizado. Novo saldo: " << saldo << endl;
    } else {
      cout << "Saldo insuficiente." << endl;
    }
  }

  void exibirExtrato() {
    cout << "Número da Conta: " << numeroConta << endl;
    cout << "Titular: " << nomeTitular << endl;
    cout << "Saldo: " << saldo << endl;
  }
};

int main() {
  ContaBancaria conta1("12345-6", "João Silva", 1000.0);
  conta1.exibirExtrato();
  conta1.depositar(500.0);
  conta1.sacar(200.0);
  conta1.exibirExtrato();

  return 0;
}
