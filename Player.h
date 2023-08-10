
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Board.h"

class Player
{
private:
    Board board;
    std::string name;
    std::vector<Ship> ships; // Store ships of the player

public:
    Player(std::string playerName);
    void placeShips();
    bool takeTurn(Player& opponent);
    bool hasLost();
    Board& getBoard();
    std::string getName();
};

#endif // PLAYER_H
