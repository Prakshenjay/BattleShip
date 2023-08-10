#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include "Player.hpp"
#include "Computer.hpp"
#include "Board.hpp"

class Game
{
private :
        Player player;
        Computer computer;

public :
        void setup();
        void play();
};

#endif