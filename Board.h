
#ifndef BOARD_H
#define BOARD_H

#include <vector>

const int BOARD_SIZE = 10;

class Board
{
private:
    char grid[BOARD_SIZE][BOARD_SIZE];
    //std::vector<Ship> ships; // Store ships on the board

public:
    Board();
    void display(bool showShips = false);
    bool isValidPosition(int x, int y);
    bool placeShip(int x, int y, int length, char direction);
    char getCell(int x, int y);
    void setCell(int x, int y, char value);
    bool isShipCell(int x, int y);
    bool receiveAttack(int x, int y);
};

#endif // BOARD_H
