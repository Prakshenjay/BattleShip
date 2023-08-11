#include <iostream>
#include "Player.hpp"

Player::Player()
{
    for(int i = 0 ; i < BOARD_SIZE ; i++)
    {
        for(int j = 0 ; j < BOARD_SIZE ; j++)
        {
            Grid[i][j] = '.';
        }
    }
}

void Player::giveName(std::string name)
{
    playerName = name;
}

std::string Player::getName()
{
    return playerName;
}

void Player::display()
{
    std::cout << "\n";
    std::cout << "\t\t  ";
    for(int j = 0 ; j < BOARD_SIZE ; j++)
    {
        std::cout << " " << j << " ";
    }
    std::cout << "\n";
    //    
    std::cout << "\t\t  ";
    for(int j = 0 ; j < BOARD_SIZE ; j++)
    {
        std::cout << "---";
    }
    std::cout << "\n";
    //
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

void Player::placeShips()
{
    std::cout << playerName << ", place your ships on the board.\n";

    for (int i = 0 ; i < 5 ; i++)
    {
        int x, y;
        char direction;

        display();

        std::cout << "Placing " << shipLength[i] << "-length ship.\n";
        
        std::cout << "Enter starting coordinates (e.g., A3): ";
        std::string coords;
        std::cin >> coords;

        x = coords[0] - 'A';
        y = coords[1] - '0';

        std::cout << "Enter direction (H for horizontal, V for vertical): ";
        std::cin >> direction;

        for(int j = 0 ; j < shipLength[i] ; j++)
        {
            if(direction == 'H')
                Grid[x][y+j] = 'S';
            else
                Grid[x+j][y] = 'S';
        }
    }
}

void Player::takeTurn(Player& opponent)
{
    int x, y;

    do
    {
        std::cout << "Enter attack coordinates (e.g., A3): ";
        std::string coords;
        std::cin >> coords;

        x = coords[0] - 'A';
        y = coords[1] - '0';

    } while (opponent.Grid[x][y] == '*' || opponent.Grid[x][y] == '*');

    std::cout << "You attack " << static_cast<char>('A' + x) << y << ". ";

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

bool Player::hasLost()
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (Grid[i][j] == 'S')
            {
                return false;
            }
        }
    }
    return true;
}
