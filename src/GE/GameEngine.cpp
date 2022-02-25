#include "GameEngine.hpp"

namespace GE {

std::unique_ptr<Window> window { std::make_unique<Window>() };
std::unique_ptr<Render> render { std::make_unique<Render>() };
std::unique_ptr<Info> info     { std::make_unique<Info>()   };

void run() {
    SDL_Event e;
    for (;;) {
        while(SDL_PollEvent(&e) != 0) {
            switch (e.type) {
            case SDL_QUIT:
                terminate<GE_EXIT_SUCCESS>();
                break;
            case SDL_WINDOWEVENT:
                switch (e.window.event) {
                case SDL_WINDOWEVENT_RESIZED:
                    window->onResize();
                    break;
                }
                
                break;
            }
        }

        render->update();
        info->update();
    }
}

}

