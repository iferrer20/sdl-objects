#pragma once 
#include <SDL2/SDL.h>
#include <string_view>
#include <stdint.h>

namespace GE {

class Window {
    SDL_Window* window;
    SDL_Surface* surface;
    bool fullScreen;
    struct Size {
        uint16_t width;
        uint16_t height;
    };
    Size size;

    friend class Render;

public:
    explicit Window(const std::string_view title="None", const uint16_t width=640, const uint16_t height=480);
    void setSize(uint16_t w, uint16_t h);
    void onResize();
    Size getSize() const;
    void toggleFullScreen();
    ~Window();
};

}