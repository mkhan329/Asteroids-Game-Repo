#pragma once

#include <glm/vec2.hpp>

#ifndef FINAL_PROJECT_MKHAN329_PLAYER_H
#define FINAL_PROJECT_MKHAN329_PLAYER_H
#endif //FINAL_PROJECT_MKHAN329_PLAYER_H

namespace asteroids {

    class Player {
    public:
        Player();
        void RenderPlayer();
        void UpdatePlayer();
        glm::vec2 Rotate(glm::vec2& vector, float r);
    private:
        glm::vec2 position_ = glm::vec2(400.0, 400.0);
        glm::vec2 velocity_ = glm::vec2(0.0, 0.0);
        glm::vec2 direction_ = glm::vec2(1.0, 0.0);
        glm::vec2 acceleration_ = glm::vec2(0.05, 0.0);

    };

}