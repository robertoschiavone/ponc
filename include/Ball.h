#ifndef PONC_BALL_H
#define PONC_BALL_H

#include <SFML/Graphics.hpp>

#include "include/Paddle.h"

class Ball {
public:
    explicit Ball(int windowWidth, int windowHeight);

    void playSound(bool v);

    bool out();

    bool playSound();

    const sf::Shape *shape();

    void move(Paddle *paddleLeft, Paddle *paddleRight, int *player1Score, int *player2Score);

    void reset();

private:
    sf::Shape *shape_;
    float x;
    float y;
    float defaultY;
    float defaultX;
    float dx;
    float dy;
    int windowWidth;
    int windowHeight;
    bool out_;
    bool playSound_;
};

#endif // PONC_BALL_H
