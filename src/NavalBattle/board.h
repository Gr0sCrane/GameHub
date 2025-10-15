#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <array>
#include "boat.h"

#define BOARD_SIZE_W 5
#define BOARD_SIZE_H 6

enum class Cell {
    EMPTY,
    BOAT
};

class Board {

private:
    std::array<std::array<Cell,BOARD_SIZE_W>,BOARD_SIZE_H> boats;

public:
    Board();
    ~Board() = default;

    std::array<std::array<Cell,BOARD_SIZE_W>,BOARD_SIZE_H> getBoats() const;
    void addBoat(Boat &boat);
    void removeBoat(int index);

};