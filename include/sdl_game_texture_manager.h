#ifndef TEXTURE_MANAGER_HPP
#define TEXTURE_MANAGER_HPP

#include <string>
#include <unordered_map>
#include "SDL2/SDL.h"
#include "sdl_game_dto.h"
#include "logging_manager.h"

namespace sdlgame {
    class TextureManager{
    public:
        TextureManager(SDL_Renderer* renderer, Logger logger);

        bool Load(const std::string& filename, const std::string& id);
        void Render(const std::string& id, const GameObjectDto& obj, SDL_RendererFlip flip=SDL_FLIP_NONE);
        void RenderRect(const GameObjectDto& obj);

    private:
        SDL_Renderer* m_renderer;
        std::unordered_map<std::string, SDL_Texture*> m_textures;
        Logger m_logger;
    };
}

#endif