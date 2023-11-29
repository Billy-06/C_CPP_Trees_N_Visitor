#include "Player.h"
#include <iostream>

Player::Player()
{
	std::vector<std::string> attackMoves = {
		"Double Jab Punch",
		"[COMBO] Low Right Kick, Right Jab Punch",
		"Tackle",
		"Round Kick, Floor Opponent"
	};

	_name = "Default Player Name";
	_health = 100;
	_attackMoves = {
		attackMoves[0],
		attackMoves[1],
		attackMoves[2],
		attackMoves[3]
	};
	_friendliness = false;
	_backpack = {};
	_shieldsUp = false;
	_attackPower = 50;

	_score = 0;
	_monstersSlain = 0;
}

Player::Player(std::string& name)
	: Character(name)
{
	_score = 0;
	_monstersSlain = 0;
}

Player::Player(const Player& player)
	: Character(player)
{
	_score = player._score;
	_monstersSlain = player._monstersSlain;
}

Player::Player(const Character& character)
	: Character(character)
{
	_score = 0;
	_monstersSlain = 0;
}

Player::~Player()
{
	_name = "";
	_health = 0;
	_attackMoves.clear();
	_friendliness = false;
	_backpack.clear();
	_shieldsUp = false;
	_attackPower = 0;

	_score = 0;
	_monstersSlain = 0;
}

int Player::GetScore() const
{
	return _score;
}

void Player::SetScore(int score)
{
	_score = score;
}

int Player::GetMonstersSlain() const
{
	return _monstersSlain;
}

void Player::SetMonstersSlain(int monstersSlain)
{
	_monstersSlain = monstersSlain;
}

void Player::ShowStats() const
{
	std::cout << "###################################################" << std::endl;
	std::cout << "\tPlayer Name: " << _name << "\tHealth: " << _health << std::endl;
	std::cout << "###################################################" << std::endl;
	std::cout << "Attack Moves: " << std::endl;
	std::cout << "------------------------------" << std::endl;

	for (auto& move : _attackMoves)
	{
		std::cout << "}=>" << move << std::endl;
	}
	std::cout << "------------------------------" << std::endl;
	std::cout << "Friendliness: " << ((_friendliness) ? "Friendly" : "Not Friendly") << std::endl;
	std::cout << "Backpack: " << std::endl;
	std::cout << "------------------------------" << std::endl;

	for (auto& item : _backpack)
	{
		item.Display();
	}
	std::cout << "------------------------------" << std::endl;
	std::cout << "Shields Up: " << ((_shieldsUp) ? "Shielded" : "Not Shielded") << std::endl;
	std::cout << "Player Attack Power: " << _attackPower << std::endl;
	std::cout << "Player Score: " << _score << std::endl;
	std::cout << "Player Monsters Slain: " << _monstersSlain << std::endl;
}

void Player::AcceptVisitor(PlayerVisitor* visitor)
{
	visitor->VisitPlayer(this);
}

void PlayerVisitor::VisitPlayer(Player* player)
{
	std::cout << "Player Visitor Upgraded Health to: " << player->GetHealth() + 30 << std::endl;
	player->SetHealth(player->GetHealth() + 30);
	player->SetScore(player->GetScore() + 40);
	std::cout << "###################################################" << std::endl;
	std::cout << "\tPlayer Name: " << player->GetName() << "\tHealth: " << player->GetHealth() << std::endl;
	std::cout << "###################################################" << std::endl;
	std::cout << "Attack Moves: " << std::endl;
	std::cout << "------------------------------" << std::endl;

	for (auto& move : player->GetAttackMoves())
	{
		std::cout << "}=>" << move << std::endl;
	}
	std::cout << "------------------------------" << std::endl;
	std::cout << "Friendliness: " << ((player->GetFriendliness()) ? "Friendly" : "Not Friendly") << std::endl;
	std::cout << "Backpack: " << std::endl;
	std::cout << "------------------------------" << std::endl;

	for (auto& item : player->GetBackpack())
	{
		item.Display();
	}
	std::cout << "------------------------------" << std::endl;
	std::cout << "Shields Up: " << ((player->GetShieldsUp()) ? "Shielded" : "Not Shielded") << std::endl;
	std::cout << "Player Attack Power: " << player->GetAttackPower() << std::endl;
	std::cout << "Player Score Updated (by the visitor): " << player->GetScore() << std::endl;
	std::cout << "Player Monsters Slain: " << player->GetMonstersSlain() << std::endl;
}
