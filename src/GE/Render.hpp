#pragma once
#include <SDL2/SDL.h>

namespace GE {

class Render {
    SDL_Renderer* gRenderer;

    void update();
    friend void run();
public:
    explicit Render();
    ~Render();
};

}
