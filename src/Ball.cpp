#include <iostream>
#include "include/Ball.h"

Ball::Ball(int windowWidth, int windowHeight) {
    this->shape_ = new sf::RectangleShape(sf::Vector2f(20, 20));

    this->x = float(windowWidth) / 2 - 10;
    this->defaultX = x;

    this->y = float(windowHeight) / 2 - 10;
    this->defaultY = y;

    this->shape_->setPosition(x, y);

    this->out_ = false;
    this->playSound_ = false;

    this->dx = 3;
    this->dy = 3;

    this->windowWidth = windowWidth;
    this->windowHeight = windowHeight;
}

void Ball::playSound(bool v) {
    this->playSound_ = v;
}

bool Ball::playSound() {
    return this->playSound_;
}

bool Ball::out() {
    return this->out_;
}

const sf::Shape *Ball::shape() {
    return this->shape_;
}

void Ball::move(Paddle *paddleLeft, Paddle *paddleRight, int *player1Score, int *player2Score) {
    this->x += this->dx;
    this->y += this->dy;

    if (this->y > float(this->windowHeight) - 50) {
        this->y = float(this->windowHeight) - 50;
        this->dy *= -1;
        this->playSound_ = true;
    }

    if (this->y < 50) {
        this->y = 50;
        this->dy *= -1;
        this->playSound_ = true;
    }

    if (this->x > float(this->windowWidth) - 50) {
        this->out_ = true;
        this->dx *= -1;
        (*player1Score)++;
    }

    if (this->x < 50) {
        this->out_ = true;
        this->dx *= -1;
        (*player2Score)++;
    }

    if ((this->x > float(this->windowWidth) - 70) && (this->x < float(this->windowWidth) - 50) &&
        (this->y > paddleRight->y()) && (this->y < paddleRight->y() + 100)) {
        this->x = float(this->windowWidth) - 70;
        this->dx *= -1;
        this->playSound_ = true;
    }

    if ((this->x < 60) && (this->x > 50) &&
        this->y > paddleLeft->y() && (this->y < paddleLeft->y() + 100)) {
        this->x = 70;
        this->dx *= -1;
        this->playSound_ = true;
    }

    this->shape_->setPosition(x, y);
}

void Ball::reset() {
    this->out_ = false;
    this->x = this->defaultX;
    this->y = this->defaultY;
    this->dy = 3;
    this->shape_->setPosition(x, y);
}
