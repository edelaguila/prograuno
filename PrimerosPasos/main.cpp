#include <iostream>

using namespace std;

int main()
{

    int Edad = 0;

    cout << "Introduce tu edad: ";

    cin >> Edad;

    cout << endl << "Que joven, apenas tienes: " << Edad << endl;


    int base,altura;
    cout << "Introduce la base de tu rectangulo: " << endl;
    cin >> base;
    cout << "Introduce la altura de tu rectangulo" << endl;
    cin >> altura;

    cout << "El area de tu rectangulo es: " << base * altura;

    char miLetraFavorita;

    cout << "Cual es tu letra favorita?" << endl;
    cin >> miLetraFavorita;
    cout << "Oh tambien la mia es: " << miLetraFavorita << endl;

    int* valorA = new int;
    int* valorB = new int;

    cout << "Introduce el primer valor a multiplicar: " << endl;
    cin >> *valorA;

    cout << "Introduce el segundo valor a multiplicar: " << endl;
    cin >> *valorB;

    cout << "El resultado es: " << *valorA * *valorB;

    return 0;
}
