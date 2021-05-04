#include "../include/Simulation.h"
#include <Windows.h>
#include "cinder/audio/audio.h"
#include <glm/vec2.hpp>

using namespace ci;
using namespace ci::app;

namespace asteroids {

    ci::audio::GainNodeRef mGain;
    ci::audio::BufferPlayerNodeRef mBufferPlayerNode;

    ci::audio::GainNodeRef mGain2;
    ci::audio::BufferPlayerNodeRef mBufferPlayerNode2;

    ci::audio::GainNodeRef mGain3;
    ci::audio::BufferPlayerNodeRef mBufferPlayerNode3;

    ci::audio::GainNodeRef mGain4;
    ci::audio::BufferPlayerNodeRef mBufferPlayerNode4;

    ci::audio::GainNodeRef mGain5;
    ci::audio::BufferPlayerNodeRef mBufferPlayerNode5;

    ci::audio::GainNodeRef mGain6;
    ci::audio::BufferPlayerNodeRef mBufferPlayerNode6;

    Simulation::Simulation() {
        ci::app::setWindowSize(kWindowSizeX, kWindowSizeY);
        for(int i = 0; i < 4; i++) {
            Asteroid a(ci::Color("gray"), i % 5, Rotate(glm::vec2(3, 3), i), glm::vec2(600, 900));
            arena_.AddAsteroid(a);
        }
    }

    void Simulation::draw() {
        ci::gl::clear(ci::Color ("black"));
        arena_.Display();
    }

    void Simulation::update() {
        arena_.Update();
        switch(arena_.SignalSound()) {
            case 1:
                mBufferPlayerNode3->start();
                break;
            case 2:
                mBufferPlayerNode4->start();
                break;
            case 3:
                mBufferPlayerNode5->start();
                break;
            case 4:
                mBufferPlayerNode6->start();
                break;
            default:
                break;

        }
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
                mBufferPlayerNode->start();
                break;
            case ci::app::KeyEvent::KEY_UP:
                mBufferPlayerNode2->start();
                break;
        }
    }

    void Simulation::setup() {

        auto ctx = audio::Context::master();
        audio::SourceFileRef source_file  = audio::load(loadAsset( "fire.mp3" ), ctx->getSampleRate());
        audio::BufferRef buffer = source_file->loadBuffer();
        mBufferPlayerNode = ctx->makeNode( new audio::BufferPlayerNode( buffer ) );
        mGain = ctx->makeNode( new audio::GainNode( 0.5f ) );
        mBufferPlayerNode >> mGain >> ctx->getOutput();
        ctx->enable();

        audio::SourceFileRef source_file2  = audio::load(loadAsset( "thrust.mp3" ), ctx->getSampleRate());
        audio::BufferRef buffer2 = source_file2->loadBuffer();
        mBufferPlayerNode2 = ctx->makeNode( new audio::BufferPlayerNode( buffer2 ) );
        mGain2 = ctx->makeNode( new audio::GainNode( 0.5f ) );
        mBufferPlayerNode2 >> mGain2 >> ctx->getOutput();

        audio::SourceFileRef source_file3  = audio::load(loadAsset( "bangMedium.mp3" ), ctx->getSampleRate());
        audio::BufferRef buffer3 = source_file3->loadBuffer();
        mBufferPlayerNode3 = ctx->makeNode( new audio::BufferPlayerNode( buffer3 ) );
        mGain3 = ctx->makeNode( new audio::GainNode( 0.5f ) );
        mBufferPlayerNode3 >> mGain3 >> ctx->getOutput();

        audio::SourceFileRef source_file4  = audio::load(loadAsset( "extraShip.mp3" ), ctx->getSampleRate());
        audio::BufferRef buffer4 = source_file4->loadBuffer();
        mBufferPlayerNode4 = ctx->makeNode( new audio::BufferPlayerNode( buffer4 ) );
        mGain4 = ctx->makeNode( new audio::GainNode( 0.5f ) );
        mBufferPlayerNode4 >> mGain4 >> ctx->getOutput();

        audio::SourceFileRef source_file5  = audio::load(loadAsset( "bangSmall.mp3" ), ctx->getSampleRate());
        audio::BufferRef buffer5 = source_file5->loadBuffer();
        mBufferPlayerNode5 = ctx->makeNode( new audio::BufferPlayerNode( buffer5 ) );
        mGain5 = ctx->makeNode( new audio::GainNode( 0.5f ) );
        mBufferPlayerNode5 >> mGain5 >> ctx->getOutput();

        audio::SourceFileRef source_file6  = audio::load(loadAsset( "bangLarge.mp3" ), ctx->getSampleRate());
        audio::BufferRef buffer6 = source_file6->loadBuffer();
        mBufferPlayerNode6 = ctx->makeNode( new audio::BufferPlayerNode( buffer6 ) );
        mGain6 = ctx->makeNode( new audio::GainNode( 0.5f ) );
        mBufferPlayerNode6 >> mGain6 >> ctx->getOutput();

    }

}