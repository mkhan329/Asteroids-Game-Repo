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
        float r = 20.0f+10.0f*radius_;
        double sides = 7 + 2*radius_;

        for(int i = 0; i < sides; i++) {
            ci::gl::drawSolidTriangle(position_,
                                      position_ + r * Rotate(direction_, i*6.28/sides),
                                      position_ + r * Rotate(direction_, (i+1)*6.28/sides));
        }
    }

    void Asteroid::UpdateAsteroid() {
        position_ += velocity_;
        direction_ = Rotate(direction_, 0.01);

        if((position_.x > 1200.0 + 200.0 && velocity_.x > 0.0) || (position_.x < 0.0 - 200.0 && velocity_.x < 0.0)) {
            velocity_.x *= -1.0f;
        }
        if((position_.y > 800.0 + 200.0 && velocity_.y > 0.0) || (position_.y < 0.0 - 200.0 && velocity_.y < 0.0)) {
            velocity_.y *= -1.0f;
        }
    }

    glm::vec2 Asteroid::Rotate(glm::vec2 &vector, float theta) {
        float x = vector.x;
        float y = vector.y;
        return glm::vec2(x*cos(theta) - y*sin(theta), x*sin(theta) + y*cos(theta));
    }

}