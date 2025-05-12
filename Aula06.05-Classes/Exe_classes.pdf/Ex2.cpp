#include <iostream>
#include <string>
using namespace std;

class Personagem {
private:
  string nome;
  int vida;
  int ataque;
  int defesa;

public:
  Personagem(string n, int v, int a, int d) {
    nome = n;
    vida = v;
    ataque = a;
    defesa = d;
  }

  void atacar(Personagem &alvo) {
    int dano = ataque - alvo.defesa;
    if (dano > 0) {
      alvo.sofrerDano(dano);
      cout << nome << " ataca " << alvo.nome << " e causa " << dano
           << " de dano!" << endl;
    } else {
      cout << nome << " ataca " << alvo.nome << ", mas não causa dano!"
           << endl;
    }
  }

  void sofrerDano(int dano) {
    vida -= dano;
    if (vida < 0) {
      vida = 0;
    }
    cout << nome << " sofre " << dano << " de dano. Vida restante: " << vida
         << endl;
  }

  void exibirStatus() {
    cout << "\nNome: " << nome << "\nVida: " << vida << "\nAtaque: " << ataque
         << "\nDefesa: " << defesa << endl;
  }
};

int main() {
  Personagem irineu("irineu", 100, 20, 10);
  Personagem fulano("fulano", 80, 15, 5);

  irineu.exibirStatus();
  fulano.exibirStatus();

  
  fulano.atacar(irineu);
  irineu.atacar(fulano);

  irineu.exibirStatus();
  fulano.exibirStatus();

  return 0;
}
