#include "../include/Projectile.h"
#include "cinder/gl/gl.h"
namespace asteroids {

    Projectile::Projectile(glm::vec2 position, glm::vec2 velocity, int radius, ci::Color color) {
        position_ = position;
        velocity_ = velocity;
        radius_ = radius;
        color_ = color;
    }

    void Projectile::UpdateProjectile() {
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

    void Projectile::RenderProjectile() {
        ci::gl::color(color_);
        ci::gl::drawSolidCircle(position_, radius_);
    }

    glm::vec2 Projectile::GetPosition() {
        return position_;
    }
}