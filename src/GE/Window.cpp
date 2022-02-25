#include "Window.hpp"
#include "GameEngine.hpp"

namespace GE {

Window::Window(const std::string_view title, const uint16_t width, const uint16_t height) 
: fullScreen{false}, size{width, height} {
    window = SDL_CreateWindow(
        title.data(), 
        SDL_WINDOWPOS_UNDEFINED, 
        SDL_WINDOWPOS_UNDEFINED, 
        width, 
        height, 
        SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE
    );
    if (!window) {
        terminate("ERROR: creating window", SDL_GetError());
    }

    surface = SDL_GetWindowSurface(window);
    if(!surface) {
        terminate("ERROR: Failed to get the surface from the window", SDL_GetError());
    }
}

void Window::setSize(uint16_t w, uint16_t h) {
    size.width = w;
    size.height = h;
    SDL_SetWindowSize(window, w, h);
}

void Window::onResize() {
    int w, h;
    SDL_GetWindowSize(window, &w, &h);
    size.width = w;
    size.height = h;
}

Window::Size Window::getSize() const {
    return size;
}

void Window::toggleFullScreen() {
    SDL_SetWindowFullscreen(window, fullScreen ? 0 : SDL_WINDOW_FULLSCREEN);
    fullScreen = !fullScreen;
}

Window::~Window() {
    SDL_DestroyWindow(window);
}

}