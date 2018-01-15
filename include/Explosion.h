#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

class Explosion{
    public:
        Explosion();
        Sprite getSprExplosion();
        void setPosicionExp(int _posicionNave);
        void setVidaNave(int _vidaNave);
        virtual ~Explosion();

    //protected:

    private:
        int tipoExplosion, posicionNave, vidaNave, contador;
        Texture txtrExplosion[3];
        Sprite sprExplosion[3];
        SoundBuffer sndBuffer;
        Sound sndExplosion;
        Vector2i vctNumSprite;
        Clock rljFrameRate;
        void actualizarSprite();
};

#endif // EXPLOSION_H
