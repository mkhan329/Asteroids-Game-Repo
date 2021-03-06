#include "../include/SpaceArena.h"

namespace asteroids {

    void SpaceArena::Display() {
        ci::gl::drawStringCentered(std::to_string(score_), glm::vec2(80, 30),ci::Color("white"), ci::Font("Roboto", 50));
        ci::gl::color(ci::Color("white"));
        for (int i = 0; i < lives_; i++) {
            ci::gl::drawSolidTriangle(glm::vec2(50 + 30*i, 100) + 20.0f * glm::vec2(0, -1),
                                      glm::vec2(50 + 30*i, 100) + 8.0f * Rotate(glm::vec2(0, -1), 2.1),
                                      glm::vec2(50 + 30*i, 100) + 8.0f * Rotate(glm::vec2(0, -1), -2.1));
        }
        if(lives_ > 0) {
            player_.RenderPlayer();
        } else {
            ci::gl::drawStringCentered("GAME OVER", glm::vec2(575, 350),ci::Color("white"), ci::Font("Roboto", 100));
        }

        ci::gl::color(ci::Color("red"));
        for(int i = 0; i<player_.max_projectiles_ - player_.projectiles_.size(); i++) {
            ci::gl::drawSolidCircle(glm::vec2(1120 - 30*i, 50), 2);
        }
        for(Asteroid& a: asteroids_) {
            a.RenderAsteroid();
        }
        for(Projectile& p: power_ups_) {
            p.RenderProjectile();
        }
    }

    void SpaceArena::Update() {
        crash = -1;
        power_up_ = false;
        if(asteroids_.empty()) {
            lives_+=1;
            power_up_ = true;
            for(int i = 0; i < 5 + score_/1000; i++) {
                Asteroid a(ci::Color("gray"), i % 5, Rotate(glm::vec2(3, 3), i), glm::vec2(600, 900));
                AddAsteroid(a);
            }
            score_ += 10;
        }

        player_.UpdatePlayer();
        for(Projectile& p: player_.projectiles_) {
            p.UpdateProjectile();
        }

        int i = 0;
        bool deletion = false;
        for(Asteroid& a: asteroids_) {
            a.UpdateAsteroid();
            if(player_.CheckCollision(a)) {
                lives_--;
                crash = 0;
            }
            int j = 0;
            for(Projectile& p: player_.projectiles_) {
                if(glm::length(p.GetPosition() - a.GetPosition()) <= 20.0f+10.0f*a.GetRadius()) {
                    deletion = true;
                    crash = a.GetRadius() % 5;
                    break;
                }
                j++;
            }
            if(deletion) {
                player_.RemoveProjectile(j);
                break;
            }
            i++;
        }
        if(deletion) {
            score_+=10;
            Asteroid a = asteroids_.at(i);
            if(a.GetRadius() == 3) {
                power_ups_.push_back(Projectile (a.GetPosition(), 0.0f*a.GetPosition(), 4, ci::Color("blue")));
            }
            if(a.GetRadius() > 0) {
                for (int k = 0; k < 2; k++) {
                    Asteroid b(ci::Color("gray"), a.GetRadius() - 1, Rotate(glm::vec2(4, 4), i + k), a.GetPosition());
                    AddAsteroid(b);
                }
            }
            RemoveAsteroid(i);
        }

        i = 0;
        deletion = false;
        for(Projectile& p: power_ups_) {
            if(player_.CheckCollision(p)) {
                deletion = true;
                break;
            }
            i++;
        }
        if(deletion) {
            power_ups_.erase(power_ups_.cbegin() + i);
        }
    }

    void SpaceArena::AddAsteroid(Asteroid& a) {
        asteroids_.push_back(a);
    }

    void SpaceArena::RemoveAsteroid(size_t i) {
        asteroids_.erase(asteroids_.cbegin()+i);
    }

    glm::vec2 SpaceArena::Rotate(glm::vec2 vector, float theta) {
        float x = vector.x;
        float y = vector.y;
        return glm::vec2(x*cos(theta) - y*sin(theta), x*sin(theta) + y*cos(theta));
    }

    int SpaceArena::SignalSound() {
        if(crash >= 4) {
            return 4;
        }
        if(crash >= 1) {
            return 1;
        }
        if(crash >= 0) {
            return 3;
        }
        if(power_up_) {
            return 2;
        }
        return 0;
    }

}