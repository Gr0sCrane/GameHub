#include <iostream>
#include "ticktack.h"

BoardT::BoardT(){}

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
            return true;
        }
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

void place(BoardT &board, Turn turn, char icon){

    if (turn == Turn::PLAYER){
        int posChoice = choice(turn,board);
        board.board[posChoice] = icon;
    }
}

int choice(Turn turn,BoardT &board) {

    if (turn == Turn::PLAYER) {
        int pos;
        char Icon = iconChoice();
        std::cout << "Enter the index of the case you want to select (1-9): ";
        std::cin >> pos;

        while (std::cin.fail() || pos < 1 || pos > 9 || board.board[pos-1] != ' ') {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Error, the case are already taken or you need to enter a number between 1 and 9: ";
            std::cin >> pos;
        }

        return pos - 1;
    } else {
        // CPU TODO code
        return 0;
    }
}

char iconChoice(){

    char icon;
    std::cout << "Choose between X and O to begin with: ";
    std::cin >> icon;

        while (std::cin.fail() || (icon != 'X' && icon != 'O')) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Incorrect, enter X or O"<<"\n";
            std::cin >> icon;
        }
    return icon;
}

void initTtt(){
}

