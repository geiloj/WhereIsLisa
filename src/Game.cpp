//
// Created by Johann on 29.05.2026.
//

#include "Game.hpp"

namespace Game {
    int Game::run() {
        while ( window.isOpen() )
        {
            while ( const std::optional event = window.pollEvent() )
            {
                if ( event->is<sf::Event::Closed>() ) {
                    window.close();
                    return 0;
                }
            }


            window.clear();
            window.display();
        }
        return -1;
    }
}
