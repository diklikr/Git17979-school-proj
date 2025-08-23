// Git17979.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Personaje.h"
#include "InputHandler.h"
#include "Command.h"
#include "Observer.h"
class SistemaDeAudio : public Observer {
public:
    void onNotify(const Personaje& personaje, Evento evento) override {
        if (evento == Evento::PERSONAJE_RECIBE_DANO) {
            std::cout << "[AUDIO] Notificación: sonido de dolor\n";
        }
    }
};

class SistemaDeLogros : public Observer {
public:
    void onNotify(const Personaje& personaje, Evento evento) override {
        if (evento == Evento::PERSONAJE_RECIBE_DANO) {
            std::cout << "[LOGROS] Notificación: logro desbloqueado\n";
        }
    }
};
    
int main()
{
    Personaje personaje;
    SistemaDeAudio audio;
    SistemaDeLogros logros;
    
    personaje.agregarObserver(&logros);
    personaje.agregarObserver(&audio);
    personaje.recibirDano(10);


   // char tecla;
   // Personaje* player = new Personaje(20,20,10,10,10);
   //
   // player->SetJumpHeight(0);

   // std::cout << "Hello World!\n";
   // std::cout << "aprieta una tecla para jugar\n";
   ////update
   // while (true)
   // {
   // 
   //     std::cin >> tecla;
   // if (tecla == 'w')
   // {
   //     player->Saltar();
   // }
   // else if (tecla == 'f')
   // {
   //     player->Disparar();
   // }
   // else
   // {
   //     std::cout << "Esa tecla no es valida\n";
   // }

   // }
    Personaje personaje;
    InputHandler inputHandler(&personaje);

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
        Personaje personaje;
        InputHandler inputHandler(&personaje);

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



