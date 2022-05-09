#include "text.h"




Text::Text(const sf::Font &font, const std::string napis, const int &size, const sf::Color &color,const sf::Uint32 style, const sf::Vector2f &position)
{
  setFont(font);
  setString(napis);
  setCharacterSize(size);
  setFillColor(color);
  setStyle(style);
  setPosition(position);

}
