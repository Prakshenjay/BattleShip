#include <iostream>
#include <string>
#include <iomanip>
#include "Game.hpp"

void Game::setup()
{
    system("clear");
    
    std::string name;
    std::cout << "Enter Player's Name : ";
    std::cin >> name;
    player.giveName(name);
    
    std::cout << "Place your ships" << std::endl;
    player.placeShips();

    computer.giveName("Computer");
    
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
        system("clear");

        std::cout << "\n";
        for(int k = 0 ; k < 2 ; k++)
            {
                std::cout << "\t\t  ";
                for(int j = 0 ; j < 10 ; j++)
                {
                    std::cout << " " << j << " ";
                }
                std::cout << "\t\t";
            }
        std::cout << "\n";
        
        for(int k = 0 ; k < 2 ; k++)
        {
            std::cout << "\t\t  ";
            for(int j = 0 ; j < 10 ; j++)
            {
                std::cout << "---";
            }
            std::cout << "\t\t";
        }
        std::cout << "\n";

        for(int i = 0 ; i < 10 ; i++)
        {
            std::cout << "\t\t" << static_cast<char>('A' + i) << "|" ;
            for(int j = 0 ; j < 10 ; j++)
            {
                std::cout << " " << playerBoard.Grid[i][j] << " " ;
            }
            std::cout << "\t\t";
            
            std::cout << "\t\t" << static_cast<char>('A' + i) << "|" ;
            for(int j = 0 ; j < 10 ; j++)
            {
                std::cout << " " << computerBoard.Grid[i][j] << " " ;
            }
            std::cout << "\t\t";
            
            std::cout << "\n";
        }

        std::cout << "\n";
        std::cout << "\t\t" << std::setw(25) << std::left << player.getName() + "'s Board";
        std::cout << "\t\t\t\t\t" << "Computer's Board";
        
        //--------------------------------------------------------------------------------//
        //--------------------------------------------------------------------------------//
        
        std::cout << "\n" << currentPlayer->getName() << "'s Turn:\n";

        bool turnOver = currentPlayer->takeTurn();

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