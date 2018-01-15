#include "Corazones.h"

Corazones::Corazones(Nave *_nave){
    if(!txtrCorazon.loadFromFile("recursos/corazon.png"))
        std::cout << "No se pudo cargar la textura corazon.png";

    sprCorazon1.setTexture(txtrCorazon);
    sprCorazon2.setTexture(txtrCorazon);
    sprCorazon3.setTexture(txtrCorazon);
    sprCorazon1.setScale(0.3, 0.3);
    sprCorazon2.setScale(0.3, 0.3);
    sprCorazon3.setScale(0.3, 0.3);
    sprCorazon1.setOrigin(sprCorazon1.getGlobalBounds().width/2.f, sprCorazon1.getGlobalBounds().height/2.f);
    sprCorazon2.setOrigin(sprCorazon2.getGlobalBounds().width/2.f, sprCorazon2.getGlobalBounds().height/2.f);
    sprCorazon3.setOrigin(sprCorazon3.getGlobalBounds().width/2.f, sprCorazon3.getGlobalBounds().height/2.f);
    sprCorazon1.setPosition(1220.f, 30.f);
    sprCorazon2.setPosition(1170.f, 30.f);
    sprCorazon3.setPosition(1120.f, 30.f);

    nave = _nave;
}

Sprite Corazones::getSprCorazon1(){
    if(nave->getVida() >= 1)
        return sprCorazon1;
    else
        return sprAuxiliar; // No contiene nada
}

Sprite Corazones::getSprCorazon2(){
    if(nave->getVida() >= 2)
        return sprCorazon2;
    else
        return sprAuxiliar; // No contiene nada
}

Sprite Corazones::getSprCorazon3(){
    if(nave->getVida() >= 3)
        return sprCorazon3;
    else
        return sprAuxiliar; // No contiene nada
}

Corazones::~Corazones(){
}
