/* @file Command.h
 * @brief Declaración de la interfaz Command y sus implementaciones concretas.
 * Esta clase y sus derivados implementan el patrón Command, permitiendo encapsular acciones del Personaje en objetos ejecutables de manera desacoplada.*/
#pragma once
#include <iostream>
#include "Personaje.h"

 /* @class Command
  * @brief Interfaz base para todos los comandos que se pueden ejecutar sobre un Personaje.*/
class Command {
public:
    virtual ~Command() {} /*@brief Destructor virtual.*/
    virtual void execute() = 0; /*@brief Ejecuta la acción encapsulada por el comando.*/
};

/* @class SaltarCommand
 * @brief Comando concreto que hace saltar al personaje.*/
class SaltarCommand : public Command {
public:
    /* @brief Constructor.
     * @param personaje Puntero al personaje sobre el que se ejecutará el comando.*/
    SaltarCommand(Personaje* personaje) : personaje_(personaje) {}
    void execute() override { personaje_->Saltar(); }/*@brief Ejecuta el salto del personaje.*/

private:
    Personaje* personaje_; ///< Personaje objetivo del comando
};

/* @class DispararCommand
 * @brief Comando concreto que hace disparar al personaje.*/
class DispararCommand : public Command {
public:
    /* @brief Constructor.
     * @param personaje Puntero al personaje sobre el que se ejecutará el comando.*/
    DispararCommand(Personaje* personaje) : personaje_(personaje) {}
    void execute() override { personaje_->Disparar(); }/*@brief Ejecuta el disparo del personaje.*/

private:
    Personaje* personaje_; ///< Personaje objetivo del comando
};

/* @class AgacharseCommand
 * @brief Comando concreto que hace agacharse al personaje.*/
class AgacharseCommand : public Command {
public:
    /* @brief Constructor.
     * @param personaje Puntero al personaje sobre el que se ejecutará el comando.*/
    AgacharseCommand(Personaje* personaje) : personaje_(personaje) {}
    void execute() override { personaje_->Agacharse(); } /*@brief Ejecuta la acción de agacharse del personaje.*/

private:
    Personaje* personaje_; ///< Personaje objetivo del comando
};