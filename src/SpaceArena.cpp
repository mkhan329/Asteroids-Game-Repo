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
        for(Asteroid& a: asteroids_) {
            a.UpdateAsteroid();
        }
    }

    void SpaceArena::AddAsteroid(Asteroid& a) {
        asteroids_.push_back(a);
    }

    void SpaceArena::RemoveAsteroid(size_t i) {
        asteroids_.erase(asteroids_.cbegin()+i);
    }

}