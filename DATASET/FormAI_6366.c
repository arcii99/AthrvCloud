//FormAI DATASET v1.0 Category: Table Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 6
#define WIDTH 7

// Print the board
void printBoard(char board[][WIDTH]) {
    printf("\n");
    for (int row = HEIGHT - 1; row >= 0; row--) { // Print bottom to top (for display purposes)
        printf("| ");
        for (int col = 0; col < WIDTH; col++) {
            printf("%c ", board[row][col]);
        }
        printf("|\n");
    }
    printf("+--------------------------+\n");
    printf("  1 2 3 4 5 6 7\n");
}

// Check if move is valid
int isValidMove(char board[][WIDTH], int col) {
    if (col < 0 || col > WIDTH - 1) { // Check if within board boundaries
        return 0;
    }
    if (board[HEIGHT - 1][col] != ' ') { // Check if column is not full
        return 0;
    }
    return 1;
}

// Update the board with the new move
void updateBoard(char board[][WIDTH], int col, char player) {
    for (int row = 0; row < HEIGHT; row++) { // Starting from bottom of the column
        if (board[row][col] == ' ') {
            board[row][col] = player;
            break;
        }
    }
}

// Check for a win
int checkWin(char board[][WIDTH], char player) {
    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            if (board[row][col] == player) { // Check horizontally
                if (col + 3 < WIDTH && board[row][col+1] == player && board[row][col+2] == player && board[row][col+3] == player) {
                    return 1;
                }
            }
            if (board[row][col] == player) { // Check vertically
                if (row + 3 < HEIGHT && board[row+1][col] == player && board[row+2][col] == player && board[row+3][col] == player) {
                    return 1;
                }
            }
            if (board[row][col] == player) { // Check diagonally
                if (col + 3 < WIDTH && row + 3 < HEIGHT && board[row+1][col+1] == player && board[row+2][col+2] == player && board[row+3][col+3] == player) {
                    return 1;
                }
                if (col - 3 >= 0 && row + 3 < HEIGHT && board[row+1][col-1] == player && board[row+2][col-2] == player && board[row+3][col-3] == player) {
                    return 1;
                }
            }
        }
    }
    return 0; // No win
}

// Get the computer's move (random)
int getComputerMove(char board[][WIDTH]) {
    int validMoves[WIDTH];
    int numValidMoves = 0;
    for (int col = 0; col < WIDTH; col++) {
        if (isValidMove(board, col)) {
            validMoves[numValidMoves] = col;
            numValidMoves++;
        }
    }
    if (numValidMoves == 0) {
        return -1; // Board is full
    }
    int randomIndex = rand() % numValidMoves;
    return validMoves[randomIndex];
}

int main() {
    char board[HEIGHT][WIDTH] = {' '}; // Initialize the board with empty spaces
    char player = 'X';
    int numMoves = 0;
    srand(time(NULL));
    printf("\nWelcome to Connect Four!\n");
    while (1) {
        printBoard(board);
        if (numMoves % 2 == 0) {
            printf("Player X, make your move (1-7): ");
            int col;
            scanf("%d", &col);
            col--; // Convert to 0-based index
            if (isValidMove(board, col)) {
                updateBoard(board, col, player);
                if (checkWin(board, player)) {
                    printf("\nCongratulations Player %c, you win!\n", player);
                    return 0;
                }
                numMoves++;
                player = 'O';
            } else {
                printf("\nInvalid move, please try again.\n");
            }
        } else {
            printf("Computer (O) is making a move...\n");
            int col = getComputerMove(board);
            if (col != -1) {
                updateBoard(board, col, player);
                if (checkWin(board, player)) {
                    printf("\nSorry, you lost. Better luck next time!\n");
                    return 0;
                }
                numMoves++;
                player = 'X';
            } else {
                printf("\nThe game is a tie!\n");
                return 0;
            }
        }
    }
}