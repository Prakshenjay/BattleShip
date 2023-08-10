#include <iostream>
#include "Player.hpp"
#include "Game.hpp"

void Player::giveName(std::string name)
{
    playerName = name;
}

void Player::placeShips()
{
    std::cout << playerName << ", place your ships on the board.\n";

    for (int i = 0 ; i < 5 ; i++)
    {
        int x, y;
        char direction;

        std::cout << "Placing " << shipLength[i] << "-length ship.\n";
        do
        {
            std::cout << "Enter starting coordinates (e.g., A3): ";
            std::string coords;
            std::cin >> coords;

            x = coords[1] - '1';
            y = coords[0] - 'A';

            std::cout << "Enter direction (H for horizontal, V for vertical): ";
            std::cin >> direction;

        } while (!playerBoard.isValidPosition(x, y) || !playerBoard.placeShip(x, y, shipLength[i], direction));

        playerBoard.Display(); 
    }
}

bool Player::takeTurn()
{

}

bool Player::hasLost()
{

}

std::string Player::getName()
{
    return playerName;
}