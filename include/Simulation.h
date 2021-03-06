#pragma once
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "../include/SpaceArena.h"
#ifndef FINAL_PROJECT_MKHAN329_SIMULATION_H
#define FINAL_PROJECT_MKHAN329_SIMULATION_H
#endif //FINAL_PROJECT_MKHAN329_SIMULATION_H

namespace asteroids {

    class Simulation : public ci::app::App  {
    public:

        void setup() override;
        Simulation();
        void draw() override;
        void update() override;
        void keyDown(ci::app::KeyEvent event) override;
        glm::vec2 Rotate(glm::vec2 vector, float theta);

        const int kWindowSizeX = 1200;
        const int kWindowSizeY = 800;

    private:
        SpaceArena arena_;

    };

}

