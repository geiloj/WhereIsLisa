//
// Created by Johann on 29.05.2026.
//

#include "Game.hpp"

namespace Game {
    int Game::run() {
        int frame = 0;
        m_knight.setScale({7,7});
        while ( window.isOpen() )
        {
            frame++;
            m_knight.input();
            while ( const std::optional event = window.pollEvent() )
            {
                if ( event->is<sf::Event::Closed>() ) {
                    window.close();
                    return 0;
                }
            }

            window.clear();
            m_knight.nextFrame(frame);
            window.draw(m_knight.getSprite());
            window.display();
        }
        return -1;
    }
}
