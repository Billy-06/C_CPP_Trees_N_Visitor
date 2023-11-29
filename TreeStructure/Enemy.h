#pragma once
#include "Character.h"
/**
 * @file Enemy.h
 * @author Billy Ndegwah Micah
 *
 * Description: This file contains the declaration of the Enemy class which extends the
 * Character class.
 *
 * Properties:
 * ------------
 * > _venomReserve: int - This is the amount of venom the enemy has.
 *
 * Methods:
 * --------
 * > Enemy() - Default constructor.
 * > Enemy(string name, int venomReserve) - Parameterized constructor.
 * > Enemy(const Enemy& enemy) - Copy constructor.
 * > Enemy(const Character& character, int venomReserve) - Copy constructor.
 * > ~Enemy() - Destructor.
 * > Getters and setters for the _venomReserve property.
 * > ShowStats() - This method displays the enemy's stats.
 */
class Enemy : public Character
{
private:
	int _venomReserve;

public:
	/**
	 * @brief This is the default constructor.
	*/
	Enemy();

	/**
	 * @brief This is the overloaded constructor.
	 * @param name - the name of the enemy.
	 * @param venomReserve - the amount of venom the enemy has.
	*/
	Enemy(std::string& name, int venomReserve);

	/**
	 * @brief This is a copy constructor that takes an Enemy type.
	 * @param enemy - the enemy to be copied.
	*/
	Enemy(const Enemy& enemy);

	/**
	 * @brief The is a copy constructor that takes a Character type.
	 * @param character - the character to be copied.
	 * @param venomReserve - the amount of venom the enemy has.
	*/
	Enemy(const Character& character, int venomReserve);

	/**
	 * @brief This is the destructor.
	*/
	~Enemy() override;

	/**
	 * @brief Getter for the _venomReserve property.
	 * @return an integer representing the amount of venom the enemy has.
	*/
	int GetVenomReserve() const;

	/**
	 * @brief Setter for the _venomReserve property.
	 * @param venomReserve - the amount of venom the enemy has.
	*/
	void SetVenomReserve(int venomReserve);

	/**
	 * @brief This method displays the enemy's stats.
	*/
	void ShowStats() const override;


};