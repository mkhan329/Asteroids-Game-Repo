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
                if(glm::length(p.GetPosition() - a.GetPosition()) < 20.0f+10.0f*a.GetRadius()) {
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
            RemoveAsteroid(i);
        }
        deletion = false;
    }

    void SpaceArena::AddAsteroid(Asteroid& a) {
        asteroids_.push_back(a);
    }

    void SpaceArena::RemoveAsteroid(size_t i) {
        asteroids_.erase(asteroids_.cbegin()+i);
    }

}