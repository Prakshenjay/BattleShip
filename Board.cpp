
#include "Board.h"
#include <iostream>
#include <iomanip>

Board::Board()
{
    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        for (int j = 0; j < BOARD_SIZE; ++j)
        {
            grid[i][j] = ' ';
        }
    }
}

void Board::display(bool showShips)
{
    std::cout << "  ";
    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        std::cout << static_cast<char>('A' + i) << " ";
    }
    std::cout << "\n";

    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        std::cout << std::setw(2) << i + 1;
        for (int j = 0; j < BOARD_SIZE; ++j)
        {
            if (showShips || grid[i][j] != 'S')
            {
                std::cout << " " << grid[i][j];
            }
            else
            {
                std::cout << "  ";
            }
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
    // Place a ship on the board and update the ships vector
}

char Board::getCell(int x, int y)
{
    return grid[x][y];
}

void Board::setCell(int x, int y, char value)
{
    grid[x][y] = value;
}

bool Board::isShipCell(int x, int y)
{
    return grid[x][y] == 'S';
}

bool Board::receiveAttack(int x, int y)
{
    // Handle attack and update the grid and ships
}
