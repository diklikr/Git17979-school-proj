#include "Personaje.h"


//con ayuda de chat gpt

void Personaje::notify(Evento evento) {
	for (int i = 0; i < numObservers_; ++i) {
		observadores_[i]->onNotify(*this, evento);
	}
}
void Personaje::agregarObserver(Observer* observer) {
	if (!observer) return;
	if (numObservers_ >= MAX_OBSERVERS) {
		std::cout << "[Subject] No se pueden agregar mas observadores (MAX_OBSERVERS alcanzado).\n";
		return;
	}
	observadores_[numObservers_++] = observer;
}
Personaje::Personaje(float health, float maxHealth, float speed, int damage, float jumpHeight)
{
	std::cout << "llamando constructor con variables" << std::endl;
	_health = health;
	_maxHealth = maxHealth;
	_speed = speed;
	_damage = damage;
	_jumpheight = jumpHeight;
	numObservers_ = 0;
}

Personaje::Personaje() 
	: currentState_(State::IDLE), stateCounter_(0)
{
	std::cout << "llamando constructor default" << std::endl;
	_health = 100;
	_maxHealth = 100;
	_speed = 10;
	_damage = 10;
	_jumpheight = 10;
	numObservers_ = 0;

}

Personaje::~Personaje()
{
	std::cout << "llamando destructor" << std::endl;
}
void Personaje::handleInput(char input)
{
    switch (currentState_)
    {
    case State::IDLE:
		if (input == 'w') {
			Saltar();
		}
		else if (input == 'f') {
			Disparar();
		}
		else if (input == 'a')
		{
			Agacharse();
		}

    case State::JUMPING:
		std::cout << "Personaje está en el aire y no puede realizar acciones." << std::endl;
        break;

    case State::ATTACKING:
		std::cout << "Personaje está atacando y no puede realizar acciones." << std::endl;
        break;
    }
}

void Personaje::update()
{
    if (currentState_ == State::JUMPING || currentState_ == State::ATTACKING) {
        stateCounter_++;
        if (stateCounter_ >= 2) { // simulamos que después de 2 frames vuelve a IDLE
            currentState_ = State::IDLE;
			std::cout << "Personaje vuelve a estado IDLE." << std::endl;
        }
    }
}

void Personaje::Saltar()
{
	if (currentState_ == State::IDLE) {
		currentState_ = State::JUMPING;
		stateCounter_ = 0;
		std::cout << "Personaje salta." << std::endl;
	}
}

void Personaje::Disparar()
{
	if (currentState_ == State::IDLE) {
		currentState_ = State::ATTACKING;
		stateCounter_ = 0;
		std::cout << "Personaje ataca." << std::endl;
	}
}

float Personaje::GetJumpHeight()
{
	return _jumpheight;
}

void Personaje::Agacharse() {
	std::cout << "El personaje SE AGACHA." << std::endl;
}

void Personaje::SetJumpHeight(float jumpHeight)
{
	_jumpheight = jumpHeight;
}

float Personaje::GetHealth()
{
	return _health;
}

void Personaje::SetHealth(float health)
{
	_health = health;
	_health -= _damage;
	if (_health <= 0)
	{
		_health = 0;
		std::cout << "Personaje ha muerto." << std::endl;
	}
}

float Personaje::GetMaxHealth()
{
	return _maxHealth;
}

void Personaje::SetMaxHealth(float maxhealth)
{
	_maxHealth = maxhealth;
}

float Personaje::GetSpeed()
{
	return _speed;
}

void Personaje::SetSpeed(float speed)
{
	_speed = speed;
}


void Personaje::getdamage(int damage)
{
	return SetHealth(_health - damage);
}

void Personaje::SetDamage(int damage)
{
	_damage = damage;
}
