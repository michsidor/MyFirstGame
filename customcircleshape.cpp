#include "customcircleshape.h"


CustomCircleShape::CustomCircleShape(const sf::Vector2f &position, const sf::Color &color, const int &size, const sf::RenderWindow &window,const float &velocity_x, const float &velocity_y)
    : sf::CircleShape(int (size)), window_(window), velocity_x_(velocity_x), velocity_y_(velocity_y){
    setPosition(position);
    setFillColor(color);
}

void CustomCircleShape::animate_FULLSCREEN(const sf::Time &time, const float &x){
    float second = time.asSeconds();
    float it = x;

    sf::FloatRect rectangle_bounds = getGlobalBounds();

            if(rectangle_bounds.left < 0 || rectangle_bounds.left+rectangle_bounds.width > window_.getSize().x){
                velocity_x_ = -velocity_x_;
            }
            if(rectangle_bounds.top < 0 || rectangle_bounds.top+rectangle_bounds.height > window_.getSize().y){
                velocity_y_ = -velocity_y_;
            }
             move(it*velocity_x_ * second,it*velocity_y_ * second);


}

void CustomCircleShape::animate_zero(const sf::Time &time,const float &x){
    float second = time.asSeconds();
    float it =x;
           velocity_y_ = -velocity_y_;
           move(it*second*velocity_x_, it*second*velocity_y_);
        };

sf::Vector2f CustomCircleShape::GettingPosition(){
    sf::Vector2f curr_pos;
    curr_pos = sf::Transformable::getPosition();
    return curr_pos;
};

int CustomCircleShape::kolizja_y(){
    sf::Vector2f dimensions_of_circle = GettingPosition();
    int YDOF_int = dimensions_of_circle.y;
    return YDOF_int;
}
int CustomCircleShape::kolizja_x(){
    sf::Vector2f dimensions_of_circle = GettingPosition();
    int XDOF_int = dimensions_of_circle.x;
    return XDOF_int;
}


