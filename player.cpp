//#include <iostream>
#include <string>
//#include <vector>
#include "Player.h"
using namespace std;

/*create a constructor that initializes
 *Player class fields*/
Player::Player(){
    score = 0;
    level = 1;
    correctWords = 0;
    incorrectWords = 0;
    timeTook = 0;
}

/*create a destructor for
 * player object*/
Player::~Player(){
//    delete score;
//    delete level;
//    delete timeTook;
//    delete correctWords;
//    delete incorrectWords;
}

/*create a method that sets
 *a name for a player*/
void Player::setName(){
    cout <<"Enter Name Here : ";
    cin >> name;
}

/*create a getter method that returns
 *a player name*/
string Player::getName(){
    return name;
}

/*create a getter method that returns
 *a player score*/
int Player::getScore(){
    return score;
}
//
///*create a getter method that returns
// *a player level*/
int Player::getLevel(){
   return level;
}

/*create a method that adds
*used words into a vector*/
void Player::addUsedWords(string w){
    usedWords.push_back(w);
}

/*create a getter method that returns
 * a vector of used words*/
vector<string> Player::getUsedWords(){
    return usedWords;
}

/*create a getter method that returns
 *number of correct words*/
int Player::getCorrectWords(){
    return correctWords;
}

/*create a getter method that returns
 *number incorrect words*/
int Player::getIncorrectWords(){
   return incorrectWords;
}

/*create a method that returns
 *a word entered by player*/
string Player::writeWord(){
    string wrd;
    cout<<"Enter word : ";
    cin >> wrd;
    return wrd;
}

/*create a getter method that returns
 *the time took by player to type words*/
int Player::getTimeTook(){
    return timeTook;
}

/*create a method that updates Player level*/
void Player::updateLevel(){level++;}


/*create a method that updates Player score*/
void Player::updateScore(){score+=10;}


/*create a method that updates Player number of correct words*/
void Player::updateCorrectWords(){correctWords++;}


/*create a method that updates Player number of incorrect words*/
void Player::updateIncorrectWords(){incorrectWords++;}


/*create a method that updates Player time took for each word entered*/
void Player::updateTimeTook(){;}
