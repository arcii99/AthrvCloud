//FormAI DATASET v1.0 Category: Game of Life ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Defines the size of the game board.
#define BOARD_WIDTH 40
#define BOARD_HEIGHT 20

// Define the Cell structure
typedef struct {
    int x, y;
} Cell;

// Initializes the board with random values.
void initializeBoard(int board[][BOARD_WIDTH]) {
    srand(time(NULL));
    for(int i = 0; i < BOARD_HEIGHT; i++) {
        for(int j = 0; j < BOARD_WIDTH; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

// Prints the current board state.
void printBoard(int board[][BOARD_WIDTH]) {
    for(int i = 0; i < BOARD_HEIGHT; i++) {
        for(int j = 0; j < BOARD_WIDTH; j++) {
            if(board[i][j] == 1) {
                printf("#");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

// Gets the number of alive neighbors for a given cell.
int getNumAliveNeighbors(int board[][BOARD_WIDTH], int x, int y) {
    int numAliveNeighbors = 0;
    for(int i = -1; i <= 1; i++) {
        for(int j = -1; j <= 1; j++) {
            if(i == 0 && j == 0) continue;
            int neighborX = x + i;
            int neighborY = y + j;
            if(neighborX >= 0 && neighborX < BOARD_HEIGHT && neighborY >= 0 && neighborY < BOARD_WIDTH) {
                if(board[neighborX][neighborY] == 1) {
                    numAliveNeighbors++;
                }
            }
        }
    }
    return numAliveNeighbors;
}

// Updates the board by applying the game rules.
void updateBoard(int board[][BOARD_WIDTH]) {
    int newBoard[BOARD_HEIGHT][BOARD_WIDTH];
    for(int i = 0; i < BOARD_HEIGHT; i++) {
        for(int j = 0; j < BOARD_WIDTH; j++) {
            int numAliveNeighbors = getNumAliveNeighbors(board, i, j);
            if(board[i][j] == 1) {
                if(numAliveNeighbors < 2 || numAliveNeighbors > 3) {
                    newBoard[i][j] = 0;
                } else {
                    newBoard[i][j] = 1;
                }
            } else {
                if(numAliveNeighbors == 3) {
                    newBoard[i][j] = 1;
                } else {
                    newBoard[i][j] = 0;
                }
            }
        }
    }
    for(int i = 0; i < BOARD_HEIGHT; i++) {
        for(int j = 0; j < BOARD_WIDTH; j++) {
            board[i][j] = newBoard[i][j];
        }
    }
}

int main() {
    int board[BOARD_HEIGHT][BOARD_WIDTH];

    initializeBoard(board);

    while(1) {
        system("clear"); // Clears the console screen.
        printBoard(board);
        updateBoard(board);
    }

    return 0;
}