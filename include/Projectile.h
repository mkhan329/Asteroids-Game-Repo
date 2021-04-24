#pragma once

#include <glm/vec2.hpp>

#ifndef FINAL_PROJECT_PROJECTILE_H
#define FINAL_PROJECT_PROJECTILE_H
#endif //FINAL_PROJECT_PROJECTILE_H

namespace asteroids {

    class Projectile {
    public:
        Projectile(glm::vec2 position, glm::vec2 velocity);
        void UpdateProjectile();
        void RenderProjectile();
    private:
        glm::vec2 position_;
        glm::vec2 velocity_;

    };

}