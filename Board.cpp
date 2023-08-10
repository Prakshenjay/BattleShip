#include <iostream>
#include "Board.hpp"

Board::Board()
{
    for(int i = 0 ; i < BOARD_SIZE ; i++)
    {
        for(int j = 0 ; j < BOARD_SIZE ; j++)
        {
            Grid[i][j] = '.';
        }
    }
}

void Board::Display()
{
    std::cout << "\n";
    std::cout << "\t\t  ";
    for(int j = 0 ; j < BOARD_SIZE ; j++)
    {
        std::cout << " " << j << " ";
    }
    std::cout << "\n";
        
    std::cout << "\t\t  ";
    for(int j = 0 ; j < BOARD_SIZE ; j++)
    {
        std::cout << "---";
    }
    std::cout << "\n";

    for(int i = 0 ; i < BOARD_SIZE ; i++)
    {
        std::cout << "\t\t" << static_cast<char>('A' + i) << "|" ;
        for(int j = 0 ; j < BOARD_SIZE ; j++)
        {
            std::cout << " " << Grid[i][j] << " " ;
        }
        std::cout << "\n";
    }
}

bool Board::isValidPosition(int x, int y)
{
    return x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE;
}

bool Board::placeShip(int x, int y, int length, char direction)
{
    return true;
}

