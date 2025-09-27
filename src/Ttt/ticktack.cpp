#include <iostream>
#include "ticktack.h"

void BoardT::displayTtt(){
    std::cout << "   1   2   3\n";
    for (int i = 0; i < 3; i++) {
        std::cout << i + 1 << "  ";
        for (int j = 0; j < 3; j++) {
            int index = i * 3 + j;
            std::cout << board[index];
            if (j < 2) std::cout << " | ";
        }
        std::cout << "\n";
        if (i < 2) std::cout << "  ---+---+---\n";
    }
    std::cout << "\n";
}

bool BoardT::checkResult()
{

    for(int i = 0; i < BoardSize; i++){
        int a = result[i][0];
        int b = result[i][1];
        int c = result[i][2];
        if(board[a] != ' ' && board[a] == board[b] && board[a] == board[c]){
            /*DEBUG*/
            std::cout<<"Trouve"<<"\n";
            return true;
        }
        /*DEBUG*/
        std::cout<<"Pas trouve"<<"\n";
    }

    return false;
}

bool BoardT::isDraw(){

    for (int i = 0; i < BoardSize; i++){
        if(board[i] == ' '){
            return false;
        }
    }
    return true;
}