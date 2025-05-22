Crie uma classe em C++ chamada Relogio24Horas para representar um relógio no formato de 24 horas 
(de 00:00:00 a 23:59:59).
Atributos privados:
int hora
int minuto
int segundo
Requisitos:
Forneça um construtor com parâmetros com valores padrão (zero para todos).
Crie funções membro setHora, setMinuto, setSegundo, todas com validação de faixa (0–23 para hora,
 0–59 para minuto e segundo).
Crie um método imprimeHora() que exibe a hora no formato HH:MM:SS.
Crie um método incrementaSegundo() que incrementa o segundo em 1, e caso ultrapasse 59, atualize minuto e hora corretamente (como em um relógio real).
Crie um método ehIgual(Relogio24Horas outro) que verifica se duas instâncias têm o mesmo horário.
No programa principal:
Crie dois objetos Relogio24Horas, um com hora 23:59:59 e outro com 00:00:00.
Incremente 1 segundo no primeiro e mostre a hora para verificar se virou para 00:00:00.
Compare os dois objetos e imprima se são iguais ou não.


#include <iostream>
using namespace std;

class Relogio24Horas {
private:
    int hora;
    int minuto;
    int segundo;

public:
    // Construtor com valores padrão
    Relogio24Horas(int h = 0, int m = 0, int s = 0) {
        setHora(h);
        setMinuto(m);
        setSegundo(s);
    }

    // Setters com validação
    void setHora(int h) {
        if (h >= 0 && h <= 23)
            hora = h;
        else {
            cout << "Hora invalida. Definido como 0." << endl;
            hora = 0;
        }
    }

    void setMinuto(int m) {
        if (m >= 0 && m <= 59)
            minuto = m;
        else {
            cout << "Minuto invalido. Definido como 0." << endl;
            minuto = 0;
        }
    }

    void setSegundo(int s) {
        if (s >= 0 && s <= 59)
            segundo = s;
        else {
            cout << "Segundo invalido. Definido como 0." << endl;
            segundo = 0;
        }
    }

    // Imprime no formato HH:MM:SS
    void imprimeHora() const {
        if (hora < 10) cout << "0";
        cout << hora << ":";

        if (minuto < 10) cout << "0";
        cout << minuto << ":";

        if (segundo < 10) cout << "0";
        cout << segundo;
    }

    // Incrementa 1 segundo, ajustando minuto e hora
    void incrementaSegundo() {
        segundo++;
        if (segundo > 59) {
            segundo = 0;
            minuto++;
            if (minuto > 59) {
                minuto = 0;
                hora++;
                if (hora > 23) {
                    hora = 0;
                }
            }
        }
    }

    // Verifica se dois relógios têm o mesmo horário
    bool ehIgual(const Relogio24Horas& outro) const {
        return (hora == outro.hora) && 
               (minuto == outro.minuto) && 
               (segundo == outro.segundo);
    }
};

// Programa principal
int main() {
    Relogio24Horas relogio1(23, 59, 59);
    Relogio24Horas relogio2(0, 0, 0);

    cout << "Relogio 1 antes de incrementar: ";
    relogio1.imprimeHora();
    cout << endl;

    relogio1.incrementaSegundo();

    cout << "Relogio 1 depois de incrementar: ";
    relogio1.imprimeHora();
    cout << endl;

    cout << "Relogio 2: ";
    relogio2.imprimeHora();
    cout << endl;

    if (relogio1.ehIgual(relogio2)) {
        cout << "Os relogios sao IGUAIS." << endl;
    } else {
        cout << "Os relogios sao DIFERENTES." << endl;
    }

    return 0;
}
