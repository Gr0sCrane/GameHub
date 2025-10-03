#include <iostream>
#include "board.h"

Board::Board(){

}

std::unordered_map<Position2,Boat> Board::getBoats() const{
    return m_boats;
}

void Board::addBoat(Boat &boat){

    auto boatPos = boat.getPosition();
    //TODO
}