#include "Room.h"

//constructor 
Room::Room::Room() {
	name_ = ""; 
}
Room::Room(std::string name) {
	name_ = name; 
}
Room::Room(std::string name, std::string description) {
	name_ = name;
	description_ = description; 
}
//getters 
std::string Room::getName() {
	return name_; 
}
std::string Room::getDescription() {
	return description_; 
}
//setters 
void Room::setName(std::string name) {
	name_ = name; 
}
void Room::setDescription(std::string description) {
	description_ = description; 
}