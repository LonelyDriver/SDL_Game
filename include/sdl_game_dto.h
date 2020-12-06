#ifndef SDL_GAME_DTO
#define SDL_GAME_DTO
#include "vector2d.h"

using Vec = vector::Vector2D;

namespace sdlgame{
    typedef struct GameObjectDto_{
        Vec Pos;
        Vec Vel;
        Vec Acc;
        Vec Size;
        
    } GameObjectDto;
}

#endif