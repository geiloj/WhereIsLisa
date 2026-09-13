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
    int m_frameWidth = 15;
    int m_frameHeight = 19;
    const int m_xOffset = 41;
    const int m_yOffset = 38;
    float m_SPEED = 5;
    int m_currentFrame = 0;
    int m_totalFrames = 6;
    int m_animationSpeed = 10;
    void changeSpriteInfo(const int animationSpeed, const int frameWidth, const int frameHeight, const int totalFrames) {
        m_animationSpeed = animationSpeed;
        m_frameWidth = frameWidth;
        m_frameHeight = frameHeight;
        m_totalFrames = totalFrames;
    }

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
        if (frameIndex >= 0 && frameIndex < m_totalFrames) {
            m_currentFrame = frameIndex;
            sprite.setTextureRect(sf::IntRect({m_currentFrame * 100 + m_xOffset, m_yOffset}, {m_frameWidth, m_frameHeight}));
        }
    }


    void nextFrame(const int frame) {
        if (frame%(60/m_animationSpeed) == 0) {
            setFrame((m_currentFrame + 1) % m_totalFrames);
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
                changeSpriteInfo(5, 15, 19, 6);
                break;
            case ATTACK1:
                changeSpriteInfo(10, 30, 24, 6);
                break;
            case ATTACK2:
                changeSpriteInfo(10, 15, 19, 6);
            case DEATH:
                changeSpriteInfo(3, 24, 19, 4);
                break;
            case DAMAGE:
                changeSpriteInfo(7, 15, 19, 4);
                break;
            case RUNNING:
                changeSpriteInfo(5, 15, 19, 8);
                break;
            case ATTACK3:
                changeSpriteInfo(5, 15, 19, 9);
        }
        if (m_currentFrame >= m_totalFrames) {
            m_currentFrame = m_totalFrames;
        }
    }
};


#endif //CMAKESFMLPROJECT_KNIGHT_HPP