#include "../include/SpaceArena.h"

namespace asteroids {

    void SpaceArena::Display() {
        player_.RenderPlayer();
    }

    void SpaceArena::Update() {
        player_.UpdatePlayer();
    }

    void SpaceArena::AddAsteroid(Asteroid a) {

    }

}