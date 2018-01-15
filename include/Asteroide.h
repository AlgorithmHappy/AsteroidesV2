#ifndef ASTEROIDE_H
#define ASTEROIDE_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>

using namespace sf;

class Asteroide{
    public:
        Asteroide();
        Sprite getSprAsteroide();
        FloatRect getRectAsteroide();
        virtual ~Asteroide();

    //protected:

    private:
        int carril, aceleracion;
        Texture txtrAsteroide;
        Sprite sprAsteroide;
        Clock rljRotacion, rljTraslacion, rljDatos;
        void definirCarril();
        void actualizarAsteroide();
};

#endif // ASTEROIDE_H
