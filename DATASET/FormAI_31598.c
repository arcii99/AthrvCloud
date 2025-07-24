//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 3

// Structure to represent a move
typedef struct {
    int row;
    int col;
} Move;

// Function to initialize the board to empty spaces
void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to print the current state of the board
void printBoard(const char board[BOARD_SIZE][BOARD_SIZE]) {
    printf("\n");
    printf("     1   2   3  \n");
    printf("   +---+---+---+\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf(" %d | %c | %c | %c |\n", i+1, board[i][0], board[i][1], board[i][2]);
        printf("   +---+---+---+\n");
    }
    printf("\n");
}

// Function to check if the given move is valid
bool isValidMove(const char board[BOARD_SIZE][BOARD_SIZE], const Move move) {
    if (move.row < 0 || move.row >= BOARD_SIZE || move.col < 0 || move.col >= BOARD_SIZE) {
        return false;   // Move is out of bounds
    } else if (board[move.row][move.col] != ' ') {
        return false;   // Position is already occupied
    } else {
        return true;    // Move is valid
    }
}

// Function to check if the game is over
bool isGameOver(const char board[BOARD_SIZE][BOARD_SIZE], char* winner) {
    int i, j;
    // Check rows
    for (i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            *winner = board[i][0];
            return true;
        }
    }
    // Check columns
    for (j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') {
            *winner = board[0][j];
            return true;
        }
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        *winner = board[0][0];
        return true;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        *winner = board[0][2];
        return true;
    }
    // Check if any space is empty
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    // If we got here then it's a tie game
    *winner = 'T';
    return true;
}

// Function to make the computer move
Move getComputerMove(const char board[BOARD_SIZE][BOARD_SIZE], const char computerMark) {
    // First check if there's a winning move
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                char temp[BOARD_SIZE][BOARD_SIZE];  // Make a copy of the board to test the move
                for (int ii = 0; ii < BOARD_SIZE; ii++) {
                    for (int jj = 0; jj < BOARD_SIZE; jj++) {
                        temp[ii][jj] = board[ii][jj];
                    }
                }
                temp[i][j] = computerMark;
                char winner = ' ';
                if (isGameOver(temp, &winner)) {
                    if (winner == computerMark) {
                        Move move = {i, j};
                        return move;
                    }
                }
            }
        }
    }
    // If we didn't find a winning move, check if we need to block the opponent's winning move
    char opponentMark = computerMark == 'X' ? 'O' : 'X';
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                char temp[BOARD_SIZE][BOARD_SIZE];  // Make a copy of the board to test the move
                for (int ii = 0; ii < BOARD_SIZE; ii++) {
                    for (int jj = 0; jj < BOARD_SIZE; jj++) {
                        temp[ii][jj] = board[ii][jj];
                    }
                }
                temp[i][j] = opponentMark;
                char winner = ' ';
                if (isGameOver(temp, &winner)) {
                    if (winner == opponentMark) {
                        Move move = {i, j};
                        return move;
                    }
                }
            }
        }
    }
    // If we didn't find a winning or blocking move, pick a random empty space
    int row, col;
    do {
        row = rand() % BOARD_SIZE;
        col = rand() % BOARD_SIZE;
    } while (board[row][col] != ' ');
    Move move = {row, col};
    return move;
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    char playerMark, computerMark;
    int playerChoice;
    Move move;
    char winner;

    // Initialize the board and randomly choose who goes first
    initializeBoard(board);
    if (rand() % 2 == 0) {
        playerMark = 'X';
        computerMark = 'O';
        printf("You go first (X):\n");
    } else {
        playerMark = 'O';
        computerMark = 'X';
        printf("Computer goes first (X):\n");
    }

    // Play the game
    while (!isGameOver(board, &winner)) {
        if (playerMark == 'X') {
            printf("Your turn (X): ");
            scanf("%d", &playerChoice);
            move.row = (playerChoice - 1) / 3;
            move.col = (playerChoice - 1) % 3;
            while (!isValidMove(board, move)) {
                printf("Invalid move\n");
                printf("Your turn (X): ");
                scanf("%d", &playerChoice);
                move.row = (playerChoice - 1) / 3;
                move.col = (playerChoice - 1) % 3;
            }
            board[move.row][move.col] = playerMark;
            printBoard(board);
        }
        move = getComputerMove(board, computerMark);
        printf("Computer's turn (%c): %d\n", computerMark, move.row * 3 + move.col + 1);
        board[move.row][move.col] = computerMark;
        printBoard(board);
    }

    // Print the winner
    if (winner == playerMark) {
        printf("You win!\n");
    } else if (winner == computerMark) {
        printf("Computer wins!\n");
    } else {
        printf("Tie game.\n");
    }

    return 0;
}