/* @file Audio.h
 * @brief Declaraci�n de la clase Audio, que implementa el patr�n Observer para reproducir sonidos.
 * Esta clase observa eventos de un Personaje y genera sonidos correspondientes. Adem�s, mantiene una cola de eventos de sonido pendientes para ser procesados.*/
#pragma once
#include "Observer.h"
#include "SoundEvent.h"

 /* @class Audio
  * @brief Sistema de audio que escucha eventos del personaje y reproduce sonidos.
  * Implementa la interfaz Observer. Puede recibir notificaciones de eventos, agregar sonidos a una cola y procesarlos de manera ordenada.*/
class Audio : public Observer {
public:
    /* @brief M�todo que se llama cuando un personaje notifica un evento.
     * @param personaje Referencia al personaje que genera el evento.
     * @param evento Evento que ocurri�.
     * Dependiendo del evento, se puede reproducir un sonido espec�fico.*/
    void onNotify(const Personaje& personaje, Evento evento) override;

    /* @brief Solicita reproducir un sonido y lo agrega a la cola de eventos pendientes.
     * @param event Evento de sonido a reproducir.*/
    void solicitarSonido(Soundevent event);
    Audio() : numPending_(0) {} /*@brief Constructor. Inicializa la cola de eventos pendientes.*/
    void procesarEventos();/*@brief Procesa todos los eventos de sonido pendientes y los reproduce.*/

private:
    static const int MAX_PENDING = 16; ///< M�ximo n�mero de eventos de sonido pendientes
    Soundevent pending_[MAX_PENDING];  ///< Cola de eventos de sonido pendientes
    int numPending_;                   ///< N�mero actual de eventos pendientes

    /* @brief Convierte un SoundID a su representaci�n en cadena.
     * @param id Identificador del sonido.
     * @return Nombre del sonido como cadena de caracteres.*/
    const char* toString(SoundID id);
};