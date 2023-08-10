
#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "ComputerPlayer.h"
#include "Board.h>"

class Game
{
private:
    Player player;
    ComputerPlayer computer;

public:
    void setup();
    void play();
};

#endif // GAME_H

