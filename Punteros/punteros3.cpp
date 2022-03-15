#include <iostream>

using namespace std;

int main() {
  int* pi;
  int a = 5;
  int b = 1;
  pi = &a;
  cout << "Valor actual variable (a): " << a << " " << &a << " Valor actual variable (b): " << b << " " << &b << " puntero: " << pi << endl;
  pi = &b;
  *pi = 10;
  cout << "Valor posterior variable (a): " << a << " " << &a << " Valor posterior variable (b): " << b << " " << &b << " puntero: " << pi << endl;
  return 0;
}
