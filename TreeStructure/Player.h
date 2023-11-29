#pragma once
#include "Character.h"
#include <string>
class PlayerVisitor;
/**
 * @file Player.h
 * @author Billy Ndegwah Micah
 *
 * Descritpion: This file contains the declaration of the Player class which extends the
 * Player class which extends the Character class.
 *
 * Properties:
 * -----------
 * > _score: int - This is the score of the player.
 * > _monstersSlain: int - This is the number of monsters slain by the player.
 *
 * Methods:
 * --------
 * > Player() - Default constructor.
 * > Player(string name, int score, int monstersSlain) - Parameterized constructor.
 * > Player(const Player& player) - Copy constructor.
 * > Player(const Character& character, int score, int monstersSlain) - Copy constructor.
 * > ~Player() - Destructor.
 * > Getters and setters for the _score and _monstersSlain properties.
 * > ShowStats() - This method displays the player's stats.
 */
class Player : public Character
{
private:
	int _score;
	int _monstersSlain;

public:
	/**
	 * @brief This is the default constructor.
	*/
	Player();

	/**
	 * @brief This is the overloaded constructor.
	 * @param name - the name of the player.
	*/
	Player(std::string& name);

	/**
	 * @brief This is a copy constructor that takes a Player type.
	 * @param player - the player to be copied.
	*/
	Player(const Player& player);

	/**
	 * @brief This is a copy constructor that takes a Character type.
	 * @param character - the character to be copied.
	*/
	Player(const Character& character);

	/**
	 * @brief This is the destructor.
	*/
	~Player() override;

	/**
	 * @brief Getter for the score.
	 * @return an integer representing the score.
	*/
	int GetScore() const;

	/**
	 * @brief Setter for the score.
	 * @param score - the score.
	*/
	void SetScore(int score);

	/**
	 * @brief Getter for the monsters slain.
	 * @return - an integer representing the number of monsters slain.
	*/
	int GetMonstersSlain() const;

	/**
	 * @brief Setter for the monsters slain.
	 * @param monstersSlain - the number of monsters slain.
	*/
	void SetMonstersSlain(int monstersSlain);

	/**
	 * @brief This method displays the player's stats.
	*/
	void ShowStats() const override;

	void AcceptVisitor(PlayerVisitor* visitor);
};


/**
 * @file Player.h
 * @author Billy Ndegwah Micah
 *
 * Description: Visitor class for the player
 *
 * Methods:
 * --------
 * > VisitPlayer(Player* player) : void - visits the player
 */
class PlayerVisitor
{
public:
	void VisitPlayer(Player* player);
};