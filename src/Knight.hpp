//
// Created by Johann on 29.05.2026.
//

#ifndef CMAKESFMLPROJECT_KNIGHT_HPP
#define CMAKESFMLPROJECT_KNIGHT_HPP

#include <SFML/Graphics.hpp>
#include <cmath>
#ifdef DEBUG
#include <iostream>
#define print(x) std::cout << x << std::endl
#else
#define print(x)
#endif

class Knight {
private:
    enum states {
        IDLE,
        RUNNING,
        ATTACK1,
        ATTACK2,
        ATTACK3,
        DAMAGE,
        DEATH
    };
    std::string path = "ressources/Characters(100x100)/Soldier/Soldier/";

    std::string files[7] = {
        "Soldier-Idle.png",
        "Soldier-Walk.png",
        "Soldier-Attack01.png",
        "Soldier-Attack02.png",
        "Soldier-Attack03.png",
        "Soldier-Hurt.png",
        "Soldier-Death.png"
    };
    states state = IDLE;
    std::unordered_map<states, std::unique_ptr<sf::Texture>> textures;
    sf::Sprite sprite;
    const int frameWidth = 15;
    const int frameHeight = 19;
    const int xOffset = 41;
    const int yOffset = 38;
    float SPEED = 5;
    int currentFrame = 0;
    int totalFrames = 6;
    int animationSpeed = 10;

public:
    void input();

    explicit Knight() :
    sprite(*std::make_unique<sf::Texture>(path+files[0])) {
        for (int i = IDLE; i <= DEATH; i++) {
            print("loading ressources for Knight...");
            auto texture = std::make_unique<sf::Texture>();
            if (texture->loadFromFile(path + files[i])) {
                textures.insert({static_cast<states>(i), std::move(texture)});
            }
        }
        sprite.setTexture(*textures[state]);
        print("done");
    }

    void setFrame(const int frameIndex) {
        if (frameIndex >= 0 && frameIndex < totalFrames) {
            currentFrame = frameIndex;
            sprite.setTextureRect(sf::IntRect({currentFrame * 100 + xOffset, yOffset}, {frameWidth, frameHeight}));
        }
    }


    void nextFrame(const int frame) {
        if (frame%(60/animationSpeed) == 0) {
            setFrame((currentFrame + 1) % totalFrames);
        }
    }

    const sf::Sprite& getSprite() const {
        return sprite;
    }
    void setScale(const sf::Vector2f& scale) {
        sprite.setScale(scale);
    }
    void changeState(const states newState) {
        state = newState;
        sprite.setTexture(*textures[newState]);
        switch (newState) {
            case IDLE:
            case ATTACK1:
            case ATTACK2:
                animationSpeed = 10;
                totalFrames = 6;
                break;
            case DEATH:
                animationSpeed = 5;
            case DAMAGE:
                animationSpeed = 7;
                totalFrames = 4;
                break;
            case RUNNING:
                totalFrames = 8;
                break;
            case ATTACK3:
                totalFrames = 9;
        }
        if (currentFrame >= totalFrames) {
            currentFrame = 0;
        }
    }
};


#endif //CMAKESFMLPROJECT_KNIGHT_HPP