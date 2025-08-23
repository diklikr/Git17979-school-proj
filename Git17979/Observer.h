#include <iostream>
#include <vector>

enum class Evento { PERSONAJE_RECIBE_DANO };
class Personaje;

class Observer {
public:
    virtual void onNotify(const Personaje& personaje, Evento evento) = 0;
    virtual ~Observer() {}
};

