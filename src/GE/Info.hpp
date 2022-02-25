#pragma once
#include <cstdint>

namespace GE {

class Info {
    uint32_t fps;
    void update();
    friend void run();

public:
    explicit Info();
    uint32_t getFps() const;
};

}

