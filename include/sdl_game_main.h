#pragma once
#include <string>

#include <SDL2/SDL.h>
#include "vector2d.h"

namespace sdlgame{
    class Main{
    public:
        void Init(const std::string& name, const Vec& window_pos, const Vec& window_size);
    };
}