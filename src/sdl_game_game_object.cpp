#include "sdl_game_game_object.h"

sdlgame::GameObject::GameObject(const GameObjectDto& params, Logger logging) :
m_params(params),
m_logging(logging)
{

}

void sdlgame::GameObject::Render(const sdlgame::TextureManager* texture_manager) const{
    texture_manager->RenderRect(m_params);
}

void sdlgame::GameObject::Update(const InputHandler* input_handler) {
    if(input_handler->IsKeyDown(SDL_SCANCODE_1)){
        m_logging->Info(" ");
    }
    m_params.Vel += m_params.Acc;
    m_params.Pos += m_params.Vel;
}