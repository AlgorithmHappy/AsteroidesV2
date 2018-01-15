#include "Espacio.h"

Espacio::Espacio(){
    if(!txtrEspacio.loadFromFile("recursos/espacio.png"))
        std::cout << "No se pudo cargar la textura espacio.png";
    txtrEspacio.setRepeated(true);

    Aceleracion = 70;

    vctPosParallax.x = 0;
    vctPosParallax.y = 0;

    sprEspacio.setTexture(txtrEspacio);
    sprEspacio.setTextureRect(IntRect(vctPosParallax.x, vctPosParallax.y, 1280, 720));
    sprEspacio.setOrigin(sprEspacio.getGlobalBounds().width/2.f, sprEspacio.getGlobalBounds().height/2.f);
    sprEspacio.setPosition(1280/2.f, 720/2.f);
}

Sprite Espacio::getSprEspacio(){
    if(rljAceleracion.getElapsedTime().asSeconds() >= 10.f){
        Aceleracion -= 10;
        rljAceleracion.restart();
    }
    if(Aceleracion <= 1)
        Aceleracion = 1;
    if(rljParallax.getElapsedTime().asMilliseconds() >= Aceleracion){
        sprEspacio.setTextureRect(IntRect(++vctPosParallax.x, vctPosParallax.y, 1280, 720));
        rljParallax.restart();
    }
    return sprEspacio;
}

Espacio::~Espacio(){
    //dtor
}
