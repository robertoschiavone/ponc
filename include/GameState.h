#ifndef PONC_GAMESTATE_H
#define PONC_GAMESTATE_H

#include <string>

#include "Ball.h"
#include "Paddle.h"

#include <SFML/Window.hpp>

class GameState {
public:
    explicit GameState(int width, int height, std::string &title);

    const sf::Window *window();

    Paddle *paddleLeft();

    Paddle *paddleRight();

    Ball *ball();

    int *player1Score();

    int *player2Score();

private:
    Paddle *paddleLeft_;
    Paddle *paddleRight_;
    Ball *ball_;

    int *player1Score_;
    int *player2Score_;

    sf::Window *window_;
};

#endif //PONC_GAMESTATE_H
