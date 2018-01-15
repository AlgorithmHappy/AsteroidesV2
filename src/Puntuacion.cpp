#include "Puntuacion.h"

Puntuacion::Puntuacion(){
    if(!fntFuente.loadFromFile("recursos/neuropol.ttf"))
        std::cout << "No se pudo cargar la fuente neuropol.ttf";

    txtPuntuacion.setFont(fntFuente);
    txtPuntuacion.setString("Hola Mundo");

    rljPuntuacion.restart();

    puntuacion = 0;

}

Text Puntuacion::getTxtPuntuacion(){
    actualizar();
    return txtPuntuacion;
}

int Puntuacion::getPuntuacion(){
    return puntuacion;
}

void Puntuacion::actualizar(){
    puntuacion = rljPuntuacion.getElapsedTime().asSeconds();
    std::stringstream ss;
    ss << puntuacion;
    std::string str = ss.str();
    txtPuntuacion.setString(str);
}

Puntuacion::~Puntuacion(){
    //dtor
}
