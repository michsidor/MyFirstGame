#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <customrectangleshape.h>
#include <customcircleshape.h>
#include "text.h"


int main( )
{
    sf::Font font;
    sf::Music music;
    sf::Clock clock;
    sf::Texture texture;
    sf::Sprite sprite1;
    int zmienna = 0;
    int option = 0;
    float predkosc_pilki = 0;


    if (!music.openFromFile("C:\\Users\\michs\\Desktop\\NAUKA PROGRAMOWANIA\\sfml_official\\music.ogg")){
        return -1;
    }

    else{
        music.play();
    }

    if(!font.loadFromFile("C:\\Users\\michs\\Desktop\\NAUKA PROGRAMOWANIA\\menu\\build-menu-Desktop_Qt_5_13_2_MinGW_64_bit-Debug\\arial.ttf")){
                std::cout << "couldnt load a font" << std::endl;
    }

    if (!texture.loadFromFile("C:\\Users\\michs\\Desktop\\NAUKA PROGRAMOWANIA\\sfml_official\\background.jpg")) {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }


      sf::RenderWindow window(sf::VideoMode(482.0,800.0), "SidorGamesStudio");
      CustomRectangleShape prostokat_1({300.0,0.0},{0,0,0},{1,1},window,0,0);
      CustomRectangleShape prostokat_2({300.0,770.0},{0,0,0},{1,1},window,0,0);
      CustomCircleShape circle_1({100.0,400.0},{0,0,0},1,window,15,-15);
      Text text(font,"Play",100,sf::Color::Red,sf::Text::Bold,{150.0,150.0});
      Text text1(font,"Exit",100,sf::Color::White,sf::Text::Bold,{160.0,400.0});





    //main loop of program
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
                break;
            }
        }

        sf::Time elapsed = clock.restart();
        prostokat_1.animate_WSAD(elapsed);
        prostokat_2.animate_case(elapsed);


           if(circle_1.kolizja_y() > 30){
               circle_1.animate_FULLSCREEN(elapsed,predkosc_pilki);
           }
           else if( (circle_1.kolizja_y() == 30) and ( (circle_1.kolizja_x() > prostokat_1.kolizja(elapsed)) and (circle_1.kolizja_x() < prostokat_1.kolizja(elapsed)+100))){
               circle_1.animate_zero(elapsed,predkosc_pilki);
               predkosc_pilki = predkosc_pilki+0.3;
           }
           else{
               circle_1.animate_FULLSCREEN(elapsed,predkosc_pilki);
           }

           if(circle_1.kolizja_y() > 740){
               circle_1.animate_FULLSCREEN(elapsed,predkosc_pilki);
           }
           else if( (circle_1.kolizja_y() == 740) and ( (circle_1.kolizja_x() > prostokat_2.kolizja(elapsed)) and (circle_1.kolizja_x() < prostokat_2.kolizja(elapsed)+100))){
               circle_1.animate_zero(elapsed,predkosc_pilki);
               predkosc_pilki = predkosc_pilki+0.3;
           }
           else{
               circle_1.animate_FULLSCREEN(elapsed,predkosc_pilki);
           }

           if((circle_1.kolizja_y() == 0) || (circle_1.kolizja_y() == 770)){
               break;
           }


        window.clear( );
        window.draw(text);
        window.draw(text1);
        window.draw(sprite1);
        window.draw(circle_1);
        window.draw(prostokat_1);
        window.draw(prostokat_2);



        if(zmienna == 1){
        sprite1.setTexture(texture);
        prostokat_1.setFillColor({0,255,0});
        prostokat_2.setFillColor({255,0,0});
        prostokat_1.setSize({100.0,30.0});
        prostokat_2.setSize({100.0,30.0});
        circle_1.setRadius(15);
        circle_1.setFillColor({200,255,0});
        text.setCharacterSize(1);
        text.setFillColor(sf::Color::Blue);
        text1.setCharacterSize(1);
        text1.setFillColor(sf::Color::Blue);
}


        if(zmienna == 0){
            if(option == 0){
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
                     zmienna = 1;
                     predkosc_pilki = 8;
                    }
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
                        text.setFillColor(sf::Color::White);
                        text1.setFillColor(sf::Color::Red);
                        option = 1;
                    }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
                        text.setFillColor(sf::Color::Red);
                        text1.setFillColor(sf::Color::White);
                        option = 0;
                    }
            if(option == 1){
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
                     break;
                    }
            }
        }
        window.display( );
    }

    return 0;
}





