#include <iomanip>
#include <iostream>
#include <random>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "include/GameState.h"

int main() {
    int width = 800;
    int height = 600;
    std::string title = "Pong by @iamrobschiavone";
    auto state = new GameState(width, height, title);
    auto *window = (sf::RenderWindow *) state->window();

    sf::Clock clock;
    sf::Time accumulator = sf::Time::Zero;
    sf::Time ups = sf::seconds(1.f / 60.f);

    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("bounce.wav")) {
        std::cerr << "Error loading sound file!" << std::endl;
    }

    sf::Sound bounce;
    bounce.setBuffer(buffer);

    sf::Font font;
    if (!font.loadFromFile("bit5x3.ttf")) {
        std::cerr << "Error loading font file!" << std::endl;
    }

    sf::Text text;
    text.setFont(font);
    text.setString("0   0");
    text.setCharacterSize(96);
    auto textWidth = text.getGlobalBounds().width;
    text.setPosition(float(width) / 2 - textWidth / 2, 20);

    std::random_device random_device;
    std::mt19937 random_engine{random_device()};
    std::bernoulli_distribution coin_distribution{0.175};

    while (window->isOpen()) {
        auto event = new sf::Event();
        while (window->pollEvent(*event)) {
            switch (event->type) {
                case sf::Event::Closed:
                    window->close();
                    break;
                case sf::Event::KeyPressed:
                    switch (event->key.code) {
                        case sf::Keyboard::Up:
                            state->paddleRight()->moveUp();
                            break;
                        case sf::Keyboard::Down:
                            state->paddleRight()->moveDown();
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
        }

        while (accumulator > ups) {
            accumulator -= ups;
            state->ball()->move(state->paddleLeft(), state->paddleRight(), state->player1Score(),
                                state->player2Score());

            if (coin_distribution(random_engine)) {
                if (state->ball()->shape()->getPosition().y > state->paddleLeft()->shape()->getPosition().y + 50) {
                    state->paddleLeft()->moveDown();
                } else {
                    state->paddleLeft()->moveUp();
                }
            }
        }

        std::stringstream newText;
        newText << std::setfill('0') << std::setw(2) << *state->player1Score()
                << "   " << std::setfill('0') << std::setw(2) << *state->player2Score();
        text.setString(newText.str());
        textWidth = text.getGlobalBounds().width;
        text.setPosition(float(width) / 2 - textWidth / 2, 20);

        window->clear(sf::Color::Black);
        window->draw(*state->paddleLeft()->shape());
        window->draw(*state->paddleRight()->shape());
        window->draw(*state->ball()->shape());
        window->draw(text);

        int separatorY = 0;
        while (separatorY < height - 40) {
            auto separator = sf::RectangleShape(sf::Vector2f(10, 40));
            separator.setPosition(float(width) / 2 - 5, float(separatorY));
            window->draw(separator);
            separatorY += 50;
        }

        if (state->ball()->playSound()) {
            bounce.play();
            state->ball()->playSound(false);
        }

        if (state->ball()->out()) {
            state->ball()->reset();
        }

        window->display();
        accumulator += clock.restart();
    }

    return 0;
}
