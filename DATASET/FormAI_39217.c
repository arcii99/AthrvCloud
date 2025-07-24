//FormAI DATASET v1.0 Category: Game of Life ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

// Generate the initial board
void generate_board(int board[ROWS][COLS])
{
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

// Count the number of live neighbors for a given cell
int count_neighbors(int board[ROWS][COLS], int row, int col)
{
    int i, j, count = 0;

    // Check surrounding cells
    for (i = row - 1; i <= row + 1; i++) {
        for (j = col - 1; j <= col + 1; j++) {
            if (i >= 0 && i < ROWS && j >= 0 && j < COLS && board[i][j] == 1) {
                count++;
            }
        }
    }

    // Subtract current cell if it's alive
    if (board[row][col] == 1) {
        count--;
    }

    return count;
}

// Update the board based on the rules of the Game of Life
void update_board(int board[ROWS][COLS])
{
    int new_board[ROWS][COLS];
    int i, j, neighbors;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            neighbors = count_neighbors(board, i, j);

            if (board[i][j] == 1) {
                // Cell is alive
                if (neighbors < 2) {
                    // Underpopulation, cell dies
                    new_board[i][j] = 0;
                } else if (neighbors > 3) {
                    // Overpopulation, cell dies
                    new_board[i][j] = 0;
                } else {
                    // Just right, cell lives
                    new_board[i][j] = board[i][j];
                }
            } else {
                // Cell is dead
                if (neighbors == 3) {
                    // Reproduction, cell comes to life
                    new_board[i][j] = 1;
                } else {
                    // No change
                    new_board[i][j] = board[i][j];
                }
            }
        }
    }

    // Copy new board back to original board
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

// Print the board to the console
void print_board(int board[ROWS][COLS])
{
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j] == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main()
{
    int board[ROWS][COLS];

    // Seed random number generator
    srand(time(NULL));

    // Generate initial board
    generate_board(board);

    // Print initial board
    print_board(board);

    // Loop until user terminates program
    while (1) {
        // Wait for user input
        printf("Press enter to continue...\n");
        getchar();

        // Update board
        update_board(board);

        // Print updated board
        print_board(board);
    }

    return 0;
}