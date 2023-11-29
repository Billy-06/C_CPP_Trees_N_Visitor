#include "Item.h"
#include <iostream>

Item::Item()
{
	_name = "Default Item Name";
	_level = 0;
	_accessPoints = 45;
}

Item::Item(std::string& name, int level, int accessPoints)
{
	_name = name;
	_level = level;
	_accessPoints = accessPoints;
}

Item::Item(const Item& item)
{
	_name = item._name;
	_level = item._level;
	_accessPoints = item._accessPoints;
}

Item::~Item()
{
	_name = "";
	_level = 0;
	_accessPoints = 0;
}

std::string& Item::GetName()
{
	return _name;
}

void Item::SetName(std::string& name)
{
	_name = name;
}

int Item::GetLevel() const
{
	return _level;
}

void Item::SetLevel(int level)
{
	_level = level;
}

int Item::GetAccessPoints() const
{
	return _accessPoints;
}

void Item::SetAccessPoints(int accessPoints)
{
	_accessPoints = accessPoints;
}

void Item::Display() const
{
	std::cout << "\t==================================" << std::endl;
	std::cout << "\t> " << _name << " Details" << std::endl;
	std::cout << "\t==================================" << std::endl;
	std::cout << "\tItem Name: " << _name << std::endl;
	std::cout << "\tItem Level: " << _level << std::endl;
	std::cout << "\tItem Access Points: " << _accessPoints << std::endl;
	std::cout << "\t__________________________________" << std::endl;
	std::cout << std::endl;
}