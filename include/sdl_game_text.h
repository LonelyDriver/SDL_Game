#ifndef GAME_TEXT_HPP
#define GAME_TEXT_HPP
#include "sdl_game_game_object.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"

namespace sdlgame {
    class TextField : public GameObject {
    public:
        TextField(const GameObjectDto& params, Logger logging);
        virtual void Render(const TextureManager* texture_manager) const override;
        virtual void Update(const InputHandler* input_handler) override;
    private:
        SDL_Texture* m_texture;
    };
}

#endif