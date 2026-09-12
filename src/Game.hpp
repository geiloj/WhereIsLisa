//
// Created by Johann on 29.05.2026.
//

#ifndef CMAKESFMLPROJECT_GAME_HPP
#define CMAKESFMLPROJECT_GAME_HPP
#include <SFML/Graphics.hpp>

namespace Game {
    class Game {
        private:
        const unsigned int WINDOW_WIDTH;
        sf::RenderWindow window;
        public:
        explicit Game(const std::string& m_window_title, const unsigned int m_width) :
        WINDOW_WIDTH(m_width),
        window(sf::VideoMode({m_width*16/9, m_width}), m_window_title){}

        explicit Game(const std::string& m_window_title) :
        WINDOW_WIDTH(200),
        window(sf::VideoMode({200, 200}), m_window_title){
        }

        int run();
    };
} // Game

#endif //CMAKESFMLPROJECT_GAME_HPP