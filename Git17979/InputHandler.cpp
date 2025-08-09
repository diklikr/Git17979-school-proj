#include "InputHandler.h"
#include "Command.h"

InputHandler::InputHandler(Personaje* personaje)
    : saltarCommand_(std::make_unique<SaltarCommand>(personaje)),
      dispararCommand_(std::make_unique<DispararCommand>(personaje)),
      agacharseCommand_(std::make_unique<AgacharseCommand>(personaje))
{
    botonArray_.fill(nullptr);

    botonArray_['w'] = saltarCommand_.get();
    botonArray_['d'] = dispararCommand_.get();
    botonArray_['s'] = agacharseCommand_.get();
}

InputHandler::~InputHandler() {}

Command* InputHandler::handleInput(char tecla)
{
    return botonArray_[static_cast<unsigned char>(tecla)];
}

void InputHandler::remapearTecla(char tecla, std::string accion)
{
    if (accion == "saltar") botonArray_[tecla] = saltarCommand_.get();
    else if (accion == "disparar") botonArray_[tecla] = dispararCommand_.get();
    else if (accion == "agacharse") botonArray_[tecla] = agacharseCommand_.get();
}
