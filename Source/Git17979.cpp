#include <iostream>
#include "Personaje.h"
#include "InputHandler.h"
#include "Command.h"
#include "Observer.h"
#include "Audio.h"
#include "Logros.h"



    
int main()
{
	Audio audioSystem;
    // Dentro del bucle while en main
    audioSystem.solicitarSonido({ SoundID::DAMAGE });
    audioSystem.solicitarSonido({ SoundID::SALTAR });
    audioSystem.solicitarSonido({ SoundID::DAMAGE }); // Duplicado
    audioSystem.solicitarSonido({ SoundID::DAMAGE }); // Duplicado

    audioSystem.procesarEventos();
    Logros logros;
    Audio  audio;
    
    Personaje personaje;
    InputHandler inputHandler(&personaje);

    personaje.agregarObserver(&logros);
    personaje.agregarObserver(&audio);
    personaje.getdamage(10);


    char input;
    bool running = true;
    while (running) {
        std::cout << "Presiona una tecla (o 'r' para reconfigurar, 'q' para salir): ";
        std::cin >> input;

        if (input == 'q') {
            running = false;
        }
        
        else if (input == 'r') {
            char tecla;
            std::string accion;
            std::cout << "¿Qué tecla quieres remapear? ";
            std::cin >> tecla;
            std::cout << "¿A qué acción? (saltar, disparar, agacharse): ";
            std::cin >> accion;
            inputHandler.remapearTecla(tecla, accion);
            std::cout << "Tecla remapeada.\n";
        }
        else {
            Command* command = inputHandler.handleInput(input);
            if (command) {
                command->execute();
            }
            else {
                std::cout << "Tecla sin acción asignada.\n";
            }
        }
    }

        char tecla;
        while (true) {
            std::cout << "\nIngresa tecla (w: saltar, f: disparar, s: agacharse, q: salir): ";
            std::cin >> tecla;

            Command* cmd = inputHandler.handleInput(tecla);
            if (cmd) cmd->execute();

            personaje.update();
        }
    return 0;
}



