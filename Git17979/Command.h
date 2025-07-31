#pragma once
#include <iostream>
#include <map>
#include "Personaje.h"
class Command
{
public:
    virtual ~Command() {}
    virtual void execute() = 0;
};

class SaltarCommand : public Command {
public:
    SaltarCommand(Personaje* personaje) : personaje_(personaje) {}
    void execute() override { personaje_->Saltar(); }
private:
    Personaje* personaje_;
};

class DispararCommand : public Command {
public:
    DispararCommand(Personaje* personaje) : personaje_(personaje) {}
    void execute() override { personaje_->Disparar(); }
private:
    Personaje* personaje_;
};

// NUEVA CLASE
class AgacharseCommand : public Command {
public:
    AgacharseCommand(Personaje* personaje) : personaje_(personaje) {}
    void execute() override { personaje_->Agacharse(); }
private:
    Personaje* personaje_;
};

