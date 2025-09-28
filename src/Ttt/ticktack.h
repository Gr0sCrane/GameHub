#pragma once
#include <iostream>
#include <limits>

enum Turn {
    PLAYER,
    CPU
};

constexpr int BoardSize = 9;

class BoardT {

private:
    int result[8][3] = {{0,1,2}, {3,4,5}, {6,7,8},   // ln
                    {0,3,6}, {1,4,7}, {2,5,8},   // col
                    {0,4,8}, {2,4,6}              // diagonals
                    };
    
public:

    char board[9] = {' ',' ',' ',
                     ' ',' ',' ',
                     ' ',' ',' '};

    BoardT();
    ~BoardT() = default;
    
    void displayTtt();
    bool checkResult();
    bool isDraw();
};

int choice(Turn turn,BoardT &board);

void place(BoardT &board, Turn turn,char icon);


char iconChoice();

void initTtt();

