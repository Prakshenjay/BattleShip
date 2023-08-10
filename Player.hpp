#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

class Player
{
private :
        std::string playerName;
        int shipLength[5] = {3,3,4,4,5};
        
public :
        Board playerBoard;
        void giveName(std::string name);
        void placeShips();
        bool takeTurn();
        bool hasLost();
        std::string getName();
};

#endif