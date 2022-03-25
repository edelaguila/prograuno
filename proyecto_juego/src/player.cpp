#include "player.h"
#include <iostream>
#include <fstream>

using namespace std;
//Implementacion de toda la funcionabilidad de la clase Jugador

player::player()
{
    //ctor
    x = 1;
    y = 1;
    lastX = 1;
    lastY = 1;
}

player::~player()
{
    //dtor
    //
}
int player::getValueX(){
    return x;
}
int player::getValueY(){
    return y;
}
void player::setValueX(int valueX){
    x = valueX;
}
void player::setValueY(int valueY){
    y = valueY;
}
void player::callInput()
{
    char userInput = ' ';
    cin >> userInput;
    switch(userInput)
    {
    case 'a':
        // Cambio que permitira guardar la posicion del jugador eje Y
        lastY = y;
        //y = y + 1;   Correccion de error de movimientos eje Y
        y = y - 1;
        //cout << "El jugador se mueve arriba" << endl;
        break;
    case 'd':
        // Cambio que permitira guardar la posicion del jugador eje Y
        lastY = y;
        // y = y - 1;  Correccion de error de movimientos eje Y;
        y = y + 1;
        //cout << "El jugador se mueve abajo" << endl;
        break;
    case 's':
        // Cambio que permitira guardar la posicion del jugador eje Y
        lastX = x;
        x = x + 1;
        //cout << "El jugador se mueve derecha" << endl;
        break;
    case 'w':
        // Cambio que permitira guardar la posicion del jugador eje Y
        lastX = x;
        x = x - 1;
        //cout << "El jugador se mueve izquierda" << endl;
        break;
    case 'x':
        cout << " -- Juego Terminado -- :(" << endl << endl;
        drawCreditos();
        cout << endl;
        exit(0);
    }
    //cout << "El jugador esta en las coordenadas -> " << "X=" << x << " Y=" << y << " GuardaX=" << lastX << "GuardaY=" << lastY << endl;
}
void player::resetToSafePosition()
{
    x = lastX;
    y = lastY;
}
void player::drawCreditos()
{
    string line;
    char userInput = ' ';
    ifstream myFile("creditos.txt");
    if(myFile.is_open())
    {
        //Se obtiene el mapa externo y se general el mapa de celdas
        while( getline(myFile, line))
        {
            cout << line << endl;
        }
        myFile.close();
        cin >> userInput;
    }
    else
    {
        cout << "Error FATAL: el archivo de ganador no pudo ser cargado" << endl;
    }
}

