#include <Windows.h>
#include <math.h>
#include "../include/Player.h"
#include "cinder/gl/gl.h"
namespace asteroids {

    Player::Player() {

    }

    glm::vec2 Player::Rotate(glm::vec2& vector, float theta) {
        float x = vector.x;
        float y = vector.y;
        return glm::vec2(x*cos(theta) - y*sin(theta), x*sin(theta) + y*cos(theta));
    }

    void Player::RenderPlayer() {
        ci::gl::color(ci::Color("white"));
        if (GetKeyState(VK_UP)) {
            ci::gl::color(ci::Color("orange"));
        }
        ci::gl::drawSolidTriangle(position_ + 50.0f * direction_,
                                  position_ + 20.0f * Rotate(direction_, 2.1),
                                  position_ + 20.0f * Rotate(direction_, -2.1));
    }

    void Player::UpdatePlayer() {

        if (GetKeyState(VK_RIGHT)) {
            direction_ = Rotate(direction_, 0.05);
            acceleration_ = Rotate(acceleration_, 0.05);
            if(GetKeyState(VK_UP)) {
                velocity_ = Rotate(velocity_, 0.05);
            }
        }
        if (GetKeyState(VK_LEFT)) {
            direction_ = Rotate(direction_, -0.05);
            acceleration_ = Rotate(acceleration_, -0.05);
            if(GetKeyState(VK_UP)) {
                velocity_ = Rotate(velocity_, -0.05);
            }
        }

        if (GetKeyState(VK_UP)) {
            float r = sqrt(velocity_.x*velocity_.x + velocity_.y*velocity_.y);
            if(r < 6.0f) {
                velocity_ += acceleration_;
            }
        } else {
            velocity_ *= 0.995;
        }

        position_ += velocity_;

        if(position_.x > 1200.0 && velocity_.x > 0.0) {
            position_.x = 0;
        }
        if(position_.x < 0.0 && velocity_.x < 0.0) {
            position_.x = 1200;
        }
        if(position_.y > 800.0 && velocity_.y > 0.0) {
            position_.y = 0.0;
        }
        if(position_.y < 0.0 && velocity_.y < 0.0) {
            position_.y = 800.0;
        }
    }
}