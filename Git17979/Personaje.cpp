#include "Personaje.h"

Personaje::Personaje(float health, float maxHealth, float speed, int damage, float jumpHeight)
{
	std::cout << "llamando constructor con variables" << std::endl;
	_health = health;
	_maxHealth = maxHealth;
	_speed = speed;
	_damage = damage;
	_jumpheight = jumpHeight;
}

Personaje::Personaje()
{
	std::cout << "llamando constructor default" << std::endl;
	_health = 100;
	_maxHealth = 100;
	_speed = 10;
	_damage = 10;
	_jumpheight = 10;
}

Personaje::~Personaje()
{
	std::cout << "llamando destructor" << std::endl;
}

void Personaje::Saltar()
{
	std::cout << "saltando" << std::endl;
}

void Personaje::Disparar()
{
	std::cout << "Disparando" << std::endl;
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
}

float Personaje::GetMaxHealth()
{
	return _maxhealth;
}

void Personaje::SetMaxHealth(float maxhealth)
{
	_maxhealth = maxhealth;
}

float Personaje::GetSpeed()
{
	return _speed;
}

void Personaje::SetSpeed(float speed)
{
	_speed = speed;
}

int Personaje::GetDamage()
{
	return _damage;
}

void Personaje::SetDamage(int damage)
{
	_damage = damage;
}
