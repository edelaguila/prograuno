#include <iostream>

using namespace std;

int main()
{
    //Operador de asignacion
    bool isWizard = true;
    bool isThief = false;

    cout << isWizard << endl;

    isWizard = isThief;

    cout << isWizard;

    //Operador de suma (adicion)
    int vida = 100;
    int resistencia = 5;
    int debilidad = 10;

    cout << vida + 10 << endl;
    cout << vida << endl;
    cout << vida + resistencia << endl;

    vida = vida + resistencia;
    cout << vida << endl;

    //Operador de resta
    int picos = 10;

    cout << vida - picos << endl;

    vida = vida - (picos - resistencia);

    cout << vida << endl;

    //Operador multiplicacion
    float base = 5.23f;
    float altura = 19.3f;
    float resultado = 0;

    resultado = base * altura;

    cout << "El area de mi figura es: " << endl;
    cout << resultado << endl;

    //Operador division
    resultado = (base * altura) / 2;

     cout << "El area de mi triangulo es: " << endl;
     cout << resultado << endl;

     //Operador modulo
     //es par
     cout << 2 % 10 << endl;

     //es impar
     cout << 10 % 10 << endl;

    return 0;
}
