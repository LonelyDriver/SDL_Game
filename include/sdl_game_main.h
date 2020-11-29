#pragma once
#include <string>
#include <vector>

#include <SDL2/SDL.h>
#include "vector2d.h"
#include "logging_manager.h"
#include "sdl_game_texture_manager.h"
#include "sdl_game_input_handler.h"

using Vec = vector::Vector2D;
namespace sdlgame{
    class Main{
    public:
        Main();
        ~Main();
        Main(const Main&) = delete;

        void Init(const std::string& name, const Vec& window_pos, const Vec& window_size);
        void Update();
        void HandleEvents();
        void Render();
        void Running(bool running);
        bool Running() const;
        void Run();

    private:
        SDL_Window* m_window;
        SDL_Renderer* m_renderer;
        Logger m_logging;
        bool m_running;
        TextureManager* m_tex_manager;
        std::vector<GameObjectDto> m_objects;
        InputHandler* m_input_handler;
    };
}