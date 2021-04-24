#include "../include/Simulation.h"
#include <Windows.h>
#include <glm/vec2.hpp>

namespace asteroids {

    Simulation::Simulation() {
        ci::app::setWindowSize(kWindowSizeX, kWindowSizeY);
        for(int i = 0; i < 5; i++) {
            Asteroid a(ci::Color("white"), 20+10*i, Rotate(glm::vec2(4, 4), i), glm::vec2(100+50*i, 100+50*i));
            arena_.AddAsteroid(a);
        }
    }

    void Simulation::draw() {
        ci::gl::clear(ci::Color ("black"));
        arena_.Display();
    }

    void Simulation::update() {
        arena_.Update();
    }

    glm::vec2 Simulation::Rotate(glm::vec2 vector, float theta) {
        float x = vector.x;
        float y = vector.y;
        return glm::vec2(x*cos(theta) - y*sin(theta), x*sin(theta) + y*cos(theta));
    }

    void Simulation::keyDown(ci::app::KeyEvent event) {
        switch (event.getCode()) {
            case ci::app::KeyEvent::KEY_SPACE:
                arena_.player_.Shoot();
                break;
        }
    }

}