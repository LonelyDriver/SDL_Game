#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP
#include "sdl_game_texture_manager.h"
#include "sdl_game_dto.h"
#include "sdl_game_input_handler.h"

namespace sdlgame {
    class GameObject{
    public:
        GameObject(const GameObjectDto& params, Logger logging);
        virtual ~GameObject(){}
        virtual void Render(const TextureManagerPtr texture_manager) const;
        virtual void Update(const InputHandlerPtr input_handler);

    protected:
        GameObjectDto m_params;
        Logger m_logging;
    };
}

#endif