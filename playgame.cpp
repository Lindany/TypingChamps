#include "playgame.h"
#include "player.h"
#include <stdlib.h>
#include <iostream>
#include <string>
//#include <vector>
using namespace std;

/*create a constructor that instantiates
 *a player object*/
PlayGame::PlayGame(){
    player = new Player();
    player->setName();
    cout<<"Thanks For Joining Spelling Bee,Learn And Have Fun!!!"<<player->getName()<<endl;
}

/*create a getter method that returns
 *a player object*/
Player PlayGame::getPlayer(){
    return *player;
}

/*create a method that generates
 *a random word from an array of words*/
string PlayGame::generateWord(){
    string arry [5] = {"Apple","Orange","Banana","Pear","Grapes"};
    int index = rand()%5;
    string tempWord = arry[index];
    return tempWord;
}

/*create a method that checks if word typed by Player matches given word*/
void PlayGame::checkWord(){
        string wd = generateWord();
        player->addUsedWords(wd);
        cout <<"Write this word : "<<wd<<endl;
        string p = getPlayer().writeWord();

        if(p == wd){
            getPlayer().updateScore();
            getPlayer().updateCorrectWords();
        }

        else{
            getPlayer().updateIncorrectWords();
        }
}

/*create a method that controls game play*/
void PlayGame::play(){
    string p;

    if(getPlayer().getUsedWords().size() > 0){

        for(int j=0;j<getPlayer().getUsedWords().size();j++){
            if(wd == getPlayer().getUsedWords()[j]){
                break;
            }
        }
        checkWord();
    }

    else{
            checkWord();
    }
}

/*create a method that sets and prints
 *player details like name,score,etc*/
void PlayGame::printResults(){
    cout<<"\nCurrent Level : "<<getPlayer().getLevel()<<endl<<"Current Score : "<<getPlayer().getScore()
    <<" points"<<endl<<"Current Correct Words : "<<getPlayer().getCorrectWords()<<endl<<"Current Incorrect Words : "
    <<getPlayer().getIncorrectWords()<<endl<<"Overall Time For This Level : "<<getPlayer().getTimeTook()<<" seconds\n";
}

