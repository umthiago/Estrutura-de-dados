#include <iostream>
using namespace std;

class Carro {
private:
  string marca;
  string modelo;
  int ano;
  int velocidade;

public:
  Carro(string m, string mo, int a, int v) {
    marca = m;
    modelo = mo;
    ano = a;
    velocidade = v;
  }

  void acelerar() {
    velocidade += 10;
    cout << "Acelerando... Velocidade atual: " << velocidade << " km/h" << endl;
  }
  void frear() {
    if (velocidade > 0) {
      velocidade -= 10;
      cout << "Freando... Velocidade atual: " << velocidade << " km/h" << endl;
    } else {
      cout << "O carro já está parado!" << endl;
    }
  }
  void exibirdadosCarro() {
    cout << "\nMarca: " << marca << "\nModelo: " << modelo << "\nAno: " << ano
         << "\nVelocidade: " << velocidade << " km/h" << endl;
  }
};

int main(){
  Carro carro("BMW", "320I", 2012, 0);
  carro.acelerar();
  carro.frear();
  carro.frear();
  carro.acelerar();
  carro.acelerar();

  carro.exibirdadosCarro();

  return 0;
}
