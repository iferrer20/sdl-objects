#include "Render.hpp"
#include "GameEngine.hpp"

namespace GE {

Render::Render() {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        terminate("ERROR: SDL could not initialize", SDL_GetError());
    }
    gRenderer = SDL_CreateRenderer(window->window, -1, SDL_RENDERER_ACCELERATED);
    if(!gRenderer) {
        terminate("Renderer could not be created", SDL_GetError());
    }
}
Render::~Render() {
    SDL_DestroyRenderer(gRenderer);
}

void Render::update() {
    SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0x00, 0xFF );		
    SDL_RenderClear(gRenderer);

    const auto [width, height] = window->getSize();

    uint32_t t = SDL_GetTicks();
    int px = (width / 2 - 50) + (cos(t / 200.f) * 100.f);
    int py = (height / 2 - 50) + (sin(t / 200.f) * 100.f);
    SDL_Rect rect = {px, py, 100, 100}; // x, y, width, height
    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );		
    SDL_RenderFillRect( gRenderer, &rect ); 
    
    SDL_RenderPresent(gRenderer);
}

}