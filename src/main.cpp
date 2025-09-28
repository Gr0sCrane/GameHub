#include <iostream>
#include "Ttt/ticktack.h"

int main()
{   
    BoardT board;
    board.displayTtt();
    board.checkResult();
    auto icon = iconChoice();
    place(board,Turn::PLAYER,icon);
    return 0;
}