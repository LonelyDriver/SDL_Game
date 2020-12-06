#include "sdl_game_main.h"

sdlgame::Main::Main() :
m_window(nullptr),
m_renderer(nullptr),
m_logging(),
m_running(false),
m_tex_manager(),
m_objects(),
m_input_handler(){
     LogManager::RegisterLogger("Main", std::make_shared<logger::ConsoleLogger>());
     LogManager::RegisterLogger("TextureManager", std::make_shared<logger::ConsoleLogger>());
     LogManager::RegisterLogger("InputHandler", std::make_shared<logger::ConsoleLogger>());
     m_logging = LogManager::GetLogger("Main");
}

sdlgame::Main::~Main(){
    m_logging->Debug("Shutting down");
    SDL_DestroyWindow(m_window);
    SDL_Quit();
    delete m_tex_manager;
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

    m_tex_manager = new TextureManager(m_renderer, LogManager::GetLogger("TextureManager"));
    m_logging->Debug("TextureManager created");
    m_input_handler = new InputHandler(LogManager::GetLogger("InputHandler"));

    GameObjectDto d = {Vec(100,100),Vec{0,0},Vec(0,0), Vec(100,100)};
    Player p{d, LogManager::GetLogger("Player")};
    m_objects.push_back(p);
}

void sdlgame::Main::Update(){
    const auto& mouse_pos = m_input_handler->GetMousePos();
    
    for(auto& obj : m_objects){
        obj.Update(m_input_handler);
    }
}

void sdlgame::Main::HandleEvents(){
    m_running = m_input_handler->Update();  
    if(m_input_handler->IsKeyDown(SDL_SCANCODE_ESCAPE)){
        m_running = false;
    }
}

void sdlgame::Main::Render(){

    SDL_RenderClear(m_renderer);
    for(const auto obj : m_objects){
        obj.Render(m_tex_manager);
    }
    SDL_RenderPresent(m_renderer);
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