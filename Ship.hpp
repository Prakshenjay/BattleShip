#ifndef SHIP_H
#define SHIP_H

class Ship
{
private:
    int length;
    int hits;

public:
    Ship(int len);
    int getLength() const;
    bool isSunk() const;
    void hit();
};

#endif // SHIP_H
