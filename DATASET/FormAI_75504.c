//FormAI DATASET v1.0 Category: Game of Life ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 40
#define HEIGHT 20

void clearScreen() {
    system("clear"); // clear screen
    fflush(stdout); // flush output buffer
}

void initBoard(int board[][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            board[i][j] = rand() % 2; // randomly initialize cells as alive or dead
        }
    }
}

int countNeighbors(int board[][WIDTH], int row, int col) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;
            int r = (row + i + HEIGHT) % HEIGHT;
            int c = (col + j + WIDTH) % WIDTH;
            count += board[r][c];
        }
    }
    return count;
}

void updateBoard(int board[][WIDTH]) {
    int newBoard[HEIGHT][WIDTH];
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int neighbors = countNeighbors(board, i, j);
            if (board[i][j] == 0 && neighbors == 3) {
                newBoard[i][j] = 1; // dead cell becomes alive if it has 3 neighbors
            } else if (board[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                newBoard[i][j] = 0; // alive cell dies if it has less than 2 or more than 3 neighbors
            } else {
                newBoard[i][j] = board[i][j]; // keep the same state for all other cases
            }
        }
    }
    // copy the new board to the old board
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            board[i][j] = newBoard[i][j];
        }
    }
}

void printBoard(int board[][WIDTH]) {
    printf("Press Ctrl+C to exit.\n\n");
    while (1) {
        // clear screen and print board
        clearScreen();
        printf("                            THE GAME OF LIFE\n");
        printf("                              Version 1.0\n\n");
        for (int i = 0; i < HEIGHT; i++) {
            printf("                              ");
            for (int j = 0; j < WIDTH; j++) {
                printf("%c", board[i][j] ? '*' : ' ');
            }
            printf("\n");
        }
        printf("\n");
        updateBoard(board); // update the board
    }
}

int main() {
    int board[HEIGHT][WIDTH];
    srand(time(NULL)); // seed the random number generator
    initBoard(board); // initialize the board with random cells
    printBoard(board); // print the board
    return 0;
}