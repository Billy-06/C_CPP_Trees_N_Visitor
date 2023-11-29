#include "Enemy.h"
#include <iostream>

Enemy::Enemy()
{
	_name = "Default Character Name";
	_health = 100;
	_attackMoves = {};
	_friendliness = false;
	_backpack = {};
	_shieldsUp = false;
	_attackPower = 50;
	_venomReserve = 0;
}

Enemy::Enemy(std::string& name, int venomReserve)
	: Character(name)
{
	_health = 100;
	_attackMoves = {};
	_friendliness = false;
	_backpack = {};
	_shieldsUp = false;
	_attackPower = 60;
	_venomReserve = venomReserve;
}

Enemy::Enemy(const Enemy& enemy)
	: Character(enemy)
{
	_venomReserve = enemy._venomReserve;
}

Enemy::Enemy(const Character& character, int venomReserve)
: Character(character)
{
	_venomReserve = venomReserve;
}

Enemy::~Enemy()
{
	_name = "";
	_health = 0;
	_attackMoves.clear();
	_friendliness = false;
	_backpack.clear();
	_shieldsUp = false;
	_attackPower = 0;
	_venomReserve = 0;
}

int Enemy::GetVenomReserve() const
{
		return _venomReserve;
}

void Enemy::SetVenomReserve(int venomReserve)
{
		_venomReserve = venomReserve;
}

void Enemy::ShowStats() const
{
	std::cout << "*************************************************" << std::endl;
	std::cout << "\tEnemy Name: " << _name << "\tHealth: " << _health << std::endl;
	std::cout << "*************************************************" << std::endl;
	std::cout << "Attack Moves: " << std::endl;
	std::cout << "------------------------------" << std::endl;

	for (auto& move: _attackMoves)
	{
		std::cout << "}=>" << move << std::endl;
	}
	std::cout << "------------------------------" << std::endl;
	std::cout << "Friendliness: " << ((_friendliness) ? "Friendly" : "Not Friendly") << std::endl;
	std::cout << "Backpack: " << std::endl;
	std::cout << "------------------------------" << std::endl;

	for (auto& item: _backpack)
	{
		item.Display();
	}
	std::cout << "------------------------------" << std::endl;
	std::cout << "Shields Up: " << ((_shieldsUp) ? "Shielded" : "Not Shielded") << std::endl;
	std::cout << "Attack Power: " << _attackPower << std::endl;
	std::cout << "Venom Reserve: " << _venomReserve << std::endl;
	std::cout << std::endl;
}