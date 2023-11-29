#pragma once
#include <string>
/**
 * @file Item.h
 * @author Billy Ndegwah Micah
 *
 * Description: This header files contains the declaration of the Item class.
 *
 * Properties:
 * ----------
 * > _name: string - This is the name of the item.
 * > _level: int - This is the level of the item in the dungeon tree where the Item is found.
 * > _accessPoints: int - This is the access points the player gets from picking up the item.
 *
 * Methods:
 * --------
 * > Getters and setters for the properties.
 * > Item() - This is the default constructor.
 * > Item(name: string, level: int, accessPoints: int) - This is the overloaded constructor.
 * > Item(const Item& item) - This is the copy constructor.
 * > ~Item() - This is the destructor.
 * > Display() - This method displays the item.
 */
class Item
{
private:
	std::string _name;
	int _level;
	int _accessPoints;

public:
	/**
	 * @brief This is the default constructor.
	*/
	Item();

	/**
	 * @brief This is the overloaded constructor.
	 * @param name - the name of the item.
	 * @param level - the level of the item.
	 * @param accessPoints - the access points the player gets from picking up the item.
	*/
	Item(std::string& name, int level, int accessPoints);

	/**
	 * @brief Ths is the copy constructor.
	 * @param item - the item to be copied.
	*/
	Item(const Item& item);

	/**
	 * @brief This is the destructor.
	*/
	~Item();

	/**
	 * @brief Getter for the _name property.
	 * @return a string representing the name of the item.
	*/
	std::string& GetName();

	/**
	 * @brief Setter for the _name property.
	 * @param name - the name of the item.
	*/
	void SetName(std::string& name);

	/**
	 * @brief Getter for the _level property.
	 * @return a string representing the level of the item.
	*/
	int GetLevel() const;

	/**
	 * @brief Setter for the _level property.
	 * @param level - the level of the item.
	*/
	void SetLevel(int level);

	/**
	 * @brief Getter for the _accessPoints property.
	 * @return an integer representing the access points the player gets from picking up the item.
	*/
	int GetAccessPoints() const;

	/**
	 * @brief Setter for the _accessPoints property.
	 * @param accessPoints - the access points the player gets from picking up the item.
	*/
	void SetAccessPoints(int accessPoints);

	/**
	 * @brief This method displays the details of the item.
	*/
	void Display() const;
};