/*@file Logros.h
 * @brief Declaraci�n de la clase Logros, que implementa el patr�n Observer
 *        para reaccionar a eventos del Personaje y desbloquear logros.*/

#pragma once
#include "../Patterns/Observer.h"

 /*@class Logros
  * @brief Sistema de logros que observa eventos generados por un Personaje.
  *
  * Esta clase implementa el patr�n Observer. Su responsabilidad es escuchar
  * las notificaciones del personaje y, en base a los eventos recibidos,
  * desbloquear logros dentro del juego.*/
class Logros : public Observer {
public:
    /*@brief M�todo llamado cuando el personaje notifica un evento.
     * @param personaje Referencia al personaje que genera el evento.
     * @param evento Evento ocurrido (ej. SALTO, DISPARO, DA�O).
     *
     * Dependiendo del evento recibido, el sistema de logros puede
     * registrar que se ha cumplido cierta condici�n de logro.*/
    void onNotify(const Personaje& personaje, Evento evento) override;
};