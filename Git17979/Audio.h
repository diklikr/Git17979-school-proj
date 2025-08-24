#pragma once
#include "Observer.h"
#include "Soundevent.h"

class Audio : public Observer
{
public:
	void onNotify(const Personaje& personaje, Evento evento) override;

	void solicitarSonido(Soundevent event);
	 Audio() : numPending_(0) {}
	void procesarEventos();

private:
	static const int MAX_PENDING = 16;
	Soundevent pending_[MAX_PENDING];
	int numPending_;
	const char* toString(SoundID id);

};


