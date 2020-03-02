#include "include/Paddle.h"

#include <algorithm>

Paddle::Paddle(int windowHeight, float x, float y) {
    this->shape_ = new sf::RectangleShape(sf::Vector2f(20, 100));
    this->x_ = x;
    this->y_ = y;
    this->shape_->setPosition(x, y);
    this->windowHeight = windowHeight;
}

sf::Shape *Paddle::shape() {
    return this->shape_;
}

float Paddle::x() {
    return this->x_;
}

float Paddle::y() {
    return this->y_;
}

void Paddle::moveUp() {
    this->y_ = std::max(50.f, this->y_ - 20);
    this->shape_->setPosition(this->x_, this->y_);
}

void Paddle::moveDown() {
    this->y_ = std::min(float(this->windowHeight) - 150.f, this->y_ + 20);
    this->shape_->setPosition(this->x_, this->y_);
}
