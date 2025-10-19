#include <iostream>
#include <array>

struct Position2 {
    int x,y;
};

enum class BoatType {
    SQUARE,
    LONG,
    SHORT,
    LARGE
};

enum class Direction {
    UP,
    RIGHT,
    LEFT,
    DOWN
};

class Boat {

protected:
    BoatType m_type;
    std::array<Position2,6> m_positions;
    Direction m_direction;

public:
    Boat(BoatType type, Direction dir);
    ~Boat() = default;

    BoatType getType() const;
    bool isOver(Boat b);
    bool isOob();
    Position2 getPosition() const;
    void setPosition(Position2 newPos);

};

class BoatShort : Boat {

public:
    BoatShort(BoatType type, Direction dir) : Boat(type,dir){};

};

class BoatLong : Boat {

public:
    BoatLong(BoatType type, Direction dir) : Boat(type,dir){};

};

class BoatSquare : Boat {

public:
    BoatSquare(BoatType type, Direction dir) : Boat(type,dir){};

};

class BoatLarge : Boat {

public:
    BoatLarge(BoatType type, Direction dir) : Boat(type,dir){};

};