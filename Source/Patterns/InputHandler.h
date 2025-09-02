/* @file InputHandler.h
 * @brief Manejador de entradas del usuario que traduce teclas en comandos ejecutables sobre un Personaje.
 * Esta clase implementa el patrón Command. Permite asignar diferentes acciones a teclas y ejecutar los comandos correspondientes cuando se detecta la entrada del usuario.*/

#pragma once
#include <memory>
#include <array>
#include <string>
#include "Personaje.h"
#include "Command.h" 

 /* @class InputHandler
  * @brief Traduce la entrada del usuario (teclas) en comandos sobre un Personaje.
  * Permite mapear teclas a comandos específicos como saltar, disparar o agacharse, y ejecutar dichos comandos cuando se reciben entradas del jugador.*/
class InputHandler {
public:
    /* @brief Constructor.
     * @param personaje Puntero al personaje sobre el que se ejecutarán los comandos.*/
    InputHandler(Personaje* personaje);

    ~InputHandler();/*@brief Destructor.*/

    /*@brief Maneja la entrada de una tecla y devuelve el comando asociado.
     * @param tecla Carácter que representa la tecla presionada.
     * @return Puntero al comando correspondiente (puede ser nullptr si no hay comando asignado).*/
    Command* handleInput(char tecla);

    /*@brief Permite remapear una tecla a una acción específica.
     * @param tecla Carácter de la tecla a remapear (ej. 'w').
     * @param accion Nombre de la acción a asignar (ej. "saltar").*/
    void remapearTecla(char tecla, std::string accion);

private:
    std::unique_ptr<SaltarCommand> saltarCommand_;      ///< Comando para saltar
    std::unique_ptr<DispararCommand> dispararCommand_;  ///< Comando para disparar
    std::unique_ptr<AgacharseCommand> agacharseCommand_;///< Comando para agacharse

    std::array<Command*, 256> botonArray_; ///< Arreglo de punteros a comandos para cada tecla
};