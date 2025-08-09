#pragma once
#include <iostream>
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

	float GetJumpHeight();
	void SetJumpHeight(float jumpHeight);
	float GetHealth();
	void SetHealth(float health);
	float GetMaxHealth();
	void SetMaxHealth(float maxhealth);
	float GetSpeed();
	void SetSpeed(float speed);
	int GetDamage();
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
	
};

