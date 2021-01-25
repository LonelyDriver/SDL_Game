#include "sdl_game_player.h"


sdlgame::Player::Player(const GameObjectDto& params, Logger logging) :
GameObject(params, logging){
    m_params.Vel = Vec(0,0);
}

void sdlgame::Player::Render(const TextureManagerPtr texture_manager) const{
    GameObject::Render(texture_manager);
}
void sdlgame::Player::Update(const InputHandlerPtr input_handler){
    auto direction = input_handler->GetMousePos() - m_params.Pos;
    direction.Normalize();
    direction *= 5;
    m_params.Acc = direction;

    m_params.Vel += m_params.Acc;
    m_params.Vel.Magnitude(15);
    m_params.Pos += m_params.Vel;
    m_logging->Debug(STREAM("Direction: "<<m_params.Vel.Print()));
}