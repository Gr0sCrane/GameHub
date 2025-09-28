#include <iostream>
#include "Ttt/ticktack.h"

int main()
{   
    BoardT board;
    auto icon = iconChoice();
    place(board,Turn::PLAYER,icon);
    board.displayTtt();
    return 0;
}