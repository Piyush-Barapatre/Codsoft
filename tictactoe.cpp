#include <iostream>
#include <vector>

using namespace std;

// Function to print the Tic-Tac-Toe board
void printBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }

    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    return false;
}

// Function to check if the game is a draw
bool checkDraw(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '-') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, '-')); // Initialize the board with empty cells
    int row, col;
    bool player1Turn = true;
    bool gameOver = false;

    while (!gameOver) {
        printBoard(board);
        if (player1Turn) {
            cout << "Player 1 (X), enter your move (row and column): ";
            cin >> row >> col;
            if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == '-') {
                board[row][col] = 'X';
                if (checkWin(board, 'X')) {
                    cout << "Player 1 wins!" << endl;
                    gameOver = true;
                } else if (checkDraw(board)) {
                    cout << "The game is a draw." << endl;
                    gameOver = true;
                } else {
                    player1Turn = false;
                }
            } else {
                cout << "Invalid move. Try again." << endl;
            }
        } else {
            cout << "Player 2 (O), enter your move (row and column): ";
            cin >> row >> col;
            if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == '-') {
                board[row][col] = 'O';
                if (checkWin(board, 'O')) {
                    cout << "Player 2 wins!" << endl;
                    gameOver = true;
                } else if (checkDraw(board)) {
                    cout << "The game is a draw." << endl;
                    gameOver = true;
                } else {
                    player1Turn = true;
                }
            } else {
                cout << "Invalid move. Try again." << endl;
            }
        }
    }

    printBoard(board);

    return 0;
}
