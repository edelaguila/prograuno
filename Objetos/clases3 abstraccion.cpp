#include <iostream>

using namespace std;

class Humano
{
public:
    Humano(int nuevaEdad)
    {
        Edad = nuevaEdad;
    }
    int Edad;

    void Pensar()
    {
        cout << obtenerPensamiento() << endl;
    }

private:

    int nivelSocial;
    int inteligencia;
    int suerte;

    string obtenerPensamiento()
    {
        nivelSocial = 0;
        suerte = 0;
        inteligencia = 0;
        if(nivelSocial + suerte > 100)
        {
            return "Estoy teniendo pensamientos felices :D";
        }
        else if(suerte > inteligencia)
        {
            return "Soy un suertudo";
        }
        else if(Edad > 18)
        {
            return "Soy un adulto";
        }
        else
        {
            return "no estoy pensando nada";
        }
    }
};


int main()
{
    Humano Roberto(19);

    Roberto.Pensar();

    return 0;
}
