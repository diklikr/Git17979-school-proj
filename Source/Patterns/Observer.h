/*@file Observer.h
 * @brief Declaración de la interfaz Observer para implementar el patrón Observer.
 * Esta interfaz permite que diferentes sistemas (ej. Logros, Audio) se suscriban a eventos generados por un Personaje y reaccionen ante ellos.*/

#pragma once
#include <iostream>
#include <vector>

class Personaje;

/* @enum Evento
 * @brief Enumeración de eventos que un Personaje puede notificar.
 * Eventos posibles:
 * - PERSONAJE_RECIBE_DANO: el personaje recibe daño.
 * - PERSONAJE_SALTAR: el personaje salta.
 * - PERSONAJE_DISPARA: el personaje dispara.*/
enum class Evento {
    PERSONAJE_RECIBE_DANO,
    PERSONAJE_SALTAR,
    PERSONAJE_DISPARA
};

/*@class Observer
 * @brief Interfaz base para todos los observadores que reaccionan a eventos de Personaje.
 * Cualquier clase que quiera recibir notificaciones de eventos de un Personaje
 * debe heredar de esta interfaz e implementar el método onNotify.*/
class Observer {
public:
    /* @brief Método que se llama cuando un personaje notifica un evento.
     * @param personaje Referencia al personaje que generó el evento.
     * @param evento Evento que ocurrió.*/
    virtual void onNotify(const Personaje& personaje, Evento evento) = 0;

    virtual ~Observer() {}/*@brief Destructor virtual de la clase Observer.*/
};