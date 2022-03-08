#include <iostream>
using namespace std;

class Perro
{
public:
    string mLadrido;
    Perro(string Nombre, string tipoLadrido)
    {
        mLadrido = tipoLadrido;
        mNombre = Nombre;
    }
    void Ladrar()
    {
        cout << mLadrido << endl;
    }
    string getNombre()
    {
        return mNombre;
    }
    void setNombre(string pNuevoNombre)
    {
        mNombre = pNuevoNombre;
    }
private:
    string mNombre;
};


int main()
{
    Perro PerroUno("Rudolf", "Ladrido1");
    PerroUno.setNombre("Boby");
    PerroUno.setNombre("Nerón)");
    PerroUno.Ladrar();
    PerroUno.mLadrido = "Ladrido3";
    Perro PerroDos("Luna", "Ladrido2");
    cout << PerroUno.getNombre() << endl;
    cout << PerroDos.getNombre() << endl;
    PerroUno.Ladrar();
    PerroDos.Ladrar();
    return 0;
}
