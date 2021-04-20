#include "../include/Simulation.h"

using asteroids::Simulation;

void prepareSettings(Simulation::Settings* settings) {
    settings->setResizable(false);
}

// This line is a macro that expands into an "int main()" function.
CINDER_APP(Simulation, ci::app::RendererGl, prepareSettings);
