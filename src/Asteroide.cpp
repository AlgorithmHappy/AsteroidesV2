#include "Asteroide.h"

Asteroide::Asteroide(){
    if(!txtrAsteroide.loadFromFile("recursos/asteroide.png"))
        std::cout << "No se pudo cargar la textura asteroide.png" << std::endl;
    definirCarril();
    aceleracion = -10;
    sprAsteroide.setTexture(txtrAsteroide);
    sprAsteroide.setOrigin(sprAsteroide.getGlobalBounds().width/2.f, sprAsteroide.getGlobalBounds().height/2.f);
    sprAsteroide.setScale(720/sprAsteroide.getGlobalBounds().width/3, 720/sprAsteroide.getGlobalBounds().height/3);
    sprAsteroide.setPosition(1280 + (sprAsteroide.getGlobalBounds().width/2), (720/6)*carril);
}

void Asteroide::definirCarril(){
    srand(time(NULL));
    carril = 1 + rand() % (6 - 1); //variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior)
}

void Asteroide::actualizarAsteroide(){
    if(rljRotacion.getElapsedTime().asMilliseconds() >= 50.f){
        sprAsteroide.rotate(aceleracion);
        rljRotacion.restart();
    }
    if(rljTraslacion.getElapsedTime().asMilliseconds() >= 50.f){
        sprAsteroide.move(aceleracion, 0);
        rljTraslacion.restart();
    }
    if(rljDatos.getElapsedTime().asSeconds() >= 10.f){
        aceleracion -= 5;
        rljDatos.restart();
    }
    if(sprAsteroide.getPosition().x <= (sprAsteroide.getGlobalBounds().width/2)*-1){
        definirCarril();
        sprAsteroide.setPosition(1280 + (sprAsteroide.getGlobalBounds().width/2), (720/6)*carril);
    }
}

Sprite Asteroide::getSprAsteroide(){
    actualizarAsteroide();
    return sprAsteroide;
}

FloatRect Asteroide::getRectAsteroide(){
    return sprAsteroide.getGlobalBounds();
}

Asteroide::~Asteroide()
{
    //dtor
}
