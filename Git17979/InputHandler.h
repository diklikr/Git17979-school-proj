#pragma once
#include <memory>
#include <map>
#include <string>
#include "Personaje.h"
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

    std::map<char, Command*> botonMap_;
};

