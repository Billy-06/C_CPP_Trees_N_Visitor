#include "Character.h"
#include "Clue.h"
#include <iostream>

Character::Character()
{
	std::vector<std::string> attackMoves = {
		"Double Jab Punch",
		"[COMBO] Low Right Kick, Right Jab Punch",
		"Tackle",
		"Round Kick, Floor Opponent"
	};

	_name = "Default Character Name";
	_health = 100;
	_attackMoves = {
		attackMoves[0],
		attackMoves[1],
		attackMoves[2],
		attackMoves[3]
	};
	_friendliness = false;
	_backpack = {
	};
	_shieldsUp = false;
	_attackPower = 120;
}

Character::Character(std::string& name)
{
	_name = name;
	_health = 100;
	_attackMoves = {};
	_friendliness = false;
	_backpack = {};
	_shieldsUp = false;
	_attackPower = 120;
}

Character::Character(const Character& character)
{
	_name = character._name;
	_health = character._health;
	_attackMoves = character._attackMoves;
	_friendliness = character._friendliness;
	_backpack = character._backpack;
	_shieldsUp = character._shieldsUp;
	_attackPower = character._attackPower;
}

Character::~Character()
{
	_name = "";
	_health = 0;
	_attackMoves.clear();
	_friendliness = false;
	_backpack.clear();
	_shieldsUp = false;
	_attackPower = 0;
}

const Character& Character::operator*() const
{
	return *this;
}

std::string& Character::GetName()
{
	return _name;
}

void Character::SetName(std::string& name)
{
	_name = name;
}

float Character::GetHealth() const
{
	return _health;
}

void Character::SetHealth(float health)
{
	_health = health;
}

std::vector<std::string>& Character::GetAttackMoves()
{
	return _attackMoves;
}

void Character::SetAttackMoves(std::vector<std::string>& attackMoves)
{
	_attackMoves = attackMoves;
}

bool Character::GetFriendliness() const
{
		return _friendliness;
}

std::vector<Item>& Character::GetBackpack()
{
	return _backpack;
}

void Character::SetBackpack(std::vector<Item>& backpack)
{
	_backpack = backpack;
}

bool Character::GetShieldsUp() const
{
	return _shieldsUp;
}

float Character::GetAttackPower() const
{
	return _attackPower;
}

void Character::SetAttackPower(float attackPower)
{
	_attackPower = attackPower;
}

bool Character::ToggleShieldsUp()
{
	_shieldsUp = !_shieldsUp;
	return _shieldsUp;
}

bool Character::ToggleFriendliness()
{
	_friendliness = !_friendliness;
	return _friendliness;
}

void Character::PickItem(Item* item)
{
	_backpack.push_back(*item);
}

void Character::Attack(Character* character) const
{
	if (_shieldsUp)
	{
		std::cout << _name << " is defending." << std::endl;
	}
	else
	{
		std::cout << _name << " is attacking." << std::endl;
		character->SetHealth(character->GetHealth() - _attackPower);
	}
}

void Character::EnterRoom(Room* room)
{
	std::cout<< _name << " has entered " << room->GetName() << "." << std::endl;
	room->TogglePlayerPresence();
}

void Character::ShowStats() const
{
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "Default Name: " << _name << "Health: " << _health << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "Attack Moves: " << std::endl;

	for (auto& move : _attackMoves)
	{
		std::cout << move << std::endl;
	}

	std::cout << "Friendliness: " << ((_friendliness) ? "Friendly" : "Not Friendly") << std::endl;
	std::cout << "Backpack: " << std::endl;

	for (auto& item : _backpack)
	{
		item.Display();
	}

	std::cout << "Shields Up: " << ((_shieldsUp) ? "Shielded" : "Not Shielded") << std::endl;
	std::cout << "Attack Power: " << _attackPower << std::endl;
}

/////////////////////////////////////////
////////    ROOM IMPLEMENTATIONS   //////
/////////////////////////////////////////

Room::Room()
{
	_name = "Default Room Name";
	_roomNumber = 10;

	Setup();

	_playerInRoom = false;
	_accessGranted = false;
	_prevRoom = Sentinel;
	_nextRoomOne = Sentinel;
	_nextRoomTwo = Sentinel;
}

Room::Room(const std::string& name, int roomNumber)
{
	

	_name = name;
	_roomNumber = roomNumber;

	Setup();

	_playerInRoom = false;
	_accessGranted = false;
	_prevRoom = Sentinel;
	_nextRoomOne = Sentinel;
	_nextRoomTwo = Sentinel;

}

Room::Room(const Room& room)
{
	_name = room._name;
	_clues = room._clues;
	_monsters = room._monsters;
	_treasureTrove = room._treasureTrove;
	_playerInRoom = room._playerInRoom;
	_accessGranted = room._accessGranted;
	_roomNumber = room._roomNumber;
	_prevRoom = room._prevRoom;
	_nextRoomOne = room._nextRoomOne;
	_nextRoomTwo = room._nextRoomTwo;
}

Room::~Room()
{
	_name = "";
	_clues.clear();
	_monsters.clear();
	_treasureTrove.clear();
	_playerInRoom = false;
	_accessGranted = false;
	_roomNumber = 0;
	_prevRoom = Sentinel;
	_nextRoomOne = Sentinel;
	_nextRoomTwo = Sentinel;
}

void Room::Setup()
{
	std::vector<std::string> cluesMsgs = {
	"This is clue message number 101",
	"This is clue message number 102",
	"This is clue message number 103",
	"This is clue message number 104",
	};
	std::vector<std::string> monstersNames = {
		"Fire Breathing Horse",
		"Stinging Robotic Wasp",
		"Multi-Head Black Mamba",
		"Hop Hop Toad"
	};
	std::vector<std::string> itemNames = {
		"Troy's Sword",
		"Belinda's Precious Necklace",
		"South African Diamond Jewel Pack",
		"Shariffah's Golden Knife"
	};

	_clues = {
		Clue(101, cluesMsgs[0], 3, _roomNumber),
		Clue(101, cluesMsgs[1], 3, _roomNumber),
		Clue(101, cluesMsgs[2], 3, _roomNumber),
		Clue(101, cluesMsgs[3], 3, _roomNumber)
	};
	_monsters = {
		Character(monstersNames[0]),
		Character(monstersNames[1]),
		Character(monstersNames[2]),
		Character(monstersNames[3])
	};
	_treasureTrove = {
		Item(itemNames[0], div(_roomNumber, 10).quot, 100),
		Item(itemNames[1], div(_roomNumber, 10).quot, 100),
		Item(itemNames[2], div(_roomNumber, 10).quot, 100),
		Item(itemNames[3], div(_roomNumber, 10).quot, 100)

	};
}
std::string Room::GetName() const
{
	return _name;
}

void Room::SetName(const std::string& name)
{
	_name = name;
}

std::vector<Clue>& Room::GetClues()
{
	return _clues;
}

void Room::SetClues(const std::vector<Clue>& clues)
{
	_clues = clues;
}

std::vector<Character>& Room::GetMonsters()
{
	return _monsters;
}

void Room::SetMonsters(const std::vector<Character>& monsters)
{
	_monsters = monsters;
}

std::vector<Item> Room::GetTreasureTrove() const
{
	return _treasureTrove;
}

void Room::SetTreasureTrove(const std::vector<Item>& treasureTrove)
{
	_treasureTrove = treasureTrove;
}

bool Room::IsPlayerInRoom() const
{
	return _playerInRoom;
}

bool Room::IsAccessGranted() const
{
	return _accessGranted;
}

int Room::GetRoomNumber() const
{
	return _roomNumber;
}

void Room::SetRoomNumber(int roomNumber)
{
	_roomNumber = roomNumber;
}

const Room& Room::operator*() const
{
	return *this;
}

Room* Room::GetPrevRoom() const
{
	return _prevRoom;
}

void Room::SetPrevRoom(Room* prevRoom)
{
	_prevRoom = prevRoom;
}

Room* Room::GetNextRoomOne() const
{
	return _nextRoomOne;
}

void Room::SetNextRoomOne(Room* nextRoomOne)
{
	_nextRoomOne = nextRoomOne;
}

Room* Room::GetNextRoomTwo() const
{
	return _nextRoomTwo;
}

void Room::SetNextRoomTwo(Room* nextRoomTwo)
{
	_nextRoomTwo = nextRoomTwo;
}

bool Room::TogglePlayerPresence()
{
	_playerInRoom = !_playerInRoom;
	return _playerInRoom;
}

bool Room::ToggleAccess()
{
	_accessGranted = !_accessGranted;
	return _accessGranted;
}

void Room::WelcomeMessage()
{
	std::cout << "===============================================" << std::endl;
	std::cout << "= Welcome to "<< _name << "    Room Number: " << _roomNumber << "  =" << std::endl;
	std::cout << "===============================================" << std::endl;
	std::cout << "In this room there both Monsters and Treasures" << std::endl;
	std::cout << "There a total of " << _treasureTrove.size() << " treasure Items as listed below:" << std::endl;
	std::cout << "----------   Treasures   ----------" << std::endl;
	for (auto& item : _treasureTrove)
	{
		item.Display();
	}
	std::cout << "Additionally you'll face some Monstrous enemies:" << std::endl;
	std::cout << "----------   Enemies   ----------" << std::endl;
	for (auto& monster : _monsters)
	{
		std::cout << monster.GetName() << " \t|\tAttack Power: " << monster.GetAttackPower() << std::endl;
	}
	std::cout << "Brace Yourself!!!" << std::endl;
	std::cout << "=========   END OF WELCOME MESSAGE   ========" << std::endl;
	std::cout << std::endl;
}


Room::RoomPtr Room::Sentinel;