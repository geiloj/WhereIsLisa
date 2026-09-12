//
// Created by Johann on 29.05.2026.
//

#include "Game.hpp"

namespace Game {
    int Game::run() {
        int count = 0;
        m_knight.setScale({5,5});
        while ( window.isOpen() )
        {
            count++;
            while ( const std::optional event = window.pollEvent() )
            {
                if ( event->is<sf::Event::Closed>() ) {
                    window.close();
                    return 0;
                }
            }


            window.clear();
            if (count%10 == 0) {
                m_knight.nextFrame();
            }
            window.draw(m_knight.getSprite());

            window.display();
        }
        return -1;
    }
}
