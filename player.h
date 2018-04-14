#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Player
{
    private:
        string name;
        int score,level,correctWords,incorrectWords,timeTook;
        vector<string> usedWords;

    public:
        Player();
        int getScore();
        void setName();
        string writeWord();
        string getName();
        vector<string> getUsedWords();
        void addUsedWords(string w);
        int getCorrectWords();
        int getLevel();
        int getIncorrectWords();
        int getTimeTook();
        void updateLevel();
        void updateScore();
        void updateCorrectWords();
        void updateIncorrectWords();
        void updateTimeTook();
        ~Player();

};

#endif // PLAYER_H
