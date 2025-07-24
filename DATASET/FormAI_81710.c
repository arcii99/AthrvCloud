//FormAI DATASET v1.0 Category: Game of Life ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Define the size of the game board
#define BOARD_HEIGHT 15
#define BOARD_WIDTH 30

// Define the ages of the cells
#define YOUTH '■'
#define ADULT '█'
#define SENIOR '▒'

// Function to print the board
void printBoard(char board[BOARD_HEIGHT][BOARD_WIDTH]) {
    printf("\n");
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to update the board
void updateBoard(char board[BOARD_HEIGHT][BOARD_WIDTH], int age[BOARD_HEIGHT][BOARD_WIDTH]) {
    char newBoard[BOARD_HEIGHT][BOARD_WIDTH];
    int newAge[BOARD_HEIGHT][BOARD_WIDTH];

    // Loop through each cell and update it
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            int neighbors = 0;

            // Check the neighbors of the cell
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    int x = i + k;
                    int y = j + l;

                    if (x < 0) {
                        x = BOARD_HEIGHT - 1;
                    } else if (x >= BOARD_HEIGHT) {
                        x = 0;
                    }

                    if (y < 0) {
                        y = BOARD_WIDTH - 1;
                    } else if (y >= BOARD_WIDTH) {
                        y = 0;
                    }

                    if (board[x][y] != ' ') {
                        neighbors++;
                    }
                }
            }

            // Update the cell based on the number of neighbors
            if (board[i][j] != ' ') {
                if (neighbors < 2 || neighbors > 3) {
                    newBoard[i][j] = ' ';
                    newAge[i][j] = 0;
                } else {
                    newAge[i][j] = age[i][j] + 1;
                    if (newAge[i][j] >= 10 && newAge[i][j] < 20) {
                        newBoard[i][j] = YOUTH;
                    } else if (newAge[i][j] >= 20 && newAge[i][j] < 30) {
                        newBoard[i][j] = ADULT;
                    } else if (newAge[i][j] >= 30) {
                        newBoard[i][j] = SENIOR;
                    } else {
                        newBoard[i][j] = board[i][j];
                    }
                }
            } else {
                if (neighbors == 3) {
                    newBoard[i][j] = YOUTH;
                    newAge[i][j] = 1;
                } else {
                    newBoard[i][j] = ' ';
                    newAge[i][j] = 0;
                }
            }
        }
    }

    // Copy the new board and age to the old board and age
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            board[i][j] = newBoard[i][j];
            age[i][j] = newAge[i][j];
        }
    }
}

int main() {
    char board[BOARD_HEIGHT][BOARD_WIDTH];
    int age[BOARD_HEIGHT][BOARD_WIDTH];

    // Seed the rand function
    srand(time(NULL));

    // Initialize the board with random cells
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            if (rand() % 2 == 0) {
                board[i][j] = ' ';
                age[i][j] = 0;
            } else {
                board[i][j] = YOUTH;
                age[i][j] = 1;
            }
        }
    }

    // Loop through and update the board
    while (1) {
        system("clear");
        printBoard(board);
        updateBoard(board, age);
        usleep(200000);
    }

    return 0;
}