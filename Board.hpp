#ifndef BOARD_HPP
#define BOARD_HPP

#define BOARD_SIZE 10

class Board
{
private :
        
public :
        char Grid[BOARD_SIZE][BOARD_SIZE];
        Board();
        void Display();
        bool isValidPosition(int x , int y);
        bool placeShip(int x , int y , int length , char direcction);
};

#endif
