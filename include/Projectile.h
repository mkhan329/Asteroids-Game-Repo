#pragma once

#include <glm/vec2.hpp>
#include <cinder/Color.h>

#ifndef FINAL_PROJECT_PROJECTILE_H
#define FINAL_PROJECT_PROJECTILE_H
#endif //FINAL_PROJECT_PROJECTILE_H

namespace asteroids {

    class Projectile {
    public:
        Projectile(glm::vec2 position, glm::vec2 velocity, int radius, ci::Color color);
        void UpdateProjectile();
        void RenderProjectile();
        glm::vec2 GetPosition();
    private:
        ci::Color color_;
        int radius_;
        glm::vec2 position_;
        glm::vec2 velocity_;

    };

}