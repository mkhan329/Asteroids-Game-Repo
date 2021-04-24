#include "../include/SpaceArena.h"

namespace asteroids {

    void SpaceArena::Display() {
        player_.RenderPlayer();
        for(Asteroid& a: asteroids_) {
            a.RenderAsteroid();
        }
    }

    void SpaceArena::Update() {
        player_.UpdatePlayer();
        for(Projectile& p: player_.projectiles_) {
            p.UpdateProjectile();
        }

        int i = 0;
        bool deletion = false;
        for(Asteroid& a: asteroids_) {
            a.UpdateAsteroid();
            int j = 0;
            for(Projectile& p: player_.projectiles_) {
                if(glm::length(p.GetPosition() - a.GetPosition()) <= 20.0f+10.0f*a.GetRadius()) {
                    deletion = true;
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
            Asteroid a = asteroids_.at(i);
            if(a.GetRadius() > 0) {
                for (int k = 0; k < 2; k++) {
                    Asteroid b(ci::Color("gray"), a.GetRadius() - 1, Rotate(glm::vec2(4, 4), i + k), a.GetPosition());
                    AddAsteroid(b);
                }
            }
            RemoveAsteroid(i);
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

}