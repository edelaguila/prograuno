#include <iostream>

using namespace std;

// Base class
class Animal {
  public:
    void sonidoAnimal() {
      cout << "Los animales hacen un sonido \n" ;
    }
};

// Derived class
class Cerdo : public Animal {
  public:
    void sonidoAnimal() {
      cout << "El cerdo dice: wee wee \n" ;
    }
};

// Derived class
class Perro : public Animal {
  public:
    void sonidoAnimal() {
      cout << "El perro dice: bow wow \n" ;
    }
};

int main() {
  Animal miAnimal;
  Cerdo miCerdo;
  Perro miPerro;

  miAnimal.sonidoAnimal();
  miCerdo.sonidoAnimal();
  miPerro.sonidoAnimal();
  return 0;
}

