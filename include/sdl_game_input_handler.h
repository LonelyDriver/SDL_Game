#ifndef INPUT_HANDLER_HPP
#define INPUT_HANDLER_HPP
#include <vector>
#include "logger_interface.h"
#include "vector2d.h"
#include "SDL2/SDL.h"

using Vec = vector::Vector2D;
namespace sdlgame {

    enum MOUSE_BUTTONS : int{
        LEFT = 0,
        MIDDLE =1,
        RIGHT = 2
    };
    
    class InputHandler{
    public:
        InputHandler(Logger logger);

        bool Update();
        Vec GetMousePos() const;
        bool GetMouseButtonState(int button_number) const;
        bool IsKeyDown(SDL_Scancode key) const;
    private:
        Logger m_logger;
        Vec m_mouse_pos;
        Uint8* m_key_states;
        std::vector<bool> m_mouse_btn_states;

        void keyState();
        void onMouseButtonUp(SDL_Event& e);
        void onMouseButtonDown(SDL_Event& e);
        void onMouseMove(SDL_Event& e);
    };
} // namespace sdlgame


#endif