#include "sdl_game_main.h"

sdlgame::Main::Main() :
m_window(nullptr),
m_renderer(nullptr),
m_logging(),
m_running(false){
     LogManager::RegisterLogger("Main", std::make_shared<logger::ConsoleLogger>());
     m_logging = LogManager::GetLogger("Main");
}

sdlgame::Main::~Main(){
    SDL_DestroyWindow(m_window);
    SDL_Quit();
    m_logging->Debug("Shutting down");
}

void sdlgame::Main::Init(const std::string& name, const Vec& window_pos, const Vec& window_size){
    SDL_Init(SDL_INIT_VIDEO);
     m_window = SDL_CreateWindow(
        name.c_str(),
        window_pos.GetX(),
        window_pos.GetY(),
        window_size.GetX(),
        window_size.GetY(),
        0
    );

    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_SOFTWARE);
    SDL_SetRenderDrawColor(m_renderer, 0,0,0,SDL_ALPHA_OPAQUE);
    SDL_RenderClear(m_renderer);
    SDL_RenderPresent(m_renderer);
}
void sdlgame::Main::Update(){
    m_logging->Debug("Update");
}
void sdlgame::Main::HandleEvents(){
    m_logging->Debug("HandleEvents");
    SDL_Event e;
    while(SDL_PollEvent(&e) != 0){
        if(e.type == SDL_QUIT){
            m_running = false;
        }
    }   
}
void sdlgame::Main::Render(){
    m_logging->Debug("Render");
}

void sdlgame::Main::Running(bool running){
    m_running = running;
}

bool sdlgame::Main::Running() const{
    return m_running;
}

void sdlgame::Main::Run(){
    while(m_running){
        HandleEvents();
        Update();
        Render();

        SDL_Delay(1000/60);
    }
}