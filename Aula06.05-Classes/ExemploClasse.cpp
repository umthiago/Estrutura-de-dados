#include <iostream>
using namespace std;

class Lampada {
private:
  int voltagem;
  int potencia;
  string cor;
  int luminosidade;
  bool ligada;

public:
  Lampada(int v, int p, string c, int l) {
    voltagem = v;
    potencia = p;
    cor = c;
    luminosidade = l;
    ligada = false;
  }

  void ascender() {
    ligada = true;
    cout << "A lampada ascendeu" << endl;
  }
  void apagar() {
    ligada = false;
    cout << "A lampada apagou" << endl;
  }
  void iluminar() {
    if (ligada)
      cout << "A lampada esta iluminando " << luminosidade << " lumens na cor "
           << cor << "." << endl;
    else
      cout << "A lampada apagada não ilumina" << endl;
  }
  void exibirInfo() {
    cout << "\nVoltagem: " << voltagem << "\nPotencia: " << potencia << "\nCor "
         << cor << "\nLuminosidade: " << luminosidade << "\n" << endl;
  }
};

int main(){
  Lampada lampada(200, 60, "branca", 70);
  lampada.exibirInfo();
  lampada.ascender();
  lampada.iluminar();
  lampada.apagar();

  return 0;
}
