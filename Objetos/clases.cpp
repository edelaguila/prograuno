
#include <iostream>
using namespace std;
class Gato
{
public:
    string Nombre;
    Gato()
    {
        Nombre = "Felix";
    }
    Gato(string pNombre)
    {
        Nombre = pNombre;
    }
    void Meow()
    {
        cout << Nombre << " dice Meow " << endl;
    }
};
int main()
{
    Gato miPrimerGato;
    Gato miSegundoGato("Tom");
    Gato miTercerGato;
    Gato miCuartoGato("Firulais");
    cout << miPrimerGato.Nombre << endl;
    cout << miSegundoGato.Nombre << endl;
    cout << miTercerGato.Nombre << endl;
    cout << miCuartoGato.Nombre << endl;

    /*miPrimerGato.Meow();
    for (int i = 0; i < 3; i++)
    {
        miSegundoGato.Meow();
    }*/
    return 0;
}
