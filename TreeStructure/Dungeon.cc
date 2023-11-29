#include "Dungeon.h"
#include <algorithm>
#include <iostream>

Dungeon::Dungeon()
{
	_player = new Player();

	std::vector<std::string> roomNames = {
		"Entry Room", "Room 1", "Room 2", "Room 3",
		"Room 4", "Room 5", "Room 6", "Room 7"
	};
	// Level 0 Rooms
	_entryRoom = new Room(roomNames[0], 10);
	// Level 1 Rooms
	Room* room1 = new Room(roomNames[1], 20);
	Room* room2 = new Room(roomNames[2], 22);
	// Level 2 Rooms
	Room* room3 = new Room(roomNames[3], 30);
	Room* room4 = new Room(roomNames[4], 31);
	Room* room5 = new Room(roomNames[5], 32);
	Room* room6 = new Room(roomNames[6], 33);
	_entryRoom->SetNextRoomOne(room1);
	_entryRoom->SetNextRoomTwo(room2);
	// room1
	room1->SetPrevRoom(_entryRoom);
	room1->SetNextRoomOne(room3);
	room1->SetNextRoomTwo(room4);
	// room2
	room2->SetPrevRoom(_entryRoom);
	room2->SetNextRoomOne(room5);
	room2->SetNextRoomTwo(room6);
	// room3
	room3->SetPrevRoom(room1);
	// room4
	room4->SetPrevRoom(room1);
	// room5
	room5->SetPrevRoom(room2);
	// room6
	room6->SetPrevRoom(room2);

	_spawnPoint = { 0, 0 };
}

Dungeon::Dungeon(Player* player, Room* entryRoom, Position spawnPoint)
{
	_player = player;

	std::vector<std::string> roomNames = {
		"Entry Room", "Room 1", "Room 2", "Room 3",
		"Room 4", "Room 5", "Room 6", "Room 7"
	};
	// Level 0 Rooms
	_entryRoom = entryRoom;
	// Level 1 Rooms
	Room* room1 = new Room(roomNames[1], 20);
	Room* room2 = new Room(roomNames[2], 22);
	// Level 2 Rooms
	Room* room3 = new Room(roomNames[3], 30);
	Room* room4 = new Room(roomNames[4], 31);
	Room* room5 = new Room(roomNames[5], 32);
	Room* room6 = new Room(roomNames[6], 33);
	_entryRoom->SetNextRoomOne(room1);
	_entryRoom->SetNextRoomTwo(room2);
	// room1
	room1->SetPrevRoom(_entryRoom);
	room1->SetNextRoomOne(room3);
	room1->SetNextRoomTwo(room4);
	// room2 
	room2->SetNextRoomOne(room5);
	room2->SetNextRoomTwo(room6);
	// room3
	room3->SetPrevRoom(room1);
	// room4
	room4->SetPrevRoom(room1);
	// room5
	room5->SetPrevRoom(room2);
	// room6
	room6->SetPrevRoom(room2);


	_spawnPoint = spawnPoint;
}

Dungeon::Dungeon(const Dungeon& dungeon)
{
	_player = dungeon._player;
	_entryRoom = dungeon._entryRoom;
	_spawnPoint = dungeon._spawnPoint;
}

Dungeon::~Dungeon()
{
	delete _player;
	delete _entryRoom;
	_spawnPoint = { 0, 0 };
}

void Dungeon::Display() const
{
	std::cout << "Dungeon: " << std::endl;
	std::cout << "Player: " << _player->GetName() << std::endl;
	std::cout << "Entry Room: " << _entryRoom->GetName() << std::endl;
	std::cout << "Spawn Point: (" << _spawnPoint.x << ", " << _spawnPoint.y << ")" << std::endl;
}

void Dungeon::DFSTraversal(Room* room)
{
	if (room == Room::Sentinel)
	{
		return;
	}


	std::cout << room->GetName() << std::endl;
	DFSTraversal(room->GetNextRoomOne());
	DFSTraversal(room->GetNextRoomTwo());
}

void Dungeon::Traverse(Room* room)
{
	while(true)
	{
		// room->WelcomeMessage();
		std::cout << "You are in " << room->GetName() << std::endl;
		std::cout << "You have the following options: " << std::endl;
		std::cout << "1. Go to " << (
			(room->GetNextRoomOne() != Room::Sentinel) 
			? room->GetNextRoomOne()->GetName()
			: "None (This room is an end point. You'll need to go back)") << std::endl;
		std::cout << "2. Go to " << (
			(room->GetNextRoomTwo() != Room::Sentinel) 
			? room->GetNextRoomTwo()->GetName()
			: "None (This room is an end point. You'll need to go back)") << std::endl;
		std::cout << "3. Go back to " << (
			(room->GetPrevRoom()!= Room::Sentinel) 
			? room->GetPrevRoom()->GetName()
			: "None (This is the entry Room)") << std::endl;
		std::cout << "4. Quit" << std::endl;
		std::cout << "Enter a command: " << std::endl;
		std::string response;
		getline(std::cin, response);

		if (response == "1")
		{
			if (room->GetNextRoomOne() == Room::Sentinel)
			{
				std::cout << "No doors out of this room. You might need to go back. End of traversal" << std::endl;
				
			}
			else
			{
				room = room->GetNextRoomOne();
			}
		}
		else if (response == "2")
		{
			if (room->GetNextRoomTwo() == Room::Sentinel)
			{
				std::cout << "No doors out of this room. You might need to go back. End of traversal" << std::endl;

			}
			else
			{
				room = room->GetNextRoomTwo();
			}
		}
		else if (response == "3")
		{
			room = room->GetPrevRoom();
		}
		else if (response == "4")
		{
			std::cout << "Quitting game..." << std::endl;
			break;
		}
		else
		{
			std::cout << "Invalid command" << std::endl;
		}
	}
}

void Dungeon::Task3()
{
	auto* dungeon = new Dungeon();

	std::cout << "===============================================" << std::endl;
	std::cout << "============    TASK 3 [START]   ==============" << std::endl;
	std::cout << "===============================================" << std::endl;
	std::cout << "You have the following rooms to traverse and explore" << std::endl;

	dungeon->DFSTraversal(dungeon->_entryRoom);

	std::cout << "We Start in the entry Room: " << std::endl;
	std::cout << std::endl;
	dungeon->_entryRoom->WelcomeMessage();
	dungeon->Traverse(dungeon->_entryRoom);
	std::cout << "============    TASK 3 [END]   ==============" << std::endl;
}

void Dungeon::Task4()
{
	auto* dungeon = new Dungeon();
	PlayerVisitor* playerVisitor = new PlayerVisitor();
	std::cout << "===============================================" << std::endl;
	std::cout << "============    TASK 4 [START]   ==============" << std::endl;
	std::cout << "===============================================" << std::endl;
	playerVisitor->VisitPlayer(dungeon->_player);
	std::cout << "============    TASK 4 [END]   ==============" << std::endl;
}

std::string Dungeon::ToLower(std::string& someString)
{
	std::string result = someString;
	std::transform(result.begin(), result.end(), result.begin(), ::tolower);
	return result;
}

void Dungeon::Begin()
{
	std::vector<std::string> commands = {
		"description", "help", "task3", "task4", "quit", "clear"
	};
	std::string response;

	std::cout << "=====================================================" << std::endl;
	std::cout << "======        WELCOME TO THE DUNGEON        =========" << std::endl;
	std::cout << "=====================================================" << std::endl;
	while (true)
	{
		std::cout << "How would you like to proceed? Please type 'help' to view commands" << std::endl;
		getline(std::cin, response);


		if (ToLower(response) == commands[0])
		{
			std::cout << "=====================================================" << std::endl;
			std::cout << "======          GAME    DESCRIPTION         =========" << std::endl;
			std::cout << "=====================================================" << std::endl;
			std::cout << "This is a simple game program where the player is meant to go through a set of rooms in the dungeon.\n"
				<< "The player's permission to go through a certain room is accessed through a set of conditions which determine\n"
				<< "whether or not the user can access the room. The player starts the game in the entry room and if the player is\n"
				<< "able to slay more than three monsters then they qualify for access both the left (nextRoomOne) and right node (nextRoomTwo)\n"
				<< "otherwise they can only access the room represented by the left node(nextRoomOne). This is the challenge on level one.\n";

			std::cout << "On Level Two the player has four challenges but may choose at least one to tackle.Each condition is link \n"
				<< "to permission to access specified room(see Figure 1) if the player manages to satisfy all four conditions then \n"
				<< "they can easily move around the whole dungeon freely with access to any room.The game is considered solved at this point." << std::endl;
			std::cout << "-----------------------------------------------------" << std::endl;
			std::cout << "-----------------------------------------------------" << std::endl;
		}
		else if (ToLower(response) == commands[1])
		{
			std::cout << "=====================================================" << std::endl;
			std::cout << "======          HELP PAGE [commands]        =========" << std::endl;
			std::cout << "=====================================================" << std::endl;
			std::cout << "\tdescription: \tShows you the description of the game" << std::endl;
			std::cout << "\thelp: \tOpens up this help page." << std::endl;
			std::cout << "\ttask3 \tRuns the implementation of Task 3" << std::endl;
			std::cout << "\ttask4 \tRuns the implementation of Task 4" << std::endl;
			std::cout << "\tquit: \tQuits the game" << std::endl;
			std::cout << "-----------------------------------------------------" << std::endl;
		}
		else if (ToLower(response) == commands[2])
		{
			Task3();
		}
		else if (ToLower(response) == commands[3])
		{
			Task4();
		}
		else if (ToLower(response) == commands[4])
		{
			std::cout << "Quitting game..." << std::endl;
			break;
		}
		else if (ToLower(response) == commands[5])
		{
			#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
				system("cls");
			#elif __APPLE__
							system("clear");
			#elif __linux__
							system("clear");
			#endif
		}
		else
		{
			std::cout << "Invalid command" << std::endl;
		}
	}

}
