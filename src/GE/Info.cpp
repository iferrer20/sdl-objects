#include "Info.hpp"
#include "GameEngine.hpp"

namespace GE {

Info::Info() {

}

uint32_t Info::getFps() const {
    return fps;
}


void Info::update() {
    static uint32_t framecount {};
    static uint32_t nextsecond {1000};
    
    if (SDL_GetTicks() > nextsecond) {
        fps = framecount;
        framecount = 0;
        nextsecond = SDL_GetTicks() + 1000;
        std::cout << "FPS: " << fps << std::endl;
    } else {
        framecount++;
    }
}

}