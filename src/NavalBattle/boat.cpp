#include <iostream>
#include "boat.h"

Boat::Boat(){

}

Position2 Boat::getPosition() const {
    return m_position;
}

void Boat::setPosition(Position2 newPos){
    m_position = newPos;
}

BoatType Boat::getType() const {
    return m_type;
}