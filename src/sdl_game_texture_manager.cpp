#include "sdl_game_texture_manager.h"
#include "SDL2/SDL_image.h"

sdlgame::TextureManager::TextureManager(SDL_Renderer* renderer, Logger logger) :
    m_renderer(renderer),
    m_textures(),
    m_logger(logger){

    }

bool sdlgame::TextureManager::Load(const std::string& filename, const std::string& id){
    SDL_Texture* texture = nullptr;

    SDL_Surface* surface = IMG_Load(filename.c_str());
    if(surface == NULL){
        m_logger->Warn(std::string("Could not load file <"+filename+">, SDL Error: "+IMG_GetError()));
        return false;
    }
    // create texture from surface pixels
    texture = SDL_CreateTextureFromSurface(m_renderer, surface);
    if(texture == NULL){
        m_logger->Warn(STREAM("Could not create texture from surface, SDL Error: "<<SDL_GetError()));
        return false;
    }
    // delete old surface
    SDL_FreeSurface(surface);
    m_textures[id] = texture;
    return true;
}

void sdlgame::TextureManager::Render(const std::string& id, const GameObjectDto& obj,SDL_RendererFlip flip){
    SDL_Rect src_rect, dest_rect;

    src_rect.x = 0;
    src_rect.y = 0;
    src_rect.w = dest_rect.w = obj.Size.GetX();
    src_rect.h = dest_rect.h = obj.Size.GetY();
    dest_rect.x = obj.Pos.GetX();
    dest_rect.y = obj.Pos.GetY();

    SDL_RenderCopyEx(m_renderer, m_textures.at(id), &src_rect, &dest_rect, 0, 0, flip);
}

void sdlgame::TextureManager::RenderRect(const GameObjectDto& obj) const{
    SDL_Rect rect;
    rect.x = obj.Pos.GetX();
    rect.y = obj.Pos.GetY();
    rect.w = obj.Size.GetX();
    rect.h = obj.Size.GetY();

    SDL_SetRenderDrawColor(m_renderer, 0xFF, 0x00, 0x00, 0x00);
    SDL_RenderDrawRect(m_renderer, &rect);
    SDL_SetRenderDrawColor(m_renderer, 0x00, 0x00, 0x00, 0xFF);
}