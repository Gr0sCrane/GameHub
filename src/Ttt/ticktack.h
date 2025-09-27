#pragma once
#include <iostream>

constexpr int BoardSize = 9;

int result[8][3] = {{0,1,2}, {3,4,5}, {6,7,8},   // ln
                        {0,3,6}, {1,4,7}, {2,5,8},   // col
                        {0,4,8}, {2,4,6}              // diagonals
                    };
struct BoardT {

    char board[9] = {' ',' ',' ',
                     ' ',' ',' ',
                     ' ',' ',' '};
    
    void displayTtt();
    bool checkResult();
    bool isDraw();
};