#ifndef SDL_GAME_DTO
#define SDL_GAME_DTO
#include "vector2d.h"

using Vec = vector::Vector2D;

namespace sdlgame{
    typedef struct GameObjectDto_{
        /*GameObjectDto_() :
        Pos(0,0), Vel(0,0), Acc(0,0), Size(0,0), rgba(){}
        */

        Vec Pos;
        Vec Vel;
        Vec Acc;
        Vec Size;
        //int rgba[4];
    } GameObjectDto;
}

#endif