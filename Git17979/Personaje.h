#pragma once
#include <iostream>
class Personaje
{
public:
	Personaje(float health, float maxHealth, float speed, int damage, float jumpHeight);
	Personaje();
	~Personaje();
	void Saltar();
	void Disparar();


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
	float _health;
	float _speed;
	int _damage;
	float _maxhealth;
	float _jumpheight;
	float _maxHealth;
	
};

