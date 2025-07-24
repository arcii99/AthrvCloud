//FormAI DATASET v1.0 Category: Game of Life ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50 
#define HEIGHT 20 

// Function to initialize the game board
void initializeBoard(int board[HEIGHT][WIDTH]) {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

// Function to print the game board
void printBoard(int board[HEIGHT][WIDTH]) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%c ", board[i][j] ? '*' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

// Function to count the number of alive neighbors
int numNeighbors(int board[HEIGHT][WIDTH], int x, int y) {
    int i, j;
    int count = 0;
    for (i = -1; i <= 1; i++) {
        for (j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;
            int row = (x + i + HEIGHT) % HEIGHT;
            int col = (y + j + WIDTH) % WIDTH;
            count += board[row][col];
        }
    }
    return count;
}

// Function to update the board based on the rules of the game
void updateBoard(int board[HEIGHT][WIDTH]) {
    int newBoard[HEIGHT][WIDTH];
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            int neighbors = numNeighbors(board, i, j);
            if (board[i][j] && (neighbors == 2 || neighbors == 3)) {
                newBoard[i][j] = 1;
            } else if (!board[i][j] && neighbors == 3) {
                newBoard[i][j] = 1;
            } else {
                newBoard[i][j] = 0;
            }
        }
    }
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            board[i][j] = newBoard[i][j];
        }
    }
}

int main() {
    int board[HEIGHT][WIDTH];
    initializeBoard(board);
    printBoard(board);
    for (int i = 0; i < 100; i++) {
        updateBoard(board);
        printBoard(board);
    }
    return 0;
}