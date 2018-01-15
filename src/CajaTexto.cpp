#include "CajaTexto.h"

CajaTexto::CajaTexto(){
    if(!txtrEspacio.loadFromFile("recursos/espacio2.png"))
        std::cout << "No se pudo cargar la textura espacio2.png";
    if(!txtrBotonGuardar.loadFromFile("recursos/guardar.png"))
        std::cout << "No se pudo cargar la textura guardar.png";
    if(!txtrBotonSaltar.loadFromFile("recursos/omitir.png"))
        std::cout << "No se pudo cargar la textura omitir.png";
    if(!txtrCursor.loadFromFile("recursos/cursor.png"))
        std::cout << "No se pudo cargar la textura cursor.png";
    if(!txtrRectangulo.loadFromFile("recursos/rectangulo.png"))
        std::cout << "No se pudo cargar la textura rectangulo.png";

    sprEspacio.setTexture(txtrEspacio);
    sprEspacio.setScale(0.467836257, 0.467836257);

    sprBotonGuardar.setTexture(txtrBotonGuardar);
    sprBotonGuardar.setPosition((1280 / 5) * 1, (720 / 6) * 2);

    sprBotonOmitir.setTexture(txtrBotonSaltar);
    sprBotonOmitir.setPosition((1280 / 5) * 3, (720 / 6) * 2);

    sprCursor.setTexture(txtrCursor);

    sprRectangulo.setTexture(txtrRectangulo);
    sprRectangulo.setPosition(((1280 / 6) * 3 + 10), ((720 / 6) * 3) - 10);
    sprRectangulo.setColor(Color(255, 255, 255, 100));

    if(!fntFuente.loadFromFile("recursos/neuropol.ttf"))
        std::cout << "No se pudo cargar la fuente neuropol.png";

    txtTexto.setFont(fntFuente);
    txtTexto.setString("Ingrese su nick: ");
    txtTexto.setPosition(((1280 / 6) * 1) + 100, (720 / 6) * 3);

    txtPuntuacion.setFont(fntFuente);

    txtIngresado.setFont(fntFuente);
    txtIngresado.setPosition(((1280 / 6) * 3 + 10) + 20,  (720 / 6) * 3);
}

void CajaTexto::setTxtIngresado(std::string strNick){
    txtIngresado.setString(strNick);
}

CajaTexto::~CajaTexto(){
    //dtor
}
