#include <iostream>
#include <cmath>
using namespace std;

void areaDelCirculo(void);
void areaDelCuadrado(void);
void areaDelRectangulo(void);
void areaDelTriangulo(void);
void mostrarArea(float area);

const float Pi = 3.14154;

int main(){
 char opcion;
 cout<<"Selecciona el area que deseas calcular"<<endl;
 cout<<" a) Circulo\n b) Cuadrado\n c) Rectangulo\n d) Triangulo\n"; cin>>opcion;
 switch(opcion){
  case 'a': areaDelCirculo(); break;
  case 'b': areaDelCuadrado(); break;
  case 'c': areaDelRectangulo(); break;
  case 'd': areaDelTriangulo(); break;
 }
 return 0;
}
