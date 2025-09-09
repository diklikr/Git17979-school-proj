#include "Audio.h"
#include "../Core/Personaje.h"
#include <iostream>

Soundevent Soundevents;

void Audio::onNotify(const Personaje& personaje, Evento evento) {
	if (evento == Evento::PERSONAJE_RECIBE_DANO) {
		std::cout << "[AUDIO] Notificación: sonido de dolor\n";
	}
	if (evento == Evento::PERSONAJE_SALTAR) {
		std::cout << "[AUDIO] Notificación: sonido de salto\n";
	}
	if (evento == Evento::PERSONAJE_DISPARA) {
		std::cout << "[AUDIO] Notificación: sonido de disparo\n";
	}
}

void Audio::solicitarSonido(Soundevent event) {
    if (Audio::numPending_ >= MAX_PENDING) {
        std::cout << "[AUDIO] Cola llena. Evento descartado.\n";
        return;
    }
    Audio::pending_[numPending_++] = event;
}

void Audio::procesarEventos() {
    // Filtrado de duplicados
    Soundevent eventos[MAX_PENDING];
    int numUnicos = 0;

    for (int i = 0; i < numPending_; ++i) {
        Soundevent c = pending_[i];
        bool existe = false;
        for (int j = 0; j < numUnicos; ++j) {
            if (eventos[j] == c) { existe = true; break; }
        }
        if (!existe) {
            eventos[numUnicos++] = c;
        }
    }

    // Procesamiento
    for (int i = 0; i < numUnicos; ++i) {
        std::cout << "[AUDIO] Reproduciendo sonido " << toString(eventos[i].id) << ".\n";
    }

    // Limpieza
    numPending_ = 0;
}

const char* Audio::toString(SoundID id)
{
    switch (id) {
    case SoundID::DAMAGE:  return "DAMAGE";
    case SoundID::SALTAR: return "SALTAR";
    case SoundID::DEAD:return "DEAD";
    default:            return "UNKNOWN";
    }
}
