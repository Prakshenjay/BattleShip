
#include "Game.h"
#include <iostream>

Game::Game()
{
    //
}

void Game::setup()
{
    std::cout << "Computer is placing its ships.\n";
    computer.placeShips();

    std::cout << "Game is set up and ready to play!\n";
}

void Game::play()
{
    Player* currentPlayer = &player;
    Player* opponent = &computer;

    while (true)
    {
        system("cls");

        for()
        std::cout << "\n" << currentPlayer->getName() << "'s Turn:\n";

        bool turnOver = currentPlayer->takeTurn(*opponent);

        if (opponent->hasLost())
        {
            std::cout << "\n" << currentPlayer->getName() << " wins!\n";
            break;
        }

        if (turnOver)
        {
            std::swap(currentPlayer, opponent);
        }
    }
}
