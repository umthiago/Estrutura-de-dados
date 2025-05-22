2)Crie uma classe em C++ chamada ContaDePoupanca. Use um
membro de dados static para conter a taxaDeJurosAnual para cada um dos
poupadores. Cada membro da classe contém um membro de dados private
saldoDaPoupanca indicando a quantia que o poupador atualmente tem em depótiso.
Forneça um método membro calculeRendimentoMensal que calcule o rendimento
mensal multiplicando o saldo pela taxaDeJurosAnual dividida por 12; este rendimento
deve ser somado ao saldoDaPoupanca. Forneça uma função membro static
modifiqueTaxaDeJuros que inicializa a variável static taxaDeJurosAnual com
um novo valor. Escreve um programa de teste que instancia dois objetos diferentes
contaDePoupanca , poupador1 e poupador2, com saldos de R$ 2000,00 e R$ 3000,00,
respectivamente. Inicialize taxaDeJurosAnual com 6%, então calcule o rendimento mensal e
imprima os novos saldos para cada um dos poupadores. Inicialize então a taxaDeJurosAnual
com 8% e calcule o rendimento do próximo mês e imprime o novo saldo para cada um dos
poupadores


#include <iostream>
#include <iomanip> // Para definir precisão de casas decimais

using namespace std;

class ContaDePoupanca {
private:
    double saldoDaPoupanca; // Saldo da conta

    // A taxa de juros anual é comum para todos os objetos
    static double taxaDeJurosAnual;

public:
    // Construtor
    ContaDePoupanca(double saldoInicial) {
        if (saldoInicial >= 0)
            saldoDaPoupanca = saldoInicial;
        else {
            cout << "Saldo inicial invalido. Definido como 0." << endl;
            saldoDaPoupanca = 0.0;
        }
    }

    // Calcula rendimento mensal e adiciona ao saldo
    void calculeRendimentoMensal() {
        double rendimento = saldoDaPoupanca * (taxaDeJurosAnual / 12.0);
        saldoDaPoupanca += rendimento;
    }

    // Mostra o saldo atual
    void mostraSaldo() const {
        cout << "Saldo atual: R$ " << fixed << setprecision(2) << saldoDaPoupanca << endl;
    }

    // Método estático para modificar a taxa de juros anual
    static void modifiqueTaxaDeJuros(double novaTaxa) {
        taxaDeJurosAnual = novaTaxa;
    }
};

// Inicializa a variável estática fora da classe
double ContaDePoupanca::taxaDeJurosAnual = 0.0;

int main() {
    // Cria dois poupadores com saldos iniciais
    ContaDePoupanca poupador1(2000.00);
    ContaDePoupanca poupador2(3000.00);

    // Define a taxa de juros anual para 6% (0.06)
    ContaDePoupanca::modifiqueTaxaDeJuros(0.06);

    cout << "Mes: 1 com taxa de juros de 6%" << endl;
    poupador1.calculeRendimentoMensal();
    poupador2.calculeRendimentoMensal();

    cout << "Poupador 1 -> ";
    poupador1.mostraSaldo();

    cout << "Poupador 2 -> ";
    poupador2.mostraSaldo();

    // Agora altera a taxa de juros anual para 8% (0.08)
    ContaDePoupanca::modifiqueTaxaDeJuros(0.08);

    cout << "\nMes: 2 com taxa de juros de 8% " << endl;
    poupador1.calculeRendimentoMensal();
    poupador2.calculeRendimentoMensal();

    cout << "Poupador 1 -> ";
    poupador1.mostraSaldo();

    cout << "Poupador 2 -> ";
    poupador2.mostraSaldo();

    return 0;
}
