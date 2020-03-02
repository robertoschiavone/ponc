#ifndef PONC_PADDLE_H
#define PONC_PADDLE_H

#include <SFML/Graphics.hpp>

class Paddle {
public:
    explicit Paddle(int windowHeight, float x, float y);

    sf::Shape *shape();

    float x();

    float y();

    void moveUp();

    void moveDown();

private:
    sf::Shape *shape_;
    float x_;
    float y_;
    int windowHeight;
};

#endif // PONC_PADDLE_H
