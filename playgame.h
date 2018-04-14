#ifndef PLAYGAME_H
#define PLAYGAME_H
#include "Player.h"
#include <string>

using namespace std;

class PlayGame{

    public:
        /** Default constructor */
        PlayGame();
        void checkWord();
        void play();
        Player getPlayer();
        void printResults();
        string getTempWord();
        int getIndex();
        string generateWord();

    private:
        Player* player;
        string wd;
};

#endif // PLAYGAME_H
