#pragma once
#include <string>
#include <map>

#include "Character.h"

// constructors, maps, getters, setters, variables

class Room
{
public:
	// constructor 
	Room();
	Room(std::string name);
	Room(std::string name, std::string description); 

	// maps 
	std::map<std::string, Room*> linked_rooms = {}; 
	std::map<std::string, Character*> linked_Characters = {}; 

	//getters (accessors)
	std::string getName(); 
	std::string getDescription(); 

	//setters (mutators)
	void setName(std::string name);
	void setDescription(std::string description); 

private:

	// variables 
	std::string name_;
	std::string description_; 


};

