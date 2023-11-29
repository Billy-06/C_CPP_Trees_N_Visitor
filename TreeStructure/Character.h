#pragma once
#include <string>
#include <vector>

#include "Clue.h"
#include "Item.h"

class Room;
/**
 * @file Character.h
 * @author Billy Ndegwah Micah
 *
 * Description: This header files contains the declaration of the Character class.
 *
 * Properties:
 * ----------
 * > _name: string - This is the name of the character.
 * > _health: float - This is the health of the character.
 * > _attackMoves: vector<string> - This is the vector of attack moves the character has.
 * > _friendliness: bool - This is the friendliness of the character.
 * > _backpack: vector<Item> - This is the vector of items the character has.
 * > _shieldsUp: bool - This is the shields up status of the character.
 * > _attackPower: float - This is the attack power of the character.
 *
 * Methods:
 * --------
 * > Getters and setters for the properties.
 * > Character() - This is the default constructor.
 * > Character(name: string) - This is the overloaded constructor.
 * > Character(const Character& character) - This is the copy constructor.
 * > ~Character() - This is the destructor.
 * > ToggleShieldsUp() - This method toggles the shields up status of the character.
 * > ToggleFriendliness() - This method toggles the friendliness of the character.
 * > PickItem(item: Item) - This method adds an item to the character's backpack.
 * > Attack(character: Character*) - This method attacks another character.
 * > EnterRoom(room: Room*) - This method allows the character to enter a room.
 * > ShowStats() - This method displays the character's status.
 */
class Character
{
protected:
	std::string _name;
	float _health;
	std::vector<std::string> _attackMoves;
	bool _friendliness;
	std::vector<Item> _backpack;
	bool _shieldsUp;
	float _attackPower;

public:
	/**
	 * @brief This is the default constructor.
	*/
	Character();

	/**
	 * @brief This is the overloaded constructor.
	 * @param name - the name of the character.
	*/
	Character(std::string& name);

	/**
	 * @brief This is the copy constructor.
	 * @param character - the character to be copied.
	*/
	Character(const Character& character);

	/**
	 * @brief This is the destructor.
	*/
	virtual ~Character();

	/**
	 * @brief This is the dereference operator.
	 * @return a reference to the character.
	*/
	const Character& operator*() const;

	/**
	 * @brief Getter for the _name property.
	 * @return a string representing the name of the character.
	*/
	std::string& GetName();

	/**
	 * @brief Setter for the _name property.
	 * @param name - the name of the character.
	*/
	void SetName(std::string& name);

	/**
	 * @brief Getter for the _health property.
	 * @return a float representing the health of the character.
	*/
	float GetHealth() const;

	/**
	 * @brief Setter for the _health property.
	 * @param health - the health of the character.
	*/
	void SetHealth(float health);

	/**
	 * @brief Getter for the _attackMoves property.
	 * @return a vector of strings representing the attack moves of the character.
	*/
	std::vector<std::string>& GetAttackMoves();

	/**
	 * @brief Setter for the _attackMoves property.
	 * @param attackMoves - the attack moves of the character.
	*/
	void SetAttackMoves(std::vector<std::string>& attackMoves);

	/**
	 * @brief Getter for the _friendliness property.
	 * @return a bool representing the friendliness of the character.
	*/
	bool GetFriendliness() const;

	/**
	 * @brief Getter for the _backpack property.
	 * @return a vector of items representing the backpack of the character.
	*/
	std::vector<Item>& GetBackpack();

	/**
	 * @brief Setter for the _backpack property.
	 * @param backpack - the backpack of the character.
	*/
	void SetBackpack(std::vector<Item>& backpack);

	/**
	 * @brief Getter for the _shieldsUp property.
	 * @return a bool representing the shields up status of the character.
	*/
	bool GetShieldsUp() const;

	/**
	 * @brief Getter for the _attackPower property.
	 * @return a float representing the attack power of the character.
	*/
	float GetAttackPower() const;

	/**
	 * @brief Setter for the _attackPower property.
	 * @param attackPower - the attack power of the character.
	*/
	void SetAttackPower(float attackPower);

	/**
	 * @brief This method toggles the shields up status of the character.
	*/
	bool ToggleShieldsUp();

	/**
	 * @brief This method toggles the friendliness of the character.
	*/
	bool ToggleFriendliness();

	/**
	 * @brief This method adds an item to the character's backpack.
	 * @param item - the item to be added.
	*/
	void PickItem(Item* item);

	/**
	 * @brief This method attacks another character.
	 * @param character - the character to be attacked.
	*/
	void Attack(Character* character) const;

	/**
	 * @brief This method allows the character to enter a room.
	 * @param room - the room to be entered.
	*/
	void EnterRoom(Room* room);

	/**
	 * @brief This method displays the character's status.
	 */
	virtual void ShowStats() const;

};

/**
 * @file Room.h
 * @author Billy Ndegwah Micah
 *
 * Description: This file contains the declaration of the Room class.
 *
 * Properties:
 * -----------
 * > _name: string - This is the name of the room.
 * > _clues: vector<string> - This is the vector of clues in the room.
 * > _monsters: vector<Enemy> - This is the vector of monsters in the room.
 * > _treasureTrove: vector<Item> - This is the vector of items in the room.
 * > _playerInRoom: bool - This checks whether or not the player is in the room.
 * > _accessGranted: bool - This is the access granted status of the player.
 * > _roomNumber: int - This is the room number.
 * > _prevRoom: Room* - This is the pointer to the previous room.
 * > _nextRoomOne: Room* - This is the pointer to the first next room.
 * > _nextRoomTwo: Room* - This is the pointer to the second next room.
 *
 * Methods:
 * --------
 * > Getters and setters for the properties.
 * > Room() - This is the default constructor.
 * > Room(name: string, roomNumber: int, clues: vector<string>, monsters: vector<Enemy>, treasureTrove: vector<Item>) - This is the overloaded constructor.
 * > Room(const Room& room) - This is the copy constructor.
 * > ~Room() - This is the destructor.
 * > TogglePlayerPresence() - This method toggles the player in room status.
 * > ToggleAccess() - This method toggles the access granted status.
 * > WelcomeMessage() - This method displays the welcome message.
 */
class Room
{
public:
	typedef Room* RoomPtr;
	static RoomPtr Sentinel;

private:
	std::string _name;
	std::vector<Clue> _clues;
	std::vector<Character> _monsters;
	std::vector<Item> _treasureTrove;
	bool _playerInRoom;
	bool _accessGranted;
	int _roomNumber;
	Room* _prevRoom;
	Room* _nextRoomOne;
	Room* _nextRoomTwo;

public:
	/**
	 * @brief This is the default constructor.
	*/
	Room();

	/**
	 * @brief This is the overloaded constructor.
	 * @param name - the name of the room.
	 * @param roomNumber - the room number.
	*/
	Room(const std::string& name, int roomNumber);

	/**
	 * @brief This is the copy constructor.
	 * @param room - the room to be copied
	*/
	Room(const Room& room);

	/**
	 * @brief This is the destructor.
	*/
	~Room();

	void Setup();

	/**
	 * @brief This is the dereference operator.
	 * @return a reference to the room.
	*/
	const Room& operator*() const;

	/**
	 * @brief Getter for the _name property.
	 * @return a string representing the name of the room.
	*/
	std::string GetName() const;

	/**
	 * @brief Setter for the _name property.
	 * @param name - the name of the room.
	*/
	void SetName(const std::string& name);

	/**
	 * @brief Getter for the _clues property.
	 * @return a vector of strings representing the clues in the room.
	*/
	std::vector<Clue>& GetClues();

	/**
	 * @brief Setter for the _clues property.
	 * @param clues - the vector of clues in the room.
	*/
	void SetClues(const std::vector<Clue>& clues);

	/**
	 * @brief Getter for the _monsters property.
	 * @return a vector of Enemy objects representing the monsters in the room.
	*/
	std::vector<Character>& GetMonsters();

	/**
	 * @brief Setter for the _monsters property.
	 * @param monsters - the vector of monsters in the room.
	*/
	void SetMonsters(const std::vector<Character>& monsters);

	/**
	 * @brief Getter for the _treasureTrove property.
	 * @return a vector of Item objects representing the items in the room.
	*/
	std::vector<Item> GetTreasureTrove() const;

	/**
	 * @brief Setter for the _treasureTrove property.
	 * @param treasureTrove - the vector of items in the room.
	*/
	void SetTreasureTrove(const std::vector<Item>& treasureTrove);

	/**
	 * @brief Getter for the _playerInRoom property.
	 * @return a bool representing the player in room status.
	*/
	bool IsPlayerInRoom() const;

	/**
	 * @brief Getter for the _accessGranted property.
	 * @return a bool representing the access granted status.
	*/
	bool IsAccessGranted() const;

	/**
	 * @brief Getter for the _roomNumber property.
	 * @return an integer representing the room number.
	*/
	int GetRoomNumber() const;

	/**
	 * @brief Setter for the _roomNumber property.
	 * @param roomNumber - the room number.
	*/
	void SetRoomNumber(int roomNumber);

	/**
	 * @brief Getter for the _prevRoom property.
	 * @return a pointer to the previous room.
	*/
	Room* GetPrevRoom() const;

	/**
	 * @brief Setter for the _prevRoom property.
	 * @param prevRoom - the previous room.
	*/
	void SetPrevRoom(Room* prevRoom);

	/**
	 * @brief Getter for the _nextRoomOne property.
	 * @return a pointer to the first next room.
	*/
	Room* GetNextRoomOne() const;

	/**
	 * @brief Setter for the _nextRoomOne property.
	 * @param nextRoomOne - the first next room.
	*/
	void SetNextRoomOne(Room* nextRoomOne);

	/**
	 * @brief Getter for the _nextRoomTwo property.
	 * @return a pointer to the second next room.
	*/
	Room* GetNextRoomTwo() const;

	/**
	 * @brief Setter for the _nextRoomTwo property.
	 * @param nextRoomTwo - the second next room.
	*/
	void SetNextRoomTwo(Room* nextRoomTwo);

	/**
	 * @brief This method toggles the player in room status.
	 * @return a bool representing the player in room status.
	*/
	bool TogglePlayerPresence();

	/**
	 * @brief This method toggles the access granted status.
	 * @return a bool representing the access granted status.
	*/
	bool ToggleAccess();

	/**
	 * @brief This method displays the welcome message.
	*/
	void WelcomeMessage();
};