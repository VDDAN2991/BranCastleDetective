// BranCastleDetective.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Room.h"
#include "Character.h"

int main()
{
    std::cout << "GAME NAME: Catle Dracula Murder mistery\n";

    ///////////   Set up GAME OBJECTS    //////////////////////////////////////////////////// 



    // ROOMS: name, description 
    // CHARACTER:  name, pronoun, description, keywords, promted line, speaking line 

    // Set up LIST OF ROOMS (9 rooms)
    Room entranceWay;
    Room courtyard; 
    Room throneRoom; 
    Room library; 
    Room queenMariesApt; 
    Room observatory; 
    Room restaurant; 
    Room weaponRoom; 
    Room orientalRoom; 

    //Set up LIST OF CHARACTERS ( 5 characters)
    Character inspector; 
    Character princess;
    Character baroness; 
    Character worker; 
    Character madame; 

    // ************ START SET UP ROOMS ******************************************
     
    // Set up NAMES OF THE ROOMS 
    entranceWay.setName("The Grand Entrance");
    courtyard.setName("Castle Courtyard");
    throneRoom.setName("The Throne Room");
    library.setName("King Ferdinand's Library");
    queenMariesApt.setName("Queen Marie's Apartment");
    observatory.setName("The Prince Vlad's Observatory");
    restaurant.setName("Dracula's Restaurant");
    weaponRoom.setName("The weapon room 'King Carol the First' ");
    orientalRoom.setName("The Oriental Room");



    // Set up DESCRIPTION OF ROOMS 
    entranceWay.setDescription("The Grand Entrance");
    courtyard.setDescription("Castle Courtyard");
    throneRoom.setDescription("The Throne Room");
    library.setDescription("King Ferdinand's Library");
    queenMariesApt.setDescription("Queen Marie's Apartment");
    observatory.setDescription("The Prince Vlad's Observatory");
    restaurant.setDescription("Dracula's Restaurant");
    weaponRoom.setDescription("The weapon room 'King Carol the First' ");
    orientalRoom.setDescription("The Oriental Room");

    // ********** END SET UP ROOMS *********************************************
    

    // ************ START SET UP CHARACTERS  ******************************************
    //Set up CHARACTER NAME  
    inspector.setName("Inspector");
    princess.setName("Penelope");
    baroness.setName("Helena Van Arsdale");
    worker.setName("Andrzej");
    madame.setName("Madame Ionescu");

    //Set up CHARACTER PRONOUN 
    inspector.setPronoun("Inspector");
    princess.setPronoun("Penelope");
    baroness.setPronoun("Helena Van Arsdale");
    worker.setPronoun("Andrzej");
    madame.setPronoun("Madame Ionescu");
    
    //Set up CHARACTER DESCRIPTION 
    inspector.setDescription("Inspector");
    princess.setDescription("Penelope");
    baroness.setDescription("Helena Van Arsdale");
    worker.setDescription("Andrzej");
    madame.setDescription("Madame Ionescu");

    //Set up CHARACTER KEYWORDS 
    inspector.setKeyWords("Inspector");
    princess.setKeyWords("Penelope");
    baroness.setKeyWords("Helena Van Arsdale");
    worker.setKeyWords("Andrzej");
    madame.setKeyWords("Madame Ionescu");


    //Set up CHARACTER PROMPTED LINE
    inspector.setPromptedLine("Inspector");
    princess.setPromptedLine("Penelope");
    baroness.setPromptedLine("Helena Van Arsdale");
    worker.setPromptedLine("Andrzej");
    madame.setPromptedLine("Madame Ionescu");

    //Set up CHARACTER SPEAKING LINE 
    inspector.setSpeakingLine("Inspector");
    princess.setSpeakingLine("Penelope");
    baroness.setSpeakingLine("Helena Van Arsdale");
    worker.setSpeakingLine("Andrzej");
    madame.setSpeakingLine("Madame Ionescu");

    // ************ END SET UP CHARACTERS ******************************************

    // **************** START LINK THE ROOMS ******************************************* 
   
    // middle map 
    courtyard.linked_rooms["north"] = &throneRoom;
    courtyard.linked_rooms["east"] = &restaurant;
    courtyard.linked_rooms["south"] = &entranceWay;
    courtyard.linked_rooms["east"] = &queenMariesApt;

    // left side - middle 
    queenMariesApt.linked_rooms["east"] = &courtyard;
    queenMariesApt.linked_rooms["north"] = &library;
    queenMariesApt.linked_rooms["south"] = &observatory;
    
    // right side - middle 
    restaurant.linked_rooms["west"] = &courtyard;
    restaurant.linked_rooms["north"] = &weaponRoom;
    restaurant.linked_rooms["south"] = &orientalRoom;



    // rooms top map (left to right, soth)
    library.linked_rooms["south"] = &queenMariesApt;
    throneRoom.linked_rooms["south"] = &courtyard;
    weaponRoom.linked_rooms["south"] = &restaurant;

    // rooms bottom map (left to right, north) 
    observatory.linked_rooms["north"] = &queenMariesApt;
    entranceWay.linked_rooms["north"] = &courtyard;

    // ************ END LINK THE ROOMS  *******************************************



    // ************* START LINK THE CHARACTERS TO THE ROOMS **************************
    
    entranceWay.linked_Characters["princess"] = &princess;
    entranceWay.linked_Characters["madame"] = &madame;

    restaurant.linked_Characters["worker"] = &worker;

    queenMariesApt.linked_Characters["baroness"] = &baroness;

    // ************* END  LINK THE CHARACTERS TO THE ROOMS **************************
    // 
    // 
    // 
    // 
    // ************* START LINK THE CLUES TO THE ROOMS *************************************
     // ************* END LINK THE CLUES TO THE ROOMS *************************************

    Room* currentRoom = &entranceWay; 
    Character* currentChar = &inspector; 

    std::string command; 
    bool changeRoom = true; 

    do {
        // if you change rooms you get a description, this only runs the first time you enter a room 
        if(changeRoom == true){

            // giving you a description of the room 
            std::cout << "Looking around " << currentRoom->getName() << " you see " << currentRoom->getDescription() << std::endl;

            changeRoom = false;
            //telling you what characters are in the room 
            if (!currentRoom->linked_Characters.empty()) {
                // Get an iterator pointing to the first element in the map 
                std::map<std::string, Character* >::iterator it = currentRoom->linked_Characters.begin();
                // Iterate through the map and print the elements 
                std::cout << "in this room you see:\n";
                while (it != currentRoom->linked_Characters.end()) {
                    std::cout << it->first << std::endl;
                    ++it;
                }
            }
        
        }
        /*
        if          /currentRoom -> linked_Characters.find(command) != currentRoom -> linked_Characters.end()
        else if     /currentRoom->linked_rooms.find(command) != currentRoom->linked_rooms.end()
        else if     /currentChar != &inspector
        else if     /command == "map" 
        else 
        */

        std::cout << ">> "; 
        std::cin >> command; 
        if (currentRoom -> linked_Characters.find(command) != currentRoom -> linked_Characters.end() ) {
            currentChar = currentRoom->linked_Characters[command];
            std::cout << "As you approach  " << currentChar->getPronoun()[1] << " you see " << currentChar->getDescription() << "\n\n";

            if (!currentChar->getSpeakingLine().empty()) {
                std::cout << currentChar->getSpeakingLine()[0];
            }
 
        }// secific key word used ?
        else if (currentChar != &inspector) {
            for (int i = 0; i < currentChar->getKeywords().size(); i++) {
                if (command == currentChar->getKeywords()[i]) {
                    std::cout << currentChar->getPromptedLine()[i] << "\n";
                }
            }
        }
        else if (currentRoom->linked_rooms.find(command) != currentRoom->linked_rooms.end()) {
        
            currentRoom = currentRoom->linked_rooms[command];
            currentChar = &inspector; 
            changeRoom = true; 
        }
        else if (command == "map") {
            std::cout << " end map \n"; 
        }
        else {
            std::cout << " You can't do that\n";
        }
    } while (command == "exit");



    
}


