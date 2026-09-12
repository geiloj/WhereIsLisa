//
// Created by Johann on 29.05.2026.
//

#ifndef CMAKESFMLPROJECT_KNIGHT_HPP
#define CMAKESFMLPROJECT_KNIGHT_HPP

#include <SFML/Graphics.hpp>

class Knight {
private:
    std::vector<std::unique_ptr<sf::Texture>> textures;
    sf::Sprite sprite;
    int currentFrame = 0;
    const int frameWidth = 100;
    const int frameHeight = 100;
    const int totalFrames = 6;
public:
    explicit Knight(const std::string& path) :
    sprite(*std::make_unique<sf::Texture>(path)) {
        auto texture = std::make_unique<sf::Texture>();
        if (texture->loadFromFile(path)) {
            textures.push_back(std::move(texture));
            sprite.setTexture(*textures.back());
        }
    }
    // Wählt einen spezifischen Frame aus (0 bis 5)
    void setFrame(int frameIndex) {
        if (frameIndex >= 0 && frameIndex < totalFrames) {
            currentFrame = frameIndex;
            sprite.setTextureRect(sf::IntRect({currentFrame * frameWidth, 0}, {frameWidth, frameHeight}));
        }
    }

    // Hilfsfunktion zur einfachen Animation
    void nextFrame() {
        setFrame((currentFrame + 1) % totalFrames);
    }

    // Verhindert das Reallokations-Dilemma:
    // Gibt eine Referenz auf das Sprite für draw() zurück
    const sf::Sprite& getSprite() const {
        return sprite;
    }
    void setScale(const sf::Vector2f& scale) {
        sprite.setScale(scale);
    }
};


#endif //CMAKESFMLPROJECT_KNIGHT_HPP