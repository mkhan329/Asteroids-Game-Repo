#include "../include/Simulation.h"
#include <Windows.h>

namespace asteroids {

    Simulation::Simulation() {
        ci::app::setWindowSize(kWindowSizeX, kWindowSizeY);
    }

    void Simulation::draw() {
        ci::Color background_color("black");
        ci::gl::clear(background_color);
    }

    void Simulation::update() {

    }

}