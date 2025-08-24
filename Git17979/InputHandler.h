#pragma once
#include <memory>
#include <array>
#include <string>
#include "Personaje.h"
#include "Command.h" // Ensure Command is included

class InputHandler
{
public:
    InputHandler(Personaje* personaje);
    ~InputHandler();

    Command* handleInput(char tecla);
    void remapearTecla(char tecla, std::string accion);

private:
    std::unique_ptr<SaltarCommand> saltarCommand_;
    std::unique_ptr<DispararCommand> dispararCommand_;
    std::unique_ptr<AgacharseCommand> agacharseCommand_;

    std::array<Command*, 256> botonArray_;
};
