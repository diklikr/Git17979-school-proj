#pragma once
#include "Observer.h"

class Logros : public Observer
{
public:
	void onNotify(const Personaje& personaje, Evento evento) override;
};

