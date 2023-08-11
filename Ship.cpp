#include "Ship.hpp"

Ship::Ship(int len) : length(len), hits(0) {}

int Ship::getLength() const {
    return length;
}

bool Ship::isSunk() const {
    return hits >= length;
}

void Ship::hit() {
    ++hits;
}
