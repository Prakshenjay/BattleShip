#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <chrono>
#include <thread>
#include "Player.hpp"
#include "Computer.hpp"

class Game
{
private :
        Player player;
        Computer computer;

public :
        void setup();
        void printSetup();
        void play();
};

#endif