#include "../include/Asteroid.h"

namespace asteroids {

    Asteroid::Asteroid(ci::Color color, size_t radius, glm::vec2 velocity, glm::vec2 position) {
        color_ = color;
        radius_ = radius;
        velocity_ = velocity;
        position_ = position;
    }

    void Asteroid::RenderAsteroid() {
        ci::gl::color(ci::Color(color_));
        ci::gl::drawStrokedCircle(position_, radius_);
    }

    void Asteroid::UpdateAsteroid() {
        position_ += velocity_;

        if((position_.x > 1200.0 + 200.0 && velocity_.x > 0.0) || (position_.x < 0.0 - 200.0 && velocity_.x < 0.0)) {
            velocity_.x *= -1.0f;
        }
        if((position_.y > 800.0 + 200.0 && velocity_.y > 0.0) || (position_.y < 0.0 - 200.0 && velocity_.y < 0.0)) {
            velocity_.y *= -1.0f;
        }
    }

}