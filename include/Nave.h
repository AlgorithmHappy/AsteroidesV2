#ifndef NAVE_H
#define NAVE_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <Asteroide.h>

using namespace sf;

class Nave{
    public:
        Nave(Asteroide *_asteroide);
        void mover(bool direccion);
        Sprite getSprNave();
        int getVida();
        int getCarril();
        void setVida(int _vida);
        virtual ~Nave();

    //protected:

    private:
        int carril, vida;
        Texture txtrNave;
        Sprite sprNave;
        Clock rljColisiones, rljInvensibilidad;
        Asteroide *asteroide;
        void actualizarNave();
};

#endif // NAVE_H
