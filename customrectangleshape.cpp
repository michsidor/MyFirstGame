#include "customrectangleshape.h"

CustomRectangleShape::CustomRectangleShape(const sf::Vector2f &position, const sf::Color &color, const sf::Vector2f &size, const sf::RenderWindow &window, const float &velocity_x, const float &velocity_y)
    : sf::RectangleShape(sf::Vector2f (size)), window_(window), velocity_x_(velocity_x), velocity_y_(velocity_y){
    setPosition(position);
    setFillColor(color);
}

// WSAD control
void CustomRectangleShape::animate_WSAD(const sf::Time &time){
    float second = time.asSeconds();
    velocity_x_ = 0;
    velocity_y_ = 0;
    sf::FloatRect rectangle_bounds = getGlobalBounds();    
           if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
               if(rectangle_bounds.left < 0){
                   velocity_x_ = 0;
                   velocity_y_ = 0;
               }
               else{
                   velocity_y_ = 0;
                   velocity_x_ = -20;
               }

                }
           if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
               if(rectangle_bounds.left+rectangle_bounds.width > window_.getSize().x){
                   velocity_x_ = 0;
                   velocity_y_ = 0;
               }

               else{
                   velocity_y_ = 0;
                   velocity_x_ = 20;
               }
                }
           move(20*velocity_x_ * second,20*velocity_y_ * second);
        };
// UpAndDown case control
void CustomRectangleShape::animate_case(const sf::Time &time){
    float second = time.asSeconds();
    velocity_x_ = 0;
    velocity_y_ = 0;
    sf::FloatRect rectangle_bounds = getGlobalBounds();
           if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
               if(rectangle_bounds.left < 0){
                   velocity_x_ = 0;
                   velocity_y_ = 0;
               }
               else{
                   velocity_y_ = 0;
                   velocity_x_ = -20;
               }
                }
           if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
               if(rectangle_bounds.left+rectangle_bounds.width > window_.getSize().x){
                   velocity_x_ = 0;
                   velocity_y_ = 0;
               }

               else{
                   velocity_y_ = 0;
                   velocity_x_ = 20;
               }
                }
           move(20*velocity_x_ * second,20*velocity_y_ * second);
        };

sf::Vector2f CustomRectangleShape::GettingPosition(){
    sf::Vector2f curr_pos;
    curr_pos = sf::Transformable::getPosition();
    return curr_pos;
};

void CustomRectangleShape::animate_zero(const sf::Time &time){
    float second = time.asSeconds();
           move(0*second,0*second);
        };


int CustomRectangleShape::kolizja(const sf::Time &time){
    sf::Vector2f dimensions_of_rectangle = GettingPosition();
    int XDOF_int = dimensions_of_rectangle.x;
    return XDOF_int;
}
