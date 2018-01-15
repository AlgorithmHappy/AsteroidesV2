#ifndef CORAZONES_H
#define CORAZONES_H

#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <Nave.h>

using namespace sf;

class Corazones{
    public:
        Corazones(Nave *_nave);
        Sprite getSprCorazon1();
        Sprite getSprCorazon2();
        Sprite getSprCorazon3();
        virtual ~Corazones();

    //protected:

    private:
        Nave *nave;
        Texture txtrCorazon;
        Sprite sprCorazon1, sprCorazon2, sprCorazon3, sprAuxiliar;
};

#endif // CORAZONES_H
