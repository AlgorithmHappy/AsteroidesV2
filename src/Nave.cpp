#include "Nave.h"

Nave::Nave(Asteroide *_asteroide){
    if(!txtrNave.loadFromFile("recursos/nave.png"))
        std::cout << "No se pudo cargar la textura nave.png" << std::endl;

    carril = 2;
    vida = 3;
    sprNave.setTexture(txtrNave);
    sprNave.setOrigin(sprNave.getGlobalBounds().width/2.f, sprNave.getGlobalBounds().height/2.f);
    sprNave.setScale(720/sprNave.getGlobalBounds().width/3, 720/sprNave.getGlobalBounds().height/3);
    sprNave.setPosition(sprNave.getGlobalBounds().width/2, ((720/3)*carril) - (sprNave.getGlobalBounds().height/2));

    asteroide = _asteroide;
}

void Nave::mover(bool direccion){ // True = abajo False = arriba
    if(direccion){
        if(carril < 3) carril++;
    }
    else{
        if(carril > 1) carril--;
    }
}

void Nave::actualizarNave(){
    sprNave.setPosition(sprNave.getGlobalBounds().width/2, ((720/3)*carril) - (sprNave.getGlobalBounds().height/2));

    if(vida <= 0){
        sprNave.setPosition(-(sprNave.getGlobalBounds().width/2), sprNave.getPosition().y);
    }
    if((asteroide->getRectAsteroide().contains(sprNave.getPosition())) &&
       (rljColisiones.getElapsedTime().asMilliseconds() >= 300.f) &&
       (rljInvensibilidad.getElapsedTime().asSeconds() > 3.f)){
        vida--;
        rljColisiones.restart();
        rljInvensibilidad.restart(); // Esto lo hago para que una vez colisionado se espere 3 segundos de invensibilidad,
                                     //si no cada 300 milisegundos le bajara la vida, es como un protector de respawn raro XD
    }
    if(rljInvensibilidad.getElapsedTime().asSeconds() < 3){
        if(rljInvensibilidad.getElapsedTime().asMilliseconds() <= 500.f)
            sprNave.setColor(Color(255.f, 255.f, 255.f, 50));
        else if(rljInvensibilidad.getElapsedTime().asMilliseconds() <= 1000.f)
            sprNave.setColor(Color(255.f, 255.f, 255.f, 200));
        else if(rljInvensibilidad.getElapsedTime().asMilliseconds() <= 1500.f)
            sprNave.setColor(Color(255.f, 255.f, 255.f, 50));
        else if(rljInvensibilidad.getElapsedTime().asMilliseconds() <= 2000.f)
            sprNave.setColor(Color(255.f, 255.f, 255.f, 200));
        else if(rljInvensibilidad.getElapsedTime().asMilliseconds() <= 2500.f)
            sprNave.setColor(Color(255.f, 255.f, 255.f, 50));
        else if(rljInvensibilidad.getElapsedTime().asMilliseconds() <= 3000.f)
            sprNave.setColor(Color(255.f, 255.f, 255.f, 50));

    }
    if(rljInvensibilidad.getElapsedTime().asSeconds() > 3)
        sprNave.setColor(Color(255.f, 255.f, 255.f, 255));
}

Sprite Nave::getSprNave(){
    actualizarNave();
    return sprNave;
}

int Nave::getVida(){
    return vida;
}

void Nave::setVida(int _vida){
    vida = _vida;
}

int Nave::getCarril(){
    return carril;
}

Nave::~Nave(){
}
