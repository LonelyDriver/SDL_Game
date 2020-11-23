#include "sdl_game_main.h"

int main(){
    sdlgame::Main game;
    game.Init(
        "SDL_GAME",
        Vec(300, 300),
        Vec(1080, 720));

    game.Running(true);

    game.Run();

    return 0;
}