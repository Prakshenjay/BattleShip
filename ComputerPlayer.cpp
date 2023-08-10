
#include <iostream>
#include "ComputerPlayer.h"

ComputerPlayer::ComputerPlayer()
{
    std::random_device rd;
    rng = std::mt19937(rd()); // Initialize the random number generator
}

bool ComputerPlayer::takeTurn(Player& opponent)
{
    
}
