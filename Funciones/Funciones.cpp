#include <iostream>

using namespace std;

void PrintCuteMessage()
{
    cout << "Eres increible!" << endl;
}

void Print(string message)
{
    cout << message << endl;
}

bool IsPlayerDead(int hp)
{
    if(hp <= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool PrintBool(bool value)
{
    if(value == true)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}

int GetAttackPower(int Damage, int Weapon)
{
    return Damage + Weapon;
}
int obtenerSuma(int Valor1, int Valor2)
{
    return Valor1 + Valor2;
}

int main()
{
    PrintCuteMessage();
    PrintCuteMessage();

    int hp = 20;
    int power = 5;
    int weapon  = 11;

    Print("Is Player dead????");

    bool isDead = IsPlayerDead( hp - GetAttackPower(power,weapon) );

    PrintBool(isDead);
    Print("Este es el valor real de acuerdo a la compu");
    cout << isDead << endl;
    Print("ejemplo de calculadora");
    int suma = obtenerSuma(power, weapon);
    Print("El resultado de la suma es:");
    cout << suma << endl;

    return 0;
}
