#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

#define BOARD_SIZE 10

class Player
{
private :
        std::string playerName;
        
public :
        char Grid[BOARD_SIZE][BOARD_SIZE];
        int shipLength[5] = {3,3,4,4,5};
        
        Player();
        
        void giveName(std::string name);
        std::string getName();
        
        void display();
        void placeShips();
        virtual void takeTurn(Player& opponent);
        bool hasLost();
};

#endif
