#include <iostream>
#include "boat.h"

Boat::Boat(BoatType type, Direction dir){};

BoatSquare::BoatSquare(BoatType type, Direction dir) : Boat::Boat(type,dir) {

    Position2 base = {0,0};
    m_direction = dir;

    m_positions[0] = base;
    m_positions[1] = {base.x + 1, base.y};
    m_positions[2] = {base.x, base.y + 1};
    m_positions[3] = {base.x + 1, base.y + 1};

};

BoatLarge::BoatLarge(BoatType type, Direction dir) : Boat::Boat(type,dir){

    Position2 base = {0,0};
    m_direction = dir;

    m_positions[0] = base;


    switch(m_direction){
        case Direction::DOWN:

            m_positions[1] = {base.x + 1, base.y};
            m_positions[2] = {base.x, base.y + 1};
            m_positions[3] = {base.x + 1, base.y + 1};
            m_positions[4] = {base.x, base.y + 2};
            m_positions[5] = {base.x + 1, base.y + 2};

        case Direction::UP:
           
            m_positions[1] = {base.x + 1, base.y - 1};
            m_positions[2] = {base.x, base.y - 1};
            m_positions[3] = {base.x + 1, base.y - 1};
            m_positions[4] = {base.x, base.y - 2};
            m_positions[5] = {base.x + 1, base.y - 2};

        case Direction::LEFT:
            
            m_positions[1] = {base.x, base.y + 1};
            m_positions[2] = {base.x + 1, base.y};
            m_positions[3] = {base.x + 1, base.y + 1};
            m_positions[4] = {base.x + 2, base.y};
            m_positions[5] = {base.x + 2, base.y + 2};

        case Direction::RIGHT:
            
            m_positions[1] = {base.x, base.y + 1};
            m_positions[2] = {base.x - 1, base.y};
            m_positions[3] = {base.x - 1, base.y + 1};
            m_positions[4] = {base.x - 2, base.y};
            m_positions[5] = {base.x - 2, base.y + 2};
            
        default:
            throw std::invalid_argument("The direction is incorrect");
    };

}

BoatShort::BoatShort(BoatType type,Direction dir) : Boat::Boat(type,dir){

    Position2 base = {0,0};
    m_direction = dir;

    m_positions[0] = base;

    switch(m_direction){

        case Direction::UP:
            m_positions[1] = {base.x, base.y + 1};

        case Direction::DOWN:
            m_positions[1] = {base.x,base.y - 1};

        case Direction::LEFT:
            m_positions[1] = {base.x - 1,base.y};

        case Direction::RIGHT:
            m_positions[1] = {base.x + 1,base.y};
        
        default:
            throw std::invalid_argument("The direction is incorrect");
    }
}


Position2 Boat::getPosition() const {
    
}


BoatType Boat::getType() const {
    return m_type;
}