
#ifndef COMPUTER_PLAYER_H
#define COMPUTER_PLAYER_H

#include "Player.h"
#include <random>

class ComputerPlayer : public Player
{
private:
    std::mt19937 rng; // Random number generator

public:
    ComputerPlayer();
    bool takeTurn(Player& opponent);
};

#endif // COMPUTER_PLAYER_H
