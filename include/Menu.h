#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <Nave.h>

class Menu
{
    public:
        Menu();
        Sprite sprEspacio, sprBotones[4], sprCursor; // Lo hago publico poruqe creo que el metodo setPosition en SFML es protegido y en la funcion menuLoop del Main.cpp
        Texture txtrEspacio, txtrBotones[4], txtrCursor; // tengo que ocupar esa funcion y no la puedo ejecutar si no esta en publico
        virtual ~Menu();

    //protected:

    private:

};

#endif // MENU_H
