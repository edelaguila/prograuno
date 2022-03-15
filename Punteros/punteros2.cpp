#include <iostream>

using namespace std;
void duplicar( int a ){
    a *= 2;
    cout << "Valor de la variable dentro de la funcion: " << a << endl;
}
void duplicarPorPuntero( int * a){
        *a *= 2;
}
int main() {
  /*int a = 5;
  cout << "Valor de la variable antes de la funcion: " << a << endl;
  duplicar(a);
  cout << "Valor de la variable despues de la funcion: " << a << endl;*/
  int a = 5;
  cout << "Valor de la variable antes de la funcion: " << a << endl;
  duplicarPorPuntero(&a);
  cout << "Valor de la variable despues de la funcion por Puntero: " << a << endl;
  return 0;
}
