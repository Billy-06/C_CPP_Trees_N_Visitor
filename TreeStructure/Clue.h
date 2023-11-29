#pragma once
#include <string>
/**
 * @file Clue.h
 * @author Billy Ndegwah Micah
 *
 * Description: This header files contains the declaration of the Clue class.
 *
 * Properties:
 * -----------
 * > _clueNumber: int - This is the clue number.
 * > _clueMessage: string - This is the clue message.
 * > _timesShown: int - This is the number of times the clue has been shown.
 * > _maxReads: int (read only) - This is the maximum number of times the clue can be read.
 * > _roomNumber: int - This is the room number in which the clue can be read.
 *
 * Methods:
 * > Getters and setters for the properties.
 * > Clue() - This is the default constructor.
 * > Clue(clueNumber: int, clueMessage: string, maxReads: int, roomNumber: int) - This is the overloaded constructor.
 * > Clue(const Clue& clue) - This is the copy constructor.
 * > ~Clue() - This is the destructor.
 * > Display() - This method displays the clue.
 */
class Clue
{
private:
	int _clueNumber;
	std::string _clueMessage;
	int _timesShown;
	int _maxReads;
	int _roomNumber;

public:
	/**
	 * @brief This is the default constructor.
	*/
	Clue();

	/**
	 * @brief This is the overloaded constructor.
	 * @param clueNumber - hte clue number.
	 * @param clueMessage - the clue message.
	 * @param maxReads - the maximum number of times the clue can be read.
	 * @param roomNumber - the room number in which the clue can be read.
	*/
	Clue(int clueNumber, std::string& clueMessage, int maxReads, int roomNumber);

	/**
	 * @brief This is the copy constructor.
	 * @param clue - the clue to be copied 
	*/
	Clue(const Clue& clue);

	/**
	 * @brief This is the destructor.
	*/
	~Clue();

	/**
	 * @brief Getter for the clue number.
	 * @return an integer representing the clue number.
	*/
	int GetClueNumber() const;

	/**
	 * @brief Setter for the clue number.
	 * @param clueNumber - the desired clue number.
	*/
	void SetClueNumber(int clueNumber);

	/**
	 * @brief Getter for the clue message.
	 * @return a string representing the clue message.
	*/
	std::string& GetClueMessage();

	/**
	 * @brief Setter for the clue message.
	 * @param clueMessage - the desired clue message.
	*/
	void SetClueMessage(std::string& clueMessage);

	/**
	 * @brief Getter for the number of times the clue has been shown.
	 * @return an integer representing the number of times the clue has been shown.
	*/
	int GetTimesShown() const;

	/**
	 * @brief Setter for the number of times the clue has been shown.
	 * @param timesShown - the desired number of times the clue has been shown.
	*/
	void SetTimesShown(int timesShown);

	/**
	 * @brief (Read only) Getter for the maximum number of times the clue can be read.
	 * @return an integer representing the maximum number of times the clue can be read.
	*/
	int GetMaxReads() const;

	/**
	 * @brief Getter for the room number in which the clue can be read.
	 * @return an integer representing the room number in which the clue can be read.
	*/
	int GetRoomNumber() const;

	/**
	 * @brief Setter for the room number in which the clue can be read.
	 * @param roomNumber - the desired room number in which the clue can be read.
	*/
	void SetRoomNumber(int roomNumber);

	/**
	 * @brief This function displays the clue.
	*/
	void Display() const;
};
