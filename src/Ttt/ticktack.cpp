#include <iostream>
#include "ticktack.h"

BoardT::BoardT(){
    for (int i = 0; i < BoardSize; i++){
        board[i] = ' ';
    }
}

void BoardT::displayTtt(){

    std::cout<<"\n";
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

    for(int i = 0; i < 8; i++){
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
    else {
        int posChoice = choice(turn, board);
        board.board[posChoice] = icon;
    }
}

int choice(Turn turn,BoardT &board) {
    
    if (turn == Turn::PLAYER) {
        int pos;
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

        int pos = randomInt(board);
        return pos;
    }
}


void initTtt(){
    BoardT board;
    srand(time(nullptr));
    
    title();
    board.displayTtt();
    Turn currentTurn = Turn::PLAYER;
    bool running = true;

    while(running){
        if (board.checkResult()){
            std::cout << "-- We have a winner ! --"<<"\n";
            running = false;
            break;
        }
        if (board.isDraw()){
            running = false;
            std::cout<<"|=== DRAW ===|"<<"\n";
            break;
        }  
        if (currentTurn == Turn::PLAYER){
            place(board,currentTurn,'X');
            board.displayTtt();
            currentTurn = Turn::CPU;

        } if (currentTurn == Turn::CPU) {
            place(board,Turn::CPU,'O');
            std::cout << "The CPU has played : "<<"\n";
            board.displayTtt();
            currentTurn = Turn::PLAYER;
        }
    }
    board.displayTtt();
    std::cout<<"===| END OF THE GAME |==="<<"\n";
}

void title(){
    std::cout<<"\n";
    std::cout<<"|==============[Tic Tac Toe]==============|"<<"\n";
    std::cout<<"\n";
    std::cout<< "Game board: " << "\n";
    std::cout<<"\n";
    std::cout<<"\n";
}

int randomInt(BoardT &board){
    int random = rand() % 9;

    if (board.isDraw()){
        return NULL;
    }

    while(board.board[random] != ' '){
        random = rand() % 9;
    }

    return random;
}

