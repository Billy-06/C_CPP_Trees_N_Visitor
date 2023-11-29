#pragma once
#include "Player.h"
#include "Enemy.h"

struct Position
{
	int x;
	int y;
};
/**
 * @file Dungeon.h
 * @author Billy Ndegwah Micah
 *
 * Description: This file contains the declaration of the Dungeon class.
 *
 * Properties:
 * -----------
 * > _player: Player* - This is the player.
 * > _entryRoom: Room* - This is the entry room.
 * > _spawnPoint: Position - This is the spawn point.
 *
 * Methods:
 * --------
 * > Dungeon() - This is the default constructor.
 * > Dungeon(player: Player*, entryRoom: Room*, spawnPoint: Position) - This is the overloaded constructor.
 * > Dungeon(const Dungeon& dungeon) - This is the copy constructor.
 * > ~Dungeon() - This is the destructor.
 * > Display() - This method displays the dungeon.
 * > Begin() - This method begins the game.
 */
class Dungeon
{
public:
	Player* _player;
	Room* _entryRoom;
	Position _spawnPoint;

	/**
	 * @brief Ths is the default constructor.
	*/
	Dungeon();

	/**
	 * @brief This is the overloaded constructor.
	 * @param player - the player.
	 * @param entryRoom - the entry room.
	 * @param spawnPoint - the spawn point.
	*/
	Dungeon(Player* player, Room* entryRoom, Position spawnPoint);

	/**
	 * @brief This is the copy constructor.
	 * @param dungeon - the dungeon to be copied.
	*/
	Dungeon(const Dungeon& dungeon);

	/**
	 * @brief This is the destructor.
	*/
	~Dungeon();

	/**
	 * @brief This method displays the details of the dungeon.
	*/
	void Display() const;

	/**
	 * @brief This method displays the details of the dungeon.
	 * @param room - the room to be traversed.
	*/
	void Traverse(Room* room);

	/**
	 * @brief This method recursively traverses the dungeon using DFS algorithm.
	 * @param room - the room to start with
	*/
	void DFSTraversal(Room* room);

	/**
	 * @brief This function implements the Task 3 in pSet4
	*/
	static void Task3();

	/**
	 * @brief This function implements the Task 4 in pSet4
	*/
	static void Task4();

	/**
	 * @brief This function implements the Task 5 in pSet4
	 * @param someString - the string to be converted to lower case.
	 * @return 
	*/
	static std::string ToLower(std::string& someString);

	/**
	 * @brief This method begins the game.
	*/
	static void Begin();
};