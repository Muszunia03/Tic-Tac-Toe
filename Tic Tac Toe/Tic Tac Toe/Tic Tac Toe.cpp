#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void drawBoard(char board[3][3]) {
    cout << "-------------\n";
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

bool checkWin(char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    return false;
}

void botMove(char board[3][3], char botPlayer) {
    int row, col;
    srand(time(0));

    while (true) {
        row = rand() % 3;
        col = rand() % 3;
        if (board[row][col] == ' ') {
            board[row][col] = botPlayer;
            break;
        }
    }
}

int main() {
    std::cout << "Hi, welcome to Tic Tac Toe!\n";

    char board[3][3] = { {' ',' ',' '},
                         {' ',' ',' '},
                         {' ',' ',' '} };

    char player1, player2;
    char currentPlayer;
    bool playAgainstBot = false;

    cout << "Do you want to be X or O? ";
    cin >> player1;

    if (player1 == 'O') {
        player2 = 'X';
    }
    else {
        player1 = 'X';
        player2 = 'O';
    }

    cout << "Do you want to play against a bot? (y/n): ";
    char choice;
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        playAgainstBot = true;
    }

    currentPlayer = 'X';
    int row, clm;
    int turn;

    for (turn = 0; turn < 9; turn++) {
        drawBoard(board);

        if (playAgainstBot && currentPlayer == player2) {
            cout << "Bot is making a move...\n";
            botMove(board, player2);
        }
        else {
            while (true) {
                cout << "Move for player " << currentPlayer << ": Enter row (0-2) and column (0-2) [Example: 0 2]: ";
                cin >> row >> clm;

                if (board[row][clm] != ' ' || row > 2 || row < 0 || clm > 2 || clm < 0) {
                    cout << "Invalid Input. Try Again please \n";
                }
                else {
                    board[row][clm] = currentPlayer;
                    break;
                }
            }
        }

        if (checkWin(board, currentPlayer)) {
            drawBoard(board);
            cout << "Player " << currentPlayer << " Wins!!! No way\n";
            return 0;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    drawBoard(board);

    if (turn == 9 && !checkWin(board, 'X') && !checkWin(board, 'O')) {
        cout << "It is a draw, we can call it, Czech Draw!" << endl;
    }

    return 0;
}

