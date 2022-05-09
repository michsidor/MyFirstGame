#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class CustomRectangleShape : public sf::RectangleShape
{
public:
    CustomRectangleShape(const sf::Vector2f &position, const sf::Color &color, const sf::Vector2f &size, const sf::RenderWindow &window, const float &velocity_x, const float &velocity_y);

    void animate_WSAD(const sf::Time &time);
    void animate_case(const sf::Time &time);
    void animate_zero(const sf::Time &time);
    sf::Vector2f GettingPosition();
    int kolizja(const sf::Time &time);

private:
    const sf::RenderWindow &window_;
    float velocity_x_;
    float velocity_y_;
};





