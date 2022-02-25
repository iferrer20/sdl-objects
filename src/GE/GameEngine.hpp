#pragma once
#include <iostream>
#include <string_view>
#include <memory>
#include <type_traits>

#include <SDL2/SDL.h>

namespace GE {

enum EXIT_CODE {
    GE_EXIT_SUCCESS,
    GE_EXIT_FAILURE
};

template<EXIT_CODE e = GE_EXIT_FAILURE, typename... S> 
requires std::conjunction_v<std::is_convertible<S, std::string_view>...>
void terminate(const S... str) {
    if constexpr (sizeof...(S) > 0)
        (std::operator<<((GE_EXIT_FAILURE ? std::cerr : std::cout) << str, " "), ...) << "\n";
    
    std::exit(e);
}
void run();

}

#include "Window.hpp"
#include "Render.hpp"
#include "Info.hpp"
namespace GE {
    extern std::unique_ptr<Window> window;
    extern std::unique_ptr<Render> render;
    extern std::unique_ptr<Info> info;
}


