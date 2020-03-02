#include "include/GameState.h"

#include <iostream>

GameState::GameState(int width, int height, std::string &title) {
    this->window_ = new sf::RenderWindow(sf::VideoMode(width, height), title);
    this->window_->setFramerateLimit(60);

    this->paddleLeft_ = new Paddle(height, 50, float(height) / 2 - 50);
    this->paddleRight_ = new Paddle(height, float(width) - 60, float(height) / 2 - 50);
    this->ball_ = new Ball(width, height);

    this->player1Score_ = new int(0);
    this->player2Score_ = new int(0);
}

const sf::Window *GameState::window() {
    return this->window_;
}

Paddle *GameState::paddleLeft() {
    return this->paddleLeft_;
}

Paddle *GameState::paddleRight() {
    return this->paddleRight_;
}

Ball *GameState::ball() {
    return this->ball_;
}

int *GameState::player1Score() {
    return this->player1Score_;
}

int *GameState::player2Score() {
    return this->player2Score_;
}
