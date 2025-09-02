/**
 * @file Personaje.h
 * @brief Declaraci�n de la clase Personaje, que representa un ente jugable dentro del juego.
 */

#pragma once
#include <iostream>
#include "Observer.h"

 /**
  * @class Personaje
  * @brief Representa a un personaje del juego que puede realizar acciones como saltar, disparar y agacharse.
  * Adem�s, implementa el patr�n agregarObserver para notificar eventos a otros sistemas (ej. audio, logros).
  */
class Personaje {
public:
    /**
     * @enum State
     * @brief Estados posibles en los que se puede encontrar el personaje.
     */
    enum class State { IDLE, JUMPING, ATTACKING };

    /**
     * @brief Constructor con par�metros personalizados.
     * @param health Salud inicial del personaje.
     * @param maxHealth Salud m�xima del personaje.
     * @param speed Velocidad de movimiento.
     * @param damage Da�o que inflige el personaje.
     * @param jumpHeight Altura del salto del personaje.
     */
    Personaje(float health, float maxHealth, float speed, int damage, float jumpHeight);

    
    Personaje(); /*@brief Constructor por defecto. Inicializa al personaje con valores est�ndar. */
	~Personaje();/*@brief Destructor de la clase Personaje.*/
    void Saltar(); /*@brief Ejecuta la acci�n de salto y cambia el estado a JUMPING.*/
    void Disparar();  /*@brief Ejecuta la acci�n de disparo y cambia el estado a ATTACKING.*/
     void Agacharse(); /*@brief Ejecuta la acci�n de agacharse.*/
    void handleInput(char input);/*@brief Maneja la entrada del usuario y cambia el estado seg�n el input recibido.@param input Caracter que representa la acci�n*/
    void update(); /*@brief Actualiza el estado del personaje (Idle, Jumping, Attacking).*/
    void getdamage(int damage);    /*@brief Aplica da�o al personaje reduciendo su salud.@param damage Cantidad de da�o recibido.*/
    float GetJumpHeight();/*@brief Obtiene la altura de salto del personaje.@return Altura de salto.*/
    void SetJumpHeight(float jumpHeight);/* @brief Establece una nueva altura de salto.@param jumpHeight Altura de salto en unidades de juego.*/
    float GetHealth(); /*@brief Obtiene la salud actual del personaje.@return Salud actual.*/
    void SetHealth(float health); /* @brief Establece la salud del personaje.@param health Nueva cantidad de salud.*/
    float GetMaxHealth();/*@brief Obtiene la salud m�xima del personaje.@return Salud m�xima.*/
    void SetMaxHealth(float maxhealth); /*@brief Establece la salud m�xima del personaje.@param maxhealth Nueva salud m�xima.*/
    float GetSpeed();/*@brief Obtiene la velocidad del personaje. @return Velocidad actual.*/
    void SetSpeed(float speed);/*@brief Establece la velocidad del personaje. @param speed Nueva velocidad.*/
    void SetDamage(int damage); /*@brief Establece el da�o base que inflige el personaje.@param damage Nuevo valor de da�o.*/
    void notify(Evento evento);/*@brief Notifica un evento a todos los observadores registrados.@param evento Evento que se env�a a los observadores.*/
    void agregarObserver(Observer* observer); /*@brief Agrega un nuevo observador al personaje. @param observer Puntero al observador a registrar.*/
    static const int MAX_OBSERVERS = 10;  /** @brief M�ximo n�mero de observadores que el personaje puede tener. */
    Observer* observadores_[MAX_OBSERVERS];  /** @brief Lista de observadores registrados. */
    int numObservers_; /** @brief N�mero actual de observadores registrados. */
	
private:
	State currentState_; ///< Estado actual del personaje
	int stateCounter_;   ///< Contador de frames para manejar estados temporales

	float _health;       ///< Salud actual.
	float _speed;        ///< Velocidad actual
	int _damage;         ///< Da�o que inflige
	float _jumpheight;   ///< Altura de salto
	float _maxHealth;    ///< Salud m�xima

};

