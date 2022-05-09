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
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
                if(rectangle_bounds.top < 0){
                    velocity_x_ = 0;
                    velocity_y_ = 0;
                }
                else{
                    velocity_x_ = 0;
                    velocity_y_ = -20;
                }

        }
           if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
               if(rectangle_bounds.top+rectangle_bounds.height > window_.getSize().y){
                   velocity_x_ = 0;
                   velocity_y_ = 0;
               }
               else{
                   velocity_x_ = 0;
                   velocity_y_ = 20;
               }

                }
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
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                if(rectangle_bounds.top < 0){
                    velocity_x_ = 0;
                    velocity_y_ = 0;
                }
                else{
                    velocity_x_ = 0;
                    velocity_y_ = -20;
                }

        }
           if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
               if(rectangle_bounds.top+rectangle_bounds.height > window_.getSize().y){
                   velocity_x_ = 0;
                   velocity_y_ = 0;
               }
               else{
                   velocity_x_ = 0;
                   velocity_y_ = 20;
               }

                }
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
// RandomControl
void CustomRectangleShape::animate_static(const sf::Time &time){
float second = time.asSeconds();
        sf::FloatRect rectangle_bounds = getGlobalBounds();

                if(rectangle_bounds.left < 0 || rectangle_bounds.left+rectangle_bounds.width > window_.getSize().x){
                    velocity_x_ = -velocity_x_;
                }
                if(rectangle_bounds.top < 0 || rectangle_bounds.top+rectangle_bounds.height > window_.getSize().y){
                    velocity_y_ = -velocity_y_;
                }
                 move(15*velocity_x_ * second,15*velocity_y_ * second);
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


float CustomRectangleShape::kolizja(const sf::Time &time){
    sf::Vector2f dimensions_of_rectangle = GettingPosition();
    int XDOF11_int = dimensions_of_rectangle.x;
    int YDOF11_int = dimensions_of_rectangle.y;
    std::cout << "X: " << XDOF11_int << ", Y:" << YDOF11_int << std::endl;
// if( (XDOF1_int + 200.0 == XDOF2_int) and ((YDOF2_int-YDOF1_int)) < 50  and ((YDOF1_int-YDOF2_int) < 50) ){
//     std::cout << "CollisionX" << std::endl;
//     animate_zero(time);
//     if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
//         animate_WSAD(time);
//         animate_case(time);
//     }
//  }

// else if( (XDOF2_int + 200.0 == XDOF1_int) and ((YDOF2_int-YDOF1_int)) < 50  and ((YDOF1_int-YDOF2_int) < 50) ){
//      std::cout << "CollisionX" << std::endl;
//      animate_zero(time);
//      if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
//          animate_WSAD(time);
//          animate_case(time);
//     }
//  }

// else if(((YDOF2_int + 50) == YDOF1_int) and ((XDOF2_int-XDOF1_int) < 50 ) and ((XDOF1_int-XDOF2_int) < 50 )){
//     std::cout << "CollisionY" << std::endl;
//     animate_zero(time);
//     if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
//         animate_WSAD(time);
//         animate_case(time);
//    }
// }

// else if(((YDOF1_int + 50) == YDOF2_int) and ((XDOF2_int-XDOF1_int) < 50 ) and ((XDOF1_int-XDOF2_int) < 50 )){
//     std::cout << "CollisionY" << std::endl;
//     animate_zero(time);
//     if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
//         animate_WSAD(time);
//         animate_case(time);
//    }
// }


// else {
//    animate_WSAD(time);
//    animate_case(time);
// };

}
