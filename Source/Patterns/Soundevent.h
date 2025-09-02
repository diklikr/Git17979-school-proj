/*@file SoundEvent.h
 * @brief Declaraci�n de estructuras para representar eventos de sonido en el juego.*/

#pragma once

 /*@enum SoundID
  * @brief Identificadores de sonidos disponibles en el juego.
  *
  * Ejemplos:
  * - DAMAGE: sonido al recibir da�o
  * - SALTAR: sonido al saltar
  * - DEAD: sonido al morir*/
enum class SoundID { DAMAGE, SALTAR, DEAD };

/*@struct Soundevent
 * @brief Representa un evento de sonido que puede ser notificado a un sistema de audio.
 *
 * Contiene un identificador de tipo SoundID y permite comparaci�n con otros eventos
 * para verificar si son iguales.*/
struct Soundevent {
public:
    /// Identificador del sonido que se desea reproducir.
    SoundID id;

    /*@brief Operador de comparaci�n.
     * @param other Otro Soundevent a comparar.
     * @return true si ambos eventos tienen el mismo SoundID, false en caso contrario.*/
    bool operator==(const Soundevent& other) const {
        return id == other.id;
    }
};
