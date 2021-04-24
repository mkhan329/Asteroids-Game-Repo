#include <Windows.h>
#include <math.h>
#include <cinder/app/KeyEvent.h>
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
        ci::gl::drawSolidTriangle(position_ + 40.0f * direction_,
                                  position_ + 16.0f * Rotate(direction_, 2.1),
                                  position_ + 16.0f * Rotate(direction_, -2.1));

        for(Projectile& p: projectiles_) {
            p.RenderProjectile();
        }
    }

    void Player::UpdatePlayer() {
        float r = glm::length(velocity_);

        if (GetKeyState(VK_RIGHT)) {
            direction_ = Rotate(direction_, k_rotation_speed_);
            acceleration_ = Rotate(acceleration_, k_rotation_speed_);
            if(GetKeyState(VK_UP) && r > 1.0f) {
                velocity_ = Rotate(velocity_, k_rotation_speed_);
            }
        }
        if (GetKeyState(VK_LEFT)) {
            direction_ = Rotate(direction_, -k_rotation_speed_);
            acceleration_ = Rotate(acceleration_, -k_rotation_speed_);
            if(GetKeyState(VK_UP) && r > 1.0f) {
                velocity_ = Rotate(velocity_, -k_rotation_speed_);
            }
        }

        if (GetKeyState(VK_UP)) {
            if(r < 6.0f) {
                velocity_ += acceleration_;
            }
        }

        velocity_ *= 0.999;
        //velocity_ -= 0.10f*acceleration_;
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

    void Player::Shoot() {
        if(projectiles_.size() < 10) {
            projectiles_.push_back(Projectile (position_, 12.0f*direction_));
        }
    }

    void Player::RemoveProjectile(size_t i) {
        projectiles_.erase(projectiles_.cbegin() + i);
    }

}