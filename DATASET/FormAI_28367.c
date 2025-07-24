//FormAI DATASET v1.0 Category: Game of Life ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initialize_board(int board[][20]) {
    // Initialize board randomly
    srand(time(NULL));
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

int count_neighbors(int board[][20], int row, int col) {
    // Count number of live neighbors around a cell
    int count = 0;
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            if (i >= 0 && i < 20 && j >= 0 && j < 20) {
                if (i != row || j != col) {
                    if (board[i][j] == 1) {
                        count++;
                    }
                }
            }
        }
    }
    return count;
}

void update_board(int board[][20]) {
    // Update the board based on Game of Life rules
    int new_board[20][20];
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            int neighbors = count_neighbors(board, i, j);
            if (board[i][j] == 1) {
                if (neighbors < 2 || neighbors > 3) {
                    new_board[i][j] = 0;
                } else {
                    new_board[i][j] = 1;
                }
            } else {
                if (neighbors == 3) {
                    new_board[i][j] = 1;
                } else {
                    new_board[i][j] = 0;
                }
            }
        }
    }
    // Copy new board to old board
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

void print_board(int board[][20]) {
    // Print the board
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (board[i][j] == 1) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int main() {
    int board[20][20];
    initialize_board(board);
    printf("Welcome to the mind-bending version of the Game of Life!\n");
    printf("The cells in this universe are not simply 0 or 1, they can also be -1 or 2 depending on how you interact with them...\n");
    printf("Each turn, you can add a cell by inputting the row and column coordinates separated by a space.\n");
    printf("If the cell is not alive (0), it will become -1, otherwise it will become 2.\n");
    printf("After adding your cell, the Game of Life will proceed to the next turn based on the rules below...\n\n");

    printf("Rules of the Game of Life:\n");
    printf("- Any live cell with fewer than two live neighbors dies, as if caused by underpopulation.\n");
    printf("- Any live cell with more than three live neighbors dies, as if by overcrowding.\n");
    printf("- Any live cell with two or three live neighbors lives on to the next generation.\n");
    printf("- Any dead cell with exactly three live neighbors becomes a live cell.\n\n");

    while (1) {
        printf("Current board:\n");
        print_board(board);
        printf("Enter coordinates to add a cell (e.g. 1 2) or enter -1 -1 to exit: ");
        int row, col;
        scanf("%d %d", &row, &col);
        if (row == -1 && col == -1) {
            printf("Goodbye!\n");
            break;
        }
        if (row < 0 || row > 19 || col < 0 || col > 19) {
            printf("Invalid coordinates!\n");
        } else {
            if (board[row][col] == 0) {
                board[row][col] = -1;
                printf("Added cell at (%d, %d).\n\n", row, col);
            } else {
                board[row][col] = 2;
                printf("Changed existing cell at (%d, %d).\n\n", row, col);
            }
            update_board(board);
        }
    }
    return 0;
}