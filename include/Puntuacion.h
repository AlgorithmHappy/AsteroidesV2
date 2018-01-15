#ifndef PUNTUACION_H
#define PUNTUACION_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <SFML/Graphics.hpp>

using namespace sf;

class Puntuacion
{
    public:
        Puntuacion();
        Text getTxtPuntuacion();
        int getPuntuacion();
        void actualizar();
        virtual ~Puntuacion();

    //protected:

    private:
        int puntuacion;
        Font fntFuente;
        Text txtPuntuacion;
        Clock rljPuntuacion;
};

#endif // PUNTUACION_H
