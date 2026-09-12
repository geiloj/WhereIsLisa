//
// Created by Johann on 29.05.2026.
//

#include "Knight.hpp"

#include <iostream>

void Knight::input() {
    changeState(IDLE);

    float scaleX = std::abs(sprite.getScale().x);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        changeState(RUNNING);
        if (sprite.getScale().x < 0) {
            sprite.move({static_cast<float>(-frameWidth*5), 0});
            std::cout << "eins\n";
        }
        sprite.setScale({scaleX, sprite.getScale().y});
        sprite.move({SPEED, 0});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        changeState(RUNNING);
        if (sprite.getScale().x > 0) {
            std::cout << "zwei\n";
            sprite.move({static_cast<float>(frameWidth*5), 0});
        }
        sprite.setScale({-scaleX, sprite.getScale().y});
        sprite.move({-SPEED, 0});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        changeState(RUNNING);
        sprite.move({0, -SPEED});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        changeState(RUNNING);
        sprite.move({0, SPEED});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P)) {
        changeState(RUNNING);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::O)) {
        changeState(DEATH);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::I)) {
        changeState(IDLE);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::K)) {
        changeState(ATTACK1);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::L)) {
        changeState(ATTACK2);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::J)) {
        changeState(ATTACK3);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::B)) {
        changeState(DAMAGE);
    }

}
