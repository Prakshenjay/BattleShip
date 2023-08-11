#include <iostream>
#include "Computer.hpp"

Computer::Computer()
{
    std::random_device rd;
    rng = std::mt19937(rd());
}

void Computer::placeShips()
{
    for (int i = 0 ; i < 5 ; i++)
    {
        int x, y;
        char direction;

        x = std::uniform_int_distribution<int>(0, BOARD_SIZE - 1)(rng);
        y = std::uniform_int_distribution<int>(0, BOARD_SIZE - 1)(rng);

        direction = (rng() % 2 == 0) ? 'H' : 'V';

        for(int j = 0 ; j < shipLength[i] ; j++)
        {
            if(direction == 'H')
                Grid[x][y+j] = 'S';
            else
                Grid[x+j][y] = 'S';
        }
    }
}

void Computer::takeTurn(Player& opponent)
{
    int x, y;

    do
    {
        x = std::uniform_int_distribution<int>(0, BOARD_SIZE - 1)(rng);
        y = std::uniform_int_distribution<int>(0, BOARD_SIZE - 1)(rng);

    } while (Grid[x][y] == '*' || Grid[x][y] == 'X');

    std::cout << "Computer attacks " << static_cast<char>('A' + x) << y << ". ";
    
    if (opponent.Grid[x][y] == 'S')
    {
        std::cout << "It's a hit!\n";
        opponent.Grid[x][y] = 'X';
    }
    else
    {
        std::cout << "It's a miss.\n";
        opponent.Grid[x][y] = '*';
    }
}

