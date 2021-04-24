#include "../include/Projectile.h"
#include "cinder/gl/gl.h"
namespace asteroids {

    Projectile::Projectile(glm::vec2 position, glm::vec2 velocity) {
        position_ = position;
        velocity_ = velocity;
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
        ci::gl::color(ci::Color("red"));
        ci::gl::drawSolidCircle(position_, 3);
    }
}