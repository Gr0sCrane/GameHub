#include <iostream>

struct Position2 {

    int x,y;
};

enum BoatType {
    SQUARE,
    LONG,
    SHORT
};

class Boat {

private:
    BoatType m_type;
    Position2 m_position;

public:
    Boat();
    ~Boat() = default;

    BoatType getType() const;
    Position2 getPosition() const;
    void setPosition(Position2 newPos);

};