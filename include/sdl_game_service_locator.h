#include <vector>

#include "sdl_game_service_interface.h"

namespace sdlgame{
    class ServiceLocator : public ServiceInterface{
    public:

    private:
        std::vector<ServiceInterface*> m_services;
    }
}