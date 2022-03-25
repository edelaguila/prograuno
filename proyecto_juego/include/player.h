#ifndef PLAYER_H
#define PLAYER_H

// Encabezado que define toda la funcionabilidad del Jugador
class player
{
    public:
        player();
        int lastX, lastY;
        virtual ~player();
        void callInput();
        int getValueX();
        void setValueX(int valueX);
        int getValueY();
        void setValueY(int valueY);
        void resetToSafePosition();
        void drawCreditos();

    protected:

    private:
        int x, y;

};

#endif // PLAYER_H
