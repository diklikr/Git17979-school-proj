#pragma once
#include <iostream>
#include "Observer.h"
class Personaje
{
public:
	enum class State { IDLE, JUMPING, ATTACKING };

	Personaje(float health, float maxHealth, float speed, int damage, float jumpHeight);
	Personaje();
	~Personaje();
	void Saltar();
	void Disparar();
	void Agacharse();
	void handleInput(char input);
	void update();
	
	static const int MAX_OBSERVERS = 10;
	Observer* observadores_[MAX_OBSERVERS];
	int numObservadores_;


	void getdamage(int damg) {
		vida_ -= damg;
		if (vida_ <= 0) vida_ = 0;

		std::cout << "Player Recibió " << damg << " de daño. Vida restante: " << vida_ << "\n";
	}

	int getVida() const { return vida_; }
	
	void agregarObserver(Observer* observer) {
		if (numObservadores_ < MAX_OBSERVERS) {
			observadores_[numObservadores_++] = observer;
		}
	}

	void recibirDano(int dano) {
		vida_ -= dano;
		std::cout << "Personaje recibe " << dano << " de dano. Vida actual: " << vida_ << std::endl;
		notificar(Evento::PERSONAJE_RECIBE_DANO);
	}

	int getVida() const { return vida_; }

	float GetJumpHeight();
	void SetJumpHeight(float jumpHeight);
	float GetHealth();
	void SetHealth(float health);
	float GetMaxHealth();
	void SetMaxHealth(float maxhealth);
	float GetSpeed();
	void SetSpeed(float speed);

	void SetDamage(int damage);
	
private:
	State currentState_;
	int stateCounter_;
	float _health;
	float _speed;
	int _damage;
	float _maxhealth;
	float _jumpheight;
	float _maxHealth;
	bool notify = false;
	int vida_;
	static const int MAX_OBSERVERS = 3;
	Observer* observers_[MAX_OBSERVERS];
	int numObservers_;

	Observer* observadores_[MAX_OBSERVERS];
	int numObservadores_;
	int vida_;

	void notify(Evento evento) {
		for (int i = 0; i < numObservadores_; ++i) {
			observadores_[i]->onNotify(*this, evento);
		}
	}
};

