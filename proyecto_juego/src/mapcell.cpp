#include "mapcell.h"
//Implementacion de toda la funcionabilidad de las celdas del mapa de juego
#include <iostream>

using namespace std;

mapcell::mapcell()
{
    //ctor
    id = 0; //ascii de espacios en el mapa
    //id = 178;
}
bool mapcell::isBlockedCell()
{
    //cout << "caracter visitado=" << id << endl;
    if( id == '1')
    //if( id == 178)
    {
        return true;
    } else
    {
        return false;
    }
}
mapcell::~mapcell()
{
    //dtor
}
