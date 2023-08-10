
#include "Player.h"
#include <iostream>

Player::Player(std::string playerName) : name(playerName)
{
    
}

void Player::placeShips()
{
    std::cout << name << ", place your ships on the board.\n";
    board.display(true); // Show player's board with ships

    for (Ship& ship : ships) {
        int x, y;
        char direction;

        std::cout << "Placing " << ship.getLength() << "-length ship.\n";
        do
        {
            std::cout << "Enter starting coordinates (e.g., A3): ";
            std::string coords;
            std::cin >> coords;

            x = coords[1] - '1';
            y = coords[0] - 'A';

            std::cout << "Enter direction (H for horizontal, V for vertical): ";
            std::cin >> direction;

        } while (!board.isValidPosition(x, y) || !board.placeShip(x, y, ship.getLength(), direction));

        board.display(true); // Show updated board with placed ship
    }
}

bool Player::takeTurn(Player& opponent)
{
    std::cout << name << "'s turn.\n";
    std::cout << "Opponent's board:\n";
    opponent.getBoard().display();

    int x, y;
    do
    {
        std::cout << "Enter attack coordinates (e.g., A3): ";
        std::string coords;
        std::cin >> coords;

        x = coords[1] - '1';
        y = coords[0] - 'A';

    } while (!board.isValidPosition(x, y) || board.getCell(x, y) == 'X' || board.getCell(x, y) == 'O');

    bool turnOver = opponent.getBoard().receiveAttack(x, y);
    board.setCell(x, y, turnOver ? 'X' : 'O');

    if (turnOver) {
        std::cout << "It's a hit!\n";
    } else {
        std::cout << "It's a miss.\n";
    }

    return !turnOver; // Returns true if the turn is over, false if the player gets another turn
}

bool Player::hasLost()
{
    for (const Ship& ship : ships) {
        if (!ship.isSunk()) {
            return false;
        }
    }
    return true;
}

Board& Player::getBoard()
{
    return board;
}

std::string Player::getName()
{
    return name;
}
