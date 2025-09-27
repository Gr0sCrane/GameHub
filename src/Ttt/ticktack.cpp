#include <iostream>
#include "ticktack.h"

void BoardT::displayTtt(){
    std::cout << "   1   2   3\n";
    for (int i = 0; i < 3; i++) {
        std::cout << i + 1 << "  ";
        for (int j = 0; j < 3; j++) {
            std::cout << board[i][j];
            if (j < 2) std::cout << " | ";
        }
        std::cout << "\n";
        if (i < 2) std::cout << "  ---+---+---\n";
    }
    std::cout << "\n";
}