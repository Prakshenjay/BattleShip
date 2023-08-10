#ifndef COMPUTER_HPP
#define COMPUTER_HPP

#include "Player.hpp"

class Computer : public Player
{
private :

public :
        Board computerBoard;
        void placeShips();
};

#endif