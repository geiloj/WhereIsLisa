//
// Created by Johann on 29.05.2026.
//

#ifndef CMAKESFMLPROJECT_GAME_HPP
#define CMAKESFMLPROJECT_GAME_HPP
#include <SFML/Graphics.hpp>
#include "Knight.hpp"

namespace Game {
    class Game {
        private:
        Knight m_knight;
        const unsigned int WINDOW_WIDTH;
        sf::RenderWindow window;
        public:
        explicit Game(const std::string& m_window_title, const unsigned int m_width) : m_knight(),
            WINDOW_WIDTH(m_width),
            window(sf::VideoMode({m_width * 16 / 9, m_width}), m_window_title) {
            window.setFramerateLimit(60);
        }

        explicit Game(const std::string& m_window_title) : m_knight(),
        WINDOW_WIDTH(200),
        window(sf::VideoMode({200, 200}), m_window_title){
            window.setFramerateLimit(60);
        }

        int run();
    };
} // Game

#endif //CMAKESFMLPROJECT_GAME_HPP