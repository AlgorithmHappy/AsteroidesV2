#ifndef CAJATEXTO_H
#define CAJATEXTO_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <SFML/Graphics.hpp>

using namespace sf;

class CajaTexto
{
    public:
        CajaTexto();
        Texture txtrEspacio, txtrBotonGuardar, txtrBotonSaltar, txtrCursor, txtrRectangulo;
        Sprite sprEspacio, sprBotonGuardar, sprBotonOmitir, sprCursor, sprRectangulo;
        Font fntFuente;
        Text txtTexto, txtPuntuacion, txtIngresado;
        void setTxtIngresado(std::string strNick);
        //RectangleShape rctTextBox;
        virtual ~CajaTexto();

    //protected:

    private:
};

#endif // CAJATEXTO_H
