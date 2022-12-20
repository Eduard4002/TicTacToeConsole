// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>

char board[9] = { '1', '2', '3',
                '4', '5', '6',
                '7', '8', '9' };
int winP1 = 0;
int winP2 = 0;
char player1 = 'O';
char player2 = 'X';
char curr = 'X';

void DisplayBoard() {
    std::cout << " " << board[0] << " | " << board[1] << " | " << board[2] << std::endl;
    std::cout << "-----------" << std::endl;
    std::cout << " " << board[3] << " | " << board[4] << " | " << board[5] << std::endl;
    std::cout << "-----------" << std::endl;
    std::cout << " " << board[6] << " | " << board[7] << " | " << board[8] << std::endl;
    std::cout << std::endl;

}
void ResetBoard() {
    board[0] = '1';
    board[1] = '2';
    board[2] = '3';
    board[3] = '4';
    board[4] = '5';
    board[5] = '6';
    board[6] = '7';
    board[7] = '8';
    board[8] = '9';
}
bool isEmpty(int cell) {
    return !((board[cell] == 'X' || board[cell] == 'O')) ? true : false;
}
char checkWinner() {
    //ROWS
    if ((board[0] == curr && board[1] == curr && board[2] == curr) ||
        (board[3] == curr && board[4] == curr && board[5] == curr) ||
        (board[6] == curr && board[7] == curr && board[8] == curr)) {
        return curr;
    }
    //COLLS
    if ((board[0] == curr && board[3] == curr && board[6] == curr) ||
        (board[1] == curr && board[4] == curr && board[7] == curr) ||
        (board[2] == curr && board[5] == curr && board[8] == curr)) {
        return curr;
    }
    //DIAG
    if ((board[0] == curr && board[4] == curr && board[8] == curr) ||
        (board[2] == curr && board[4] == curr && board[6] == curr)){
        return curr;
    }
    //DRAW?
    short count = 0;
    for (unsigned int i = 0; i < 9;i++) {
        if (!isEmpty(i)) {
            count++;
        }
    }
    if (count == 9) {
        return 'D';
    }
    return ' ';
}

void StartGame(bool again = false) {
    if (again) {
        player1 = (player1 == 'X') ? 'O' : 'X';
        player2 = (player2 == 'X') ? 'O' : 'X';

    }
    std::cout << "PLAYER 1: <" << player1 << "> - PLAYER 2 <" << player2 << ">" << std::endl;
    DisplayBoard();
    unsigned int choiceNum;
    std::cout << "Current turn: " << curr << std::endl;
    std::cout << "Enter number: ";
    std::cin >> choiceNum;

    std::cout << std::endl;
    if (!isEmpty(choiceNum - 1)) {
        std::cout << "INVALID: POSITION TAKEN!" << std::endl;
        Sleep(2000);
        system("CLS");
        StartGame();
    }
    board[choiceNum - 1] = curr;
    char win = checkWinner();
    if (win == ' ') {
        curr = (curr == 'X') ? 'O' : 'X';
        system("CLS");
        StartGame();
    }

    if (win == player1) {
        winP1++;
        std::cout << "WINNER IS: PLAYER 1" << std::endl;
    }
    else if (win == player2) {
        winP2++;
        std::cout << "WINNER IS: PLAYER 2" << std::endl;
    }
    else if (win == 'D') {
        std::cout << "IT IS A DRAW" << std::endl;
    }
}
int main()
{
    StartGame(true);
    char choice = 'n';
    std::cout << "Would you like to go again [y/n]";
    std::cin >> choice;
    if (choice == 'Y' || choice == 'y') {
        ResetBoard();
        system("CLS");
        main();
    }
    else {
        std::cout << "===RESULTS===" << std::endl;
        std::cout << "PLAYER 1: " << winP1 << std::endl;
        std::cout << "PLAYER 2: " << winP2 << std::endl;

    }
}

