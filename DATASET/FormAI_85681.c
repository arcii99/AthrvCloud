//FormAI DATASET v1.0 Category: Game of Life ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 10 // Size of the game board

bool isValid(int row, int col) {
    return row >= 0 && row < SIZE && col >= 0 && col < SIZE;
}

int countNeighbors(int **board, int row, int col) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue; // Don't check self
            int r = row + i;
            int c = col + j;
            if (isValid(r, c) && board[r][c] == 1) {
                count++;
            }
        }
    }
    return count;
}

void printBoard(int **board) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 1) {
                printf("O ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int **board = (int **) malloc(SIZE * sizeof(int *));
    for (int i = 0; i < SIZE; i++) {
        board[i] = (int *) malloc(SIZE * sizeof(int));
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = rand() % 2; // Randomly fill board with 0 or 1
        }
    }

    printf("Initial board:\n");
    printBoard(board);

    int **newBoard = (int **) malloc(SIZE * sizeof(int *));
    for (int i = 0; i < SIZE; i++) {
        newBoard[i] = (int *) malloc(SIZE * sizeof(int));
    }

    for (int generation = 0; generation < 10; generation++) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                int neighbors = countNeighbors(board, i, j);
                if (board[i][j] == 1) { // If cell is alive
                    if (neighbors < 2 || neighbors > 3) {
                        newBoard[i][j] = 0; // Cell dies
                    } else {
                        newBoard[i][j] = 1; // Cell survives
                    }
                } else { // If cell is dead
                    if (neighbors == 3) {
                        newBoard[i][j] = 1; // Cell becomes alive
                    } else {
                        newBoard[i][j] = 0; // Cell stays dead
                    }
                }
            }
        }
        // Swap board and newBoard
        int **temp = board;
        board = newBoard;
        newBoard = temp;

        printf("Generation %d:\n", generation + 1);
        printBoard(board);
    }

    free(board);
    free(newBoard);

    return 0;
}