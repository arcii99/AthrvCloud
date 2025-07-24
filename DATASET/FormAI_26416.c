//FormAI DATASET v1.0 Category: Game ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define ROWS 10
#define COLS 10
#define MAX_BOMBS 20

// Function prototypes
void initBoard(int board[ROWS][COLS]);
void placeBombs(int board[ROWS][COLS], int numBombs);
void printBoard(int board[ROWS][COLS], int reveal);
void revealCell(int board[ROWS][COLS], int row, int col);
int countAdjacentBombs(int board[ROWS][COLS], int row, int col);
int isWin(int board[ROWS][COLS]);
void gameOver();

int main() {
    // Initialize random seed
    srand(time(NULL));

    // Initialize game board and place bombs
    int board[ROWS][COLS];
    initBoard(board);
    placeBombs(board, MAX_BOMBS);

    // Game loop
    int row, col, reveal = 0, gameOver = 0;
    do {
        // Print game board
        printBoard(board, reveal);

        // Get user input
        printf("Enter row and column: ");
        scanf("%d %d", &row, &col);

        // Check if input is valid
        if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
            printf("Invalid row or column.\n");
            continue;
        }

        // Reveal cell and check if game over
        revealCell(board, row, col);
        if (board[row][col] == -1) {
            gameOver = 1;
        } else if (isWin(board)) {
            printf("Congratulations, you win!\n");
            reveal = 1;
            gameOver = 1;
        }
    } while (!gameOver);

    // Print final game board
    printBoard(board, 1);

    return 0;
}

// Function to initialize game board with 0's
void initBoard(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = 0;
        }
    }
}

// Function to randomly place bombs on game board
void placeBombs(int board[ROWS][COLS], int numBombs) {
    int count = 0;
    while (count < numBombs) {
        int row = rand() % ROWS;
        int col = rand() % COLS;
        if (board[row][col] != -1) {
            board[row][col] = -1;
            count++;
        }
    }
}

// Function to print game board
void printBoard(int board[ROWS][COLS], int reveal) {
    printf("  ");
    for (int j = 0; j < COLS; j++) {
        printf("%d ", j);
    }
    printf("\n");

    for (int i = 0; i < ROWS; i++) {
        printf("%d ", i);
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == -1 && reveal) {
                printf("* ");
            } else if (board[i][j] == -2 && reveal) {
                printf("F ");
            } else if (board[i][j] < 0 && !reveal) {
                printf(". ");
            } else {
                printf("%d ", board[i][j]);
            }
        }
        printf("\n");
    }
}

// Function to reveal cell and its adjacent cells
void revealCell(int board[ROWS][COLS], int row, int col) {
    if (board[row][col] < 0) {
        return;
    } else if (board[row][col] > 0) {
        board[row][col] *= -1;
        return;
    }

    board[row][col] = -(countAdjacentBombs(board, row, col) + 1);

    if (board[row][col] == -1) {
        return;
    }

    if (row > 0) {
        revealCell(board, row - 1, col);
    }
    if (row < ROWS - 1) {
        revealCell(board, row + 1, col);
    }
    if (col > 0) {
        revealCell(board, row, col - 1);
    }
    if (col < COLS - 1) {
        revealCell(board, row, col + 1);
    }
}

// Function to count adjacent bombs in game board
int countAdjacentBombs(int board[ROWS][COLS], int row, int col) {
    int count = 0;
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            if (i >= 0 && i < ROWS && j >= 0 && j < COLS && board[i][j] == -1) {
                count++;
            }
        }
    }
    return count;
}

// Function to check if player has won the game
int isWin(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] >= 0 && board[i][j] <= 8 && board[i][j] != -2) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to print game over message
void gameOver() {
    printf("Game over!\n");
}