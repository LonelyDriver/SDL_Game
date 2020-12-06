#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "sdl_game_game_object.h"
#include "logger_interface.h"

namespace sdlgame {
    class Player : public GameObject{
    public:
        Player(const GameObjectDto& params, Logger logging);
        /*Player(const Player& other) : GameObject({
            *this = other;
        }
        Player operator=(const Player& other){
            m_params = other.m_params;
            m_logging = other.m_logging;
        }*/

        void Render(const TextureManager* texture_manager) const override;
        void Update(const InputHandler* input_handler) override;
    };
}

#endif