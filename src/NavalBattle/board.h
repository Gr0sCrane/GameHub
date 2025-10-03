#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include "boat.h"

class Board {

private:
    std::unordered_map<Position2,Boat> m_boats;

public:
    Board();
    ~Board() = default;

    std::unordered_map<Position2,Boat> getBoats() const;
    void addBoat(Boat &boat);
    void removeBoat(int index);

};