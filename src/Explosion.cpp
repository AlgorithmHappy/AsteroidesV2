#include "Explosion.h"

Explosion::Explosion(){
    srand(time(NULL));
    tipoExplosion = 0 + rand() % (3 - 0); //variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior)
    contador = 0;
    vctNumSprite.x = 0;
    vctNumSprite.y = 0;
    for(int i = 0; i < 3; i++){
        std::string ruta;
        ruta = "recursos/explosion";
        ruta += char(49 + i);
        if(!txtrExplosion[i].loadFromFile(ruta + ".png"))
            std::cout << "No se pudo cargar la textura explosion" << i + 1 << ".png" << std::endl;

        sprExplosion[i].setTexture(txtrExplosion[i]);
        sprExplosion[i].setScale(2.3f, 2.3f);
        sprExplosion[i].setTextureRect(IntRect(0, 0, sprExplosion[i].getLocalBounds().width / 8, sprExplosion[i].getLocalBounds().height / 8));
        sprExplosion[i].setOrigin((txtrExplosion[i].getSize().x / 16),
                                  (txtrExplosion[i].getSize().y / 16));
        sprExplosion[i].setPosition(120.f, 0);
    }

    sndBuffer.loadFromFile("recursos/DeathFlash.flac");
    sndExplosion.setBuffer(sndBuffer);
    sndExplosion.setVolume(250);
}

Sprite Explosion::getSprExplosion(){
    sprExplosion[tipoExplosion].setPosition(sprExplosion[tipoExplosion].getPosition().x, ((720/3)*posicionNave) - (720/6));
    if(vidaNave <= 0){
        actualizarSprite();
        return sprExplosion[tipoExplosion];
    }
    else{
        Sprite sprAuxiliar;
        return sprAuxiliar;
    }
}

void Explosion::setPosicionExp(int _posicionNave){
    posicionNave = _posicionNave;
}

void Explosion::setVidaNave(int _vidaNave){
    vidaNave = _vidaNave;
}

void Explosion::actualizarSprite(){
    if(contador == 0){
        sndExplosion.play();
        contador++;
    }
    if(vctNumSprite.y <= 7){
        if(rljFrameRate.getElapsedTime().asMilliseconds() >= 50.f){
            if(vctNumSprite.x == 7){
                vctNumSprite.y++;
                vctNumSprite.x = 0;
            }
            else{
                vctNumSprite.x++;
            }
            rljFrameRate.restart();
        }
    }
    sprExplosion[tipoExplosion].setTextureRect(IntRect((txtrExplosion[tipoExplosion].getSize().x / 8) * vctNumSprite.x,
                                               (txtrExplosion[tipoExplosion].getSize().y / 8) * vctNumSprite.y,
                                               txtrExplosion[tipoExplosion].getSize().x / 8,
                                               txtrExplosion[tipoExplosion].getSize().y / 8));
}

Explosion::~Explosion(){
}
