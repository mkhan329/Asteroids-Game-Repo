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
    private:
        std::vector<Asteroid> asteroids_;
        Player player_ = Player();


    };

}



