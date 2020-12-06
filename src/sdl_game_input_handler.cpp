#include "sdl_game_input_handler.h"

sdlgame::InputHandler::InputHandler(Logger logger) :
m_logger(logger),
m_mouse_pos(0,0),
m_key_states(),
m_mouse_btn_states()
{
    for(int i=0;i<3;++i){
        m_mouse_btn_states.push_back(false);
    }
}

bool sdlgame::InputHandler::Update() {
    SDL_Event e;

    while(SDL_PollEvent(&e)){
        switch(e.type){
            case SDL_MOUSEMOTION:
                onMouseMove(e);
                break;
            case SDL_MOUSEBUTTONDOWN:
                onMouseButtonDown(e);
                break;
            case SDL_MOUSEBUTTONUP:
                onMouseButtonUp(e);
                break;
            case SDL_KEYDOWN:
            case SDL_KEYUP:
                keyState();
                break;
            case SDL_QUIT:
                return false;
        }
    }
    return true;
}

/**
 * @brief Returns current mouse position
 * 
 * @return Vec& 
 */
Vec sdlgame::InputHandler::GetMousePos() const {
    return m_mouse_pos;
}

bool sdlgame::InputHandler::IsKeyDown(SDL_Scancode key) const{
    if(!m_key_states){
        return false;
    }

    return m_key_states[key] == 1;
}


/**
 * @brief Get array of current pressed keys
 * 
 */
void sdlgame::InputHandler::keyState() {
    m_key_states = (Uint8*)SDL_GetKeyboardState(0);
}

void sdlgame::InputHandler::onMouseMove(SDL_Event& e){
    m_mouse_pos.SetX(e.motion.x);
    m_mouse_pos.SetY(e.motion.y);
}

void sdlgame::InputHandler::onMouseButtonDown(SDL_Event& e){
    if(e.button.button == SDL_MOUSEBUTTONDOWN){
        m_mouse_btn_states[MOUSE_BUTTONS::LEFT] = true;
    }
    if(e.button.button == SDL_MOUSEBUTTONDOWN){
        m_mouse_btn_states[sdlgame::MOUSE_BUTTONS::MIDDLE] = true;
    }
    if(e.button.button == SDL_MOUSEBUTTONDOWN){
        m_mouse_btn_states[sdlgame::MOUSE_BUTTONS::RIGHT] = true;
    }
}

void sdlgame::InputHandler::onMouseButtonUp(SDL_Event& e){
    if(e.button.button == SDL_MOUSEBUTTONDOWN){
        m_mouse_btn_states[sdlgame::MOUSE_BUTTONS::LEFT] = false;
    }
    if(e.button.button == SDL_MOUSEBUTTONDOWN){
        m_mouse_btn_states[sdlgame::MOUSE_BUTTONS::MIDDLE] = false;
    }
    if(e.button.button == SDL_MOUSEBUTTONDOWN){
        m_mouse_btn_states[sdlgame::MOUSE_BUTTONS::RIGHT] = false;
    }
}
