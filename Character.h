#pragma once
#include <string>
#include <vector>


class Character
{
public: 
	// constructor 
	Character(); 
	Character(std::string name); 
	Character(std::string name, std::string description); 
	//getters
	
	//getters 
	std::string getName();
	std::string getDescription();
	std::vector<std::string>getSpeakingLine();
	std::vector<std::string>getKeywords();
	std::vector<std::string>getPromptedLine(); 
	std::vector<std::string>getPronoun(); 

	//setters 
	void setName(std::string name);
	void setDescription(std::string description);
	void setSpeakingLine(const std::vector<std::string> speakingLine);
	void setKeyWords(const std::vector<std::string> keyWords);
	void setPromptedLine(const std::vector<std::string> promptedLines); 
	void setPronoun(const std::vector<std::string> pronoun); 

private:

	std::string name_;
	std::string description_;
	std::vector<std::string>speakingLine_;
	std::vector<std::string>keyWords_; 
	std::vector<std::string>promptedLines_; 
	std::vector<std::string>pronouns_; 
};

