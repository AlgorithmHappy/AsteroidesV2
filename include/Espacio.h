#ifndef ESPACIO_H
#define ESPACIO_H

#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

using namespace sf;

class Espacio{
    public:
        Espacio();
        Sprite getSprEspacio();
        virtual ~Espacio();

    //protected:

    private:
        float Aceleracion;
        Texture txtrEspacio;
        Sprite sprEspacio;
        Clock rljParallax, rljAceleracion;
        Vector2i vctPosParallax;
};

#endif // ESPACIO_H
