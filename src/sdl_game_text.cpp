#include "sdl_game_text.h"

sdlgame::TextField::TextField(const GameObjectDto& params, Logger logging) :
GameObject(params, logging),
m_texture(){

}

void sdlgame::TextField::Render(const TextureManagerPtr texture_manager) const{
    GameObject::Render(texture_manager);
}
void sdlgame::TextField::Update(const InputHandlerPtr input_handler){
    input_handler->IsKeyDown(SDL_SCANCODE_F10);
}