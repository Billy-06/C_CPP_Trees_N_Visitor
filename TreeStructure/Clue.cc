#include "Clue.h"
#include <iostream>

Clue::Clue()
{
	_clueNumber = 0;
	_clueMessage = "Default Clue Message";
	_timesShown = 0;
	_maxReads = 3;
	_roomNumber = 000;
}

Clue::Clue(int clueNumber, std::string& clueMessage, int maxReads, int roomNumber)
{
	_clueNumber = clueNumber;
	_clueMessage = clueMessage;
	_timesShown = 0;
	_maxReads = maxReads;
	_roomNumber = roomNumber;
}

Clue::Clue(const Clue& clue)
{
	_clueNumber = clue._clueNumber;
	_clueMessage = clue._clueMessage;
	_timesShown = clue._timesShown;
	_maxReads = clue._maxReads;
	_roomNumber = clue._roomNumber;
}

Clue::~Clue()
{
	_clueNumber = 0;
	_clueMessage = "";
	_timesShown = 0;
	_maxReads = 0;
	_roomNumber = 0;
}

int Clue::GetClueNumber() const
{
	return _clueNumber;
}

void Clue::SetClueNumber(int clueNumber)
{
	_clueNumber = clueNumber;
}

std::string& Clue::GetClueMessage()
{
	return _clueMessage;
}

void Clue::SetClueMessage(std::string& clueMessage)
{
	_clueMessage = clueMessage;
}

int Clue::GetTimesShown() const
{
	return _timesShown;
}

void Clue::SetTimesShown(int timesShown)
{
	_timesShown = timesShown;
}

int Clue::GetMaxReads() const
{
	return _maxReads;
}

int Clue::GetRoomNumber() const
{
	return _roomNumber;
}

void Clue::SetRoomNumber(int roomNumber)
{
	_roomNumber = roomNumber;
}

void Clue::Display() const
{
	std::cout << "======================================" << std::endl;
	std::cout << "=  CLUE: " << _clueNumber << "  =====  Room Number: "<< _roomNumber << " ===" << std::endl;
	std::cout << "======================================" << std::endl;
	std::cout << "======================================" << std::endl;
	std::cout << _clueMessage << std::endl;
	std::cout << "--------------------------------------" << std::endl;
	std::cout << "Number of Times shown: " << _timesShown << std::endl;
	std::cout << "Maximum Reads Set to : " << _maxReads << std::endl;
	std::cout << "======================================" << std::endl;
}