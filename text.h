#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


class Text : public sf::Text
{
public:
    Text(const sf::Font &font, const std::string napis, const int &size, const sf::Color &color,const sf::Uint32 style, const sf::Vector2f &position);
};

