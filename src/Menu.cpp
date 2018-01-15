#include "Menu.h"

Menu::Menu(){
    if(!txtrEspacio.loadFromFile("recursos/espacio2.png"))
        std::cout << "No se pudo cargar la textura espacio2.png";
    sprEspacio.setTexture(txtrEspacio);
    sprEspacio.setScale(0.467836257, 0.467836257);

    if(!txtrCursor.loadFromFile("recursos/cursor.png"))
        std::cout << "No se pudo cargar la textura cursor.png";
    sprCursor.setTexture(txtrCursor);
    sprCursor.setPosition(1280 / 2, 720 / 2);

    for(int i = 0; i < 4; i++){
        std::string ruta = "recursos/boton";
        ruta += char(49 + i);
        if(!txtrBotones[i].loadFromFile(ruta + ".png"))
            std::cout << "No se pudo cargar la textura boton" << i + 1 << ".png" << std::endl;
        sprBotones[i].setTexture(txtrBotones[i]);
        sprBotones[i].setOrigin(txtrBotones[i].getSize().x / 2, txtrBotones[i].getSize().y / 2);
        sprBotones[i].setPosition((1280 / 2),(720 / 5) * (i + 1));
    }
}

Menu::~Menu(){
    //dtor
}
