#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "sdl_game_game_object.h"
#include "logger_interface.h"

namespace sdlgame {
    class Player : public GameObject{
    public:
        Player(const GameObjectDto& params, Logger logging);

        void Render(const TextureManagerPtr texture_manager) const override;
        void Update(const InputHandlerPtr input_handler) override;
    };
}

#endif