#include "Logros.h"

void Logros::onNotify(const Personaje& personaje, Evento evento)
{
    if (evento == Evento::PERSONAJE_RECIBE_DANO) {
            std::cout << "[LOGROS] Notificaci�n: logro desbloqueado\n";
        }
  
}
