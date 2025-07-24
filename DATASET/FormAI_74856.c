//FormAI DATASET v1.0 Category: Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define macro constants for game parameters
#define BOARD_SIZE 5
#define MAX_MOVES 10

// Define function signatures
void initializeBoard(int board[][BOARD_SIZE]);
void printBoard(int board[][BOARD_SIZE]);
void makeMove(int board[][BOARD_SIZE], int* row, int* col);
int checkWin(int board[][BOARD_SIZE]);
int isValidMove(int board[][BOARD_SIZE], int row, int col);

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];
    int player = 1;
    int row, col;
    int numMoves = 0;

    // Seed random number generator for computer's moves
    srand(time(NULL));

    // Initialize the board and display it
    initializeBoard(board);
    printBoard(board);

    while (1) {
        // Make a move
        if (player == 1) {
            makeMove(board, &row, &col);
        } else {
            // Computer's move - choose a random valid move
            do {
                row = rand() % BOARD_SIZE;
                col = rand() % BOARD_SIZE;
            } while (!isValidMove(board, row, col));
            printf("Computer chooses row %d, col %d\n", row+1, col+1);
        }

        // Update the board and display it
        board[row][col] = player;
        printBoard(board);
        numMoves++;

        // Check for a win
        if (checkWin(board)) {
            printf("Player %d wins!\n", player);
            break;
        }

        // Check for a draw
        if (numMoves == MAX_MOVES) {
            printf("Draw!\n");
            break;
        }

        // Switch to the other player
        player = (player == 1) ? 2 : 1;
    }

    return 0;
}

void initializeBoard(int board[][BOARD_SIZE]) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }
}

void printBoard(int board[][BOARD_SIZE]) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            char c = ' ';
            if (board[i][j] == 1) c = 'X';
            else if (board[i][j] == 2) c = 'O';
            printf(" %c ", c);
            if (j < BOARD_SIZE-1) printf("|");
        }
        printf("\n");
        if (i < BOARD_SIZE-1) {
            for (j = 0; j < BOARD_SIZE; j++) {
                printf("---");
                if (j < BOARD_SIZE-1) printf("+");
            }
            printf("\n");
        }
    }
    printf("\n");
}

void makeMove(int board[][BOARD_SIZE], int* row, int* col) {
    while (1) {
        printf("Enter row (1-%d) and column (1-%d) of your move: ", BOARD_SIZE, BOARD_SIZE);
        scanf("%d%d", row, col);
        (*row)--;
        (*col)--;

        if (isValidMove(board, *row, *col)) {
            break;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
}

int checkWin(int board[][BOARD_SIZE]) {
    int i, j;

    // Check rows
    for (i = 0; i < BOARD_SIZE; i++) {
        int count = 0;
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == board[i][0] && board[i][0] != 0) {
                count++;
            }
        }
        if (count == BOARD_SIZE) {
            return 1;
        }
    }

    // Check columns
    for (j = 0; j < BOARD_SIZE; j++) {
        int count = 0;
        for (i = 0; i < BOARD_SIZE; i++) {
            if (board[i][j] == board[0][j] && board[0][j] != 0) {
                count++;
            }
        }
        if (count == BOARD_SIZE) {
            return 1;
        }
    }

    // Check diagonal 1
    int count = 0;
    for (i = 0; i < BOARD_SIZE; i++) {
        if (board[i][i] == board[0][0] && board[0][0] != 0) {
            count++;
        }
    }
    if (count == BOARD_SIZE) {
        return 1;
    }

    // Check diagonal 2
    count = 0;
    for (i = 0; i < BOARD_SIZE; i++) {
        if (board[i][BOARD_SIZE-i-1] == board[0][BOARD_SIZE-1] && board[0][BOARD_SIZE-1] != 0) {
            count++;
        }
    }
    if (count == BOARD_SIZE) {
        return 1;
    }

    return 0;
}

int isValidMove(int board[][BOARD_SIZE], int row, int col) {
    if (row < 0 || row >= BOARD_SIZE) return 0;
    if (col < 0 || col >= BOARD_SIZE) return 0;
    if (board[row][col] != 0) return 0;
    return 1;
}