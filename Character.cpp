#include "Character.h"

///////////   CONSTRUCTORS ////////////////////////////////////
Character::Character() {
	name_ = ""; 
}

Character::Character(std::string name) {
	name_ = name; 
}

Character::Character(std::string name, std::string description) {
	name_ = name; 
	description_ = description; 
}

/////////////   GETTERS /////////////////////////////////
std::string Character::getName() {
	return name_;
}
std::string Character::getDescription() {
	return description_;
}

std::vector<std::string> Character::getSpeakingLine() {
	return speakingLine_; 
}
std::vector<std::string> Character::getKeywords() {
	return keyWords_; 
}
std::vector<std::string> Character::getPromptedLine() {
	return promptedLines_; 
}
std::vector<std::string> Character::getPronoun() {
	return pronouns_; 
}



///////////   SETTERS /////////////////////////////////////////////
void Character::setName(std::string name) {
	name_ = name;
}
void Character::setDescription(std::string description) {
	description_ = description;
}

void Character::setSpeakingLine(const std::vector<std::string> speakingLine) {
	speakingLine_ = speakingLine; 
}

void Character::setKeyWords(const std::vector<std::string> keyWords) {
	keyWords_ = keyWords; 
}

void Character::setPromptedLine(const std::vector<std::string> promptedLines) {
	promptedLines_ = promptedLines; 
}

void Character::setPronoun(const std::vector<std::string> pronoun) {
	pronouns_ = pronoun; 
}