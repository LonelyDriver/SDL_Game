#include "sdl_game_main.h"

int main(){
    LogManager::RegisterLogger("Main", std::make_shared<logger::ConsoleLogger>());
    Logger logger = LogManager::GetLogger("Main");

    logger->Info("Initializing game");
    sdlgame::Main game;
    game.Init(
        "SDL_GAME",
        Vec(300, 300),
        Vec(1080, 720));

    logger->Info("Starting game loop");
    game.Running(true);

    game.Run();

    return 0;
}