#include "InputHandler.h"
#include "Command.h"
InputHandler::InputHandler(Personaje* personaje)
{
    saltarCommand_ = std::make_unique<SaltarCommand>(personaje);
    dispararCommand_ = std::make_unique<DispararCommand>(personaje);
    agacharseCommand_ = std::make_unique<AgacharseCommand>(personaje);

    // Asignación inicial de teclas
    botonMap_['w'] = saltarCommand_.get();
    botonMap_['d'] = dispararCommand_.get();
    botonMap_['s'] = agacharseCommand_.get();
}

InputHandler::~InputHandler() {}
Command* InputHandler::handleInput(char tecla)
{
    
        auto it = botonMap_.find(tecla);
        if (it != botonMap_.end()) {
            return it->second;
        }
        return nullptr;
}

    void InputHandler::remapearTecla(char tecla, std::string accion)
    {
        if (accion == "saltar") {
            botonMap_[tecla] = saltarCommand_.get();
        }
        else if (accion == "disparar") {
            botonMap_[tecla] = dispararCommand_.get();
        }
        else if (accion == "agacharse") {
            botonMap_[tecla] = agacharseCommand_.get();
        }
    }
