#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class CustomCircleShape : public sf::CircleShape
{
public:
    CustomCircleShape(const sf::Vector2f &position, const sf::Color &color, const int &size, const sf::RenderWindow &window, const float &velocity_x, const float &velocity_y);
    void animate_FULLSCREEN(const sf::Time &time, const float &x);
    void animate_zero(const sf::Time &time, const float &x);
    sf::Vector2f GettingPosition();
    int kolizja_y();
    int kolizja_x();


private:
    const sf::RenderWindow &window_;
    float velocity_x_;
    float velocity_y_;

};


