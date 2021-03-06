#pragma once

#include <vector>
#include "../include/Asteroid.h"
#include "../include/Player.h"
#ifndef FINAL_PROJECT_MKHAN329_SPACEARENA_H
#define FINAL_PROJECT_MKHAN329_SPACEARENA_H
#endif //FINAL_PROJECT_MKHAN329_SPACEARENA_H

namespace asteroids {

    class SpaceArena {
    public:
        void Update();
        void Display();
        void AddAsteroid(Asteroid& a);
        void RemoveAsteroid(size_t i);
        int SignalSound();
        glm::vec2 Rotate(glm::vec2 vector, float theta);
        Player player_ = Player();
    private:
        std::vector<Asteroid> asteroids_;
        std::vector<Projectile> power_ups_;
        int score_ = 0;
        int lives_ = 3;
        int crash = -1;
        bool power_up_ = false;

    };

}



