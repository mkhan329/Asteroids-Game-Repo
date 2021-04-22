#pragma once
#include <glm/vec2.hpp>
#include "cinder/gl/gl.h"
#ifndef FINAL_PROJECT_MKHAN329_ASTEROID_H
#define FINAL_PROJECT_MKHAN329_ASTEROID_H
#endif //FINAL_PROJECT_MKHAN329_ASTEROID_H

namespace asteroids {

    class Asteroid {
    public:
        Asteroid(ci::Color color, size_t radius, glm::vec2 velocity, glm::vec2 position);
        void RenderAsteroid();
        void UpdateAsteroid();
    private:
        ci::Color color_;
        size_t radius_;
        glm::vec2 velocity_;
        glm::vec2 position_;

    };

}



