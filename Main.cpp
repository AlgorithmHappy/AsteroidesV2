#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Asteroide.h>
#include <Nave.h>
#include <Corazones.h>
#include <Espacio.h>
#include <Explosion.h>
#include <Menu.h>
#include <Puntuacion.h>
#include <CajaTexto.h>
#include <sqlite3.h>

using namespace sf;

RenderWindow window(VideoMode(1280, 720), "Asteroides");
Music mscCancion;
SoundBuffer sndBClics;
Sound sndSonido;
sqlite3 *BD;
sqlite3_stmt *iterador;

void gameLoop();
void menuLoop();
void salidaLoop(int puntuacion);
int callBackSQL();
void botonPuntuacion();

int main(){
    mscCancion.openFromFile("recursos/space walk.ogg");
    mscCancion.play();
    mscCancion.setLoop(true);

    sndBClics.loadFromFile("recursos/Menu Selection Click.wav");
    sndSonido.setBuffer(sndBClics);

    if((sqlite3_open("recursos/BDAsteroides", &BD)) != SQLITE_OK){
        std::cout << "No se pudo cargar la base de datos BDAsteroides" << std::endl << sqlite3_errmsg(BD);
        sqlite3_close(BD);
    }

    menuLoop();
    mscCancion.stop();
    sqlite3_close(BD);
    return EXIT_SUCCESS;
}

void gameLoop(){
    bool gameOver = false;
    Asteroide asteroide;
    Espacio espacio;
    Nave nave(&asteroide);
    Corazones corazones(&nave);
    Explosion explosion;

    Clock rljEsperar;
    Puntuacion puntuacion;
    while(!gameOver){ // GameLoop
        Event e;

        while(window.pollEvent(e)){ // Procesamiento de eventos

            if(e.type == Event::Closed){
                window.close();
                exit(0);
            }

            if((e.type == Event::KeyPressed) && (e.key.code == Keyboard::Down))
                nave.mover(true);

            if((e.type == Event::KeyPressed) && (e.key.code == Keyboard::Up))
                nave.mover(false);

        }

        explosion.setPosicionExp(nave.getCarril());
        explosion.setVidaNave(nave.getVida());

        // Procesamiento de texturas
        window.clear(Color::Black);
        window.draw(espacio.getSprEspacio());
        window.draw(nave.getSprNave());
        window.draw(asteroide.getSprAsteroide());
        window.draw(corazones.getSprCorazon1());
        window.draw(corazones.getSprCorazon2());
        window.draw(corazones.getSprCorazon3());
        window.draw(puntuacion.getTxtPuntuacion());
        window.draw(explosion.getSprExplosion());
        window.display();

        if(nave.getVida() > 0)
            rljEsperar.restart();

        if(rljEsperar.getElapsedTime().asSeconds() >= 4)
            gameOver = true;

    }

    salidaLoop(puntuacion.getPuntuacion());
}

void menuLoop(){
    Menu menu;
    bool op = true;

    window.setMouseCursorVisible(false);

    while(op){
        Event e;

        while(window.pollEvent(e)){ // Procesamiento de eventos

            if(e.type == Event::Closed){
                window.close();
                exit(0);
            }

            if(menu.sprCursor.getGlobalBounds().intersects(menu.sprBotones[0].getGlobalBounds())){
                menu.sprBotones[0].setScale(1.2, 1.2);
                if(Mouse::isButtonPressed(Mouse::Left)){
                    op = false;
                    sndSonido.play();
                }
            }else
                menu.sprBotones[0].setScale(1.0, 1.0);

            if(menu.sprCursor.getGlobalBounds().intersects(menu.sprBotones[1].getGlobalBounds())){
                menu.sprBotones[1].setScale(1.2, 1.2);
                if(Mouse::isButtonPressed(Mouse::Left)){
                    system("START /max iexplore.exe https://www.facebook.com/Juegos-Geek-1890472260968691");
                    sndSonido.play();
                }
            }else
                menu.sprBotones[1].setScale(1.0, 1.0);

            if(menu.sprCursor.getGlobalBounds().intersects(menu.sprBotones[2].getGlobalBounds())){
                menu.sprBotones[2].setScale(1.2, 1.2);
                if(Mouse::isButtonPressed(Mouse::Left)){
                    system("START /max iexplore.exe paypal.me/LMarquezMendez");
                    sndSonido.play();
                }
            }else
                menu.sprBotones[2].setScale(1.0, 1.0);

            if(menu.sprCursor.getGlobalBounds().intersects(menu.sprBotones[3].getGlobalBounds())){
                menu.sprBotones[3].setScale(1.2, 1.2);
                if(Mouse::isButtonPressed(Mouse::Left)){
                    sndSonido.play();
                    botonPuntuacion();
                }
            }else
                menu.sprBotones[3].setScale(1.0, 1.0);

        }

        menu.sprCursor.setPosition(Vector2f(Mouse::getPosition(window)));

        window.clear(Color::Black);
        window.draw(menu.sprEspacio);
        for(int i = 0; i < 4; i++)
            window.draw(menu.sprBotones[i]);

        window.draw(menu.sprCursor);
        window.display();
    }

    window.setMouseCursorVisible(true);
    gameLoop();
}

void salidaLoop(int puntuacion){
    CajaTexto cajaTexto;
    bool op = true;
    std::string strNick = "";
    std::stringstream ss;
    ss << puntuacion;
    std::string str = ss.str();
    cajaTexto.txtPuntuacion.setString(str);

    window.setMouseCursorVisible(false);

    while(op){
        Event e;

        while(window.pollEvent(e)){ // Procesamiento de eventos

            if(e.type == Event::Closed){
                window.close();
                exit(0);
            }

            if(cajaTexto.sprCursor.getGlobalBounds().intersects(cajaTexto.sprBotonGuardar.getGlobalBounds())){
                cajaTexto.sprBotonGuardar.setScale(1.2, 1.2);
                if(Mouse::isButtonPressed(Mouse::Left)){
                    sndSonido.play();
                    // -------------SQLite------------ //
                    std::string consulta = "insert into Puntuaciones (nickname, puntuacion) values ('";
                    consulta += strNick;
                    consulta += "', ";
                    consulta += str;
                    consulta += ");";
                    if(sqlite3_exec(BD, consulta.c_str(), 0, 0, 0) != SQLITE_OK){
                        std::cout << "No se pudo guardar la puntuacion" << std::endl << sqlite3_errmsg(BD);
                    }
                    menuLoop();
                }
            }else
                cajaTexto.sprBotonGuardar.setScale(1.0, 1.0);

            if(cajaTexto.sprCursor.getGlobalBounds().intersects(cajaTexto.sprBotonOmitir.getGlobalBounds())){
                cajaTexto.sprBotonOmitir.setScale(1.2, 1.2);
                if(Mouse::isButtonPressed(Mouse::Left)){
                    sndSonido.play();
                    menuLoop();
                }
            }else
                cajaTexto.sprBotonOmitir.setScale(1.0, 1.0);

            if(e.type == Event::TextEntered){
                if (e.text.unicode < 128){
                    if(e.text.unicode == 8){
                        if(!strNick.empty())
                            strNick.erase(strNick.length() - 1);
                    }
                    else{
                        strNick += char(e.text.unicode);
                    }
                    cajaTexto.setTxtIngresado(strNick);
                }
            }

        }

        cajaTexto.sprCursor.setPosition(Vector2f(Mouse::getPosition(window)));

        window.clear(Color::Black);
        window.draw(cajaTexto.sprEspacio);
        window.draw(cajaTexto.txtPuntuacion);
        window.draw(cajaTexto.sprBotonOmitir);
        window.draw(cajaTexto.sprBotonGuardar);
        window.draw(cajaTexto.txtTexto);
        window.draw(cajaTexto.sprRectangulo);
        window.draw(cajaTexto.txtIngresado);
        window.draw(cajaTexto.sprCursor);
        window.display();
    }

    window.setMouseCursorVisible(true);
}

void botonPuntuacion(){
    bool atras = false;
    char *aux;
    std::string strPuntuaciones = "";
    Texture txtrFondo, txtrBoton, txtrCursor;
    Sprite sprFondo, sprBoton, sprCursor;
    Font fntFuente;
    Text txtTexto;

    if(!txtrFondo.loadFromFile("recursos/espacio2.png"))
        std::cout << "No se pudo cargar la textura espacio2.png";
    sprFondo.setTexture(txtrFondo);
    sprFondo.setScale(0.467836257, 0.467836257);

    if(!txtrBoton.loadFromFile("recursos/atras.png"))
        std::cout << "No se pudo cargar la textura atras.png";
    sprBoton.setTexture(txtrBoton);
    sprBoton.setPosition(1280 - 300, 720 - 132);

    if(!txtrCursor.loadFromFile("recursos/cursor.png"))
        std::cout << "No se pudo cargar la textura atras.png";
    sprCursor.setTexture(txtrCursor);

    if(!fntFuente.loadFromFile("recursos/neuropol.ttf"))
        std::cout << "No se pudo cargar la fuente neuropol.ttf";
    txtTexto.setFont(fntFuente);
    if(sqlite3_prepare_v2(BD, "SELECT * FROM Puntuaciones;", -1, &iterador, NULL) != SQLITE_OK)
        std::cout << "No se pudo generar la consulta" << std::endl << sqlite3_errmsg(BD);
    else{
        while(sqlite3_step(iterador) == SQLITE_ROW){
            aux = (char*)sqlite3_column_text(iterador, 0);
            strPuntuaciones += aux;
            strPuntuaciones += "\t";
            aux = (char*)sqlite3_column_text(iterador, 1);
            strPuntuaciones += aux;
            strPuntuaciones += "\n";
        }
        sqlite3_finalize(iterador);
    }
    txtTexto.setString(strPuntuaciones);
    txtTexto.setPosition(500, 50);

    while(!atras){
        Event e;
        while(window.pollEvent(e)){
            if(e.type == Event::Closed){
                window.close();
                exit(0);
            }

            if(sprCursor.getGlobalBounds().intersects(sprBoton.getGlobalBounds())){
                sprBoton.setScale(1.2, 1.2);
                if(Mouse::isButtonPressed(Mouse::Left)){
                    sndSonido.play();
                    menuLoop();
                }
            }
            else
                sprBoton.setScale(1, 1);
        }

        sprCursor.setPosition(Vector2f(Mouse::getPosition(window)));

        window.clear(Color::Black);
        window.draw(sprFondo);
        window.draw(txtTexto);
        window.draw(sprBoton);
        window.draw(sprCursor);
        window.display();
    }
}




