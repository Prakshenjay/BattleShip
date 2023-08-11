#ifndef COMPUTER_HPP
#define COMPUTER_HPP

#include "Player.hpp"
#include <random>

class Computer : public Player
{
private :
        std::mt19937 rng;

public :
        Computer();
        void placeShips();
        void takeTurn(Player& opponent);
};

#endif