#include <iostream>
#include <vector>


class Personaje;
enum class Evento { 

    PERSONAJE_RECIBE_DANO, PERSONAJE_SALTAR, PERSONAJE_DISPARA

};

class Observer {
public:
    virtual void onNotify(const Personaje& personaje, Evento evento) = 0;
    virtual ~Observer() {}
};

