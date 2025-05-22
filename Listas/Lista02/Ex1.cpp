1 - Crie uma classe em C++ chamada InteiroGigante que usa 
um array de dígitos de 40 elementos para armazenar 
inteiros tão grandes quanto 40 dígitos. Forneça as 
funções membro leiaInteiroGigante, 
imprimeInteiroGigante, adicioneInteiroGigantes e 
subtraiaInteiroGigantes gPara comparar objetos do tipo 
InteiroGigante, providencie métodos eIgual, naoEIgual, 
ehMaior, ehMenorQueOuIgualA e ehMenorQueOuIgualA – cada 
um desses métodos é uma “função predicado”, que 
simplesmente retorna true se a relação entre os dois 
inteiros gigantes for verdadeira e retorna false se a 
relação não for verdadeira





#include <iostream>
#include <cstring>

using namespace std;

class InteiroGigante {
private:
    static const int TAMANHO = 40;
    int digitos[TAMANHO];

public:
    // Construtor: inicializa o vetor com zeros
    InteiroGigante() {
        for (int i = 0; i < TAMANHO; i++) {
            digitos[i] = 0;
        }
    }

    // Ler número como sequência de dígitos
    void leiaInteiroGigante() {
        char entrada[TAMANHO + 1];  // +1 para o caractere nulo '\0'

        cout << "Digite um numero de ate 40 digitos: ";
        cin >> entrada;

        int tamanhoEntrada = strlen(entrada);

        // Verifica se excede 40 dígitos
        if (tamanhoEntrada > TAMANHO) {
            cout << "Erro: Numero excede 40 digitos." << endl;
            exit(1);
        }

        // Preencher zeros à esquerda
        int inicio = TAMANHO - tamanhoEntrada;
        for (int i = 0; i < inicio; i++) {
            digitos[i] = 0;
        }

        // Preencher os dígitos do número
        for (int i = 0; i < tamanhoEntrada; i++) {
            if (entrada[i] >= '0' && entrada[i] <= '9') {
                digitos[inicio + i] = entrada[i] - '0';
            } else {
                cout << "Erro: Entrada invalida. Digite apenas numeros." << endl;
                exit(1);
            }
        }
    }

    // Imprimir o número sem zeros à esquerda
    void imprimeInteiroGigante() const {
        bool iniciou = false;
        for (int i = 0; i < TAMANHO; i++) {
            if (digitos[i] != 0 || iniciou) {
                cout << digitos[i];
                iniciou = true;
            }
        }
        if (!iniciou) cout << "0";
    }

    // Soma de dois InteiroGigante
    InteiroGigante adicioneInteiroGigantes(const InteiroGigante& outro) const {
        InteiroGigante resultado;
        int carry = 0;

        for (int i = TAMANHO - 1; i >= 0; i--) {
            int soma = digitos[i] + outro.digitos[i] + carry;
            resultado.digitos[i] = soma % 10;
            carry = soma / 10;
        }

        return resultado;
    }

    // Subtração (assume que o primeiro >= segundo)
    InteiroGigante subtraiaInteiroGigantes(const InteiroGigante& outro) const {
        InteiroGigante resultado;
        int emprestimo = 0;

        for (int i = TAMANHO - 1; i >= 0; i--) {
            int sub = digitos[i] - outro.digitos[i] - emprestimo;
            if (sub < 0) {
                sub += 10;
                emprestimo = 1;
            } else {
                emprestimo = 0;
            }
            resultado.digitos[i] = sub;
        }

        return resultado;
    }

    // Comparações
    bool eIgual(const InteiroGigante& outro) const {
        for (int i = 0; i < TAMANHO; i++) {
            if (digitos[i] != outro.digitos[i])
                return false;
        }
        return true;
    }

    bool naoEIgual(const InteiroGigante& outro) const {
        return !eIgual(outro);
    }

    bool ehMaior(const InteiroGigante& outro) const {
        for (int i = 0; i < TAMANHO; i++) {
            if (digitos[i] > outro.digitos[i])
                return true;
            if (digitos[i] < outro.digitos[i])
                return false;
        }
        return false; // São iguais
    }

    bool ehMenor(const InteiroGigante& outro) const {
        return !ehMaiorQueOuIgualA(outro);
    }

    bool ehMaiorQueOuIgualA(const InteiroGigante& outro) const {
        return ehMaior(outro) || eIgual(outro);
    }

    bool ehMenorQueOuIgualA(const InteiroGigante& outro) const {
        return !ehMaior(outro);
    }
};


// Programa principal para testar
int main() {
    InteiroGigante num1, num2, resultadoSoma, resultadoSub;

    cout << "Digite o primeiro numero:" << endl;
    num1.leiaInteiroGigante();

    cout << "Digite o segundo numero:" << endl;
    num2.leiaInteiroGigante();

    cout << "\nPrimeiro numero: ";
    num1.imprimeInteiroGigante();
    cout << "\nSegundo numero: ";
    num2.imprimeInteiroGigante();

    resultadoSoma = num1.adicioneInteiroGigantes(num2);
    cout << "\n\nSoma: ";
    resultadoSoma.imprimeInteiroGigante();

    if (num1.ehMaiorQueOuIgualA(num2)) {
        resultadoSub = num1.subtraiaInteiroGigantes(num2);
        cout << "\nSubtracao (Primeiro - Segundo): ";
        resultadoSub.imprimeInteiroGigante();
    } else {
        cout << "\nSubtracao nao permitida (Primeiro < Segundo)";
    }

    cout << "\n\nComparacoes:";
    cout << "\nEh igual? " << (num1.eIgual(num2) ? "Sim" : "Nao");
    cout << "\nNao eh igual? " << (num1.naoEIgual(num2) ? "Sim" : "Nao");
    cout << "\nEh maior? " << (num1.ehMaior(num2) ? "Sim" : "Nao");
    cout << "\nEh menor? " << (num1.ehMenor(num2) ? "Sim" : "Nao");
    cout << "\nEh maior ou igual? " << (num1.ehMaiorQueOuIgualA(num2) ? "Sim" : "Nao");
    cout << "\nEh menor ou igual? " << (num1.ehMenorQueOuIgualA(num2) ? "Sim" : "Nao");

    cout << endl;
    return 0;
}
