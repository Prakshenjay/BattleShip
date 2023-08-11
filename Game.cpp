#include <iostream>
#include <string>
#include <iomanip>
#include "Game.hpp"

void delayAnimation()
{
    std::cout << "Loading...";
    
    for (int i = 0; i < 5; ++i)
    {
        std::cout << ".";
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    
    std::cout << "\n\nLoading complete!\n\n";
}

void Game::setup()
{
    system("clear");
    
    std::string name;
    std::cout << "\tEnter Player's Name : ";
    std::cin >> name;
    player.giveName(name);
    
    std::cout << "\tPlace your ships" << std::endl;
    player.placeShips();

    computer.giveName("Computer");
    
    system("clear");
    
    std::cout << "\tComputer is placing its ships.\n";
    computer.placeShips();
    
    delayAnimation();

    std::cout << "\tGame is set up and ready to play!\n";
    
    delayAnimation();
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
                std::cout << " " << player.Grid[i][j] << " " ;
            }
            std::cout << "\t\t";
            
            std::cout << "\t\t" << static_cast<char>('A' + i) << "|" ;
            for(int j = 0 ; j < 10 ; j++)
            {
                std::cout << " " ; if(computer.Grid[i][j] != 'S') std::cout << computer.Grid[i][j] ; else std::cout << '.' ; std::cout << " " ;
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
        
        currentPlayer->takeTurn(*opponent);

        if (opponent->hasLost())
        {
            std::cout << "\n" << currentPlayer->getName() << " wins!\n";
            break;
        }

        std::swap(currentPlayer, opponent);
    }
}