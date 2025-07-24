//FormAI DATASET v1.0 Category: Game of Life ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Define the board size
#define ROWS 15
#define COLS 30

// Function to print the board
void print_board(int board[][COLS]) {
    system("clear"); // clear the console screen
    printf("Welcome to the Game of Life (or Death?)\n\n");
    printf("   "); // print top border

    for (int j = 0; j < COLS; j++) {
        printf("_");
    }

    printf("\n");

    for (int i = 0; i < ROWS; i++) {
        printf("  |"); // left border

        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 1) {
                printf("*"); // print alive cell
            } else {
                printf(" "); // print dead cell
            }
        }

        printf("|"); // right border
        printf("\n"); // new line
    }

    printf("   "); // bottom border

    for (int j = 0; j < COLS; j++) {
        printf("_");
    }

    printf("\n");
}

int main() {
    int board[ROWS][COLS] = {0}; // init all cells to 0

    // Add some random starting live cells
    board[5][6] = 1;
    board[6][6] = 1;
    board[7][6] = 1;
    board[7][5] = 1;
    board[7][4] = 1;

    print_board(board); // print the initial board

    for (int generation = 1; generation <= 100; generation++) { // iterate for 100 generations
        int new_board[ROWS][COLS] = {0}; // init new board for next generation

        // Check each cell
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                int neighbors = 0;

                // Check each neighbor cell
                for (int row_offset = -1; row_offset <= 1; row_offset++) {
                    for (int col_offset = -1; col_offset <= 1; col_offset++) {
                        int neighbor_i = i + row_offset;
                        int neighbor_j = j + col_offset;

                        // Skip the current cell itself
                        if (neighbor_i == i && neighbor_j == j)
                            continue;

                        // Check if the neighbor cell is inside the board
                        if (neighbor_i >= 0 && neighbor_i < ROWS && neighbor_j >= 0 && neighbor_j < COLS) {
                            if (board[neighbor_i][neighbor_j] == 1) {
                                neighbors++;
                            }
                        }
                    }
                }

                // Apply the rules of the Game of Life
                if (board[i][j] == 1) {
                    if (neighbors == 2 || neighbors == 3) {
                        new_board[i][j] = 1;
                    } else {
                        new_board[i][j] = 0;
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

        // Update the current board to the new board
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                board[i][j] = new_board[i][j];
            }
        }

        print_board(board); // print the new board for this generation
        printf("Generation %d\n", generation);
        printf("Press ENTER to continue to the next generation...\n");

        // Wait for user to press ENTER
        while (getchar() != '\n') {}

        // Add some randomness by swapping two random cells
        int random_row1 = rand() % ROWS;
        int random_col1 = rand() % COLS;
        int random_row2 = rand() % ROWS;
        int random_col2 = rand() % COLS;
        int temp = board[random_row1][random_col1];
        board[random_row1][random_col1] = board[random_row2][random_col2];
        board[random_row2][random_col2] = temp;

        print_board(board); // print board with swapped cells
        printf("Oops, the board has been scrambled by aliens! Press ENTER to unscramble...\n");

        // Wait for user to press ENTER
        while (getchar() != '\n') {}

        // Unscramble the board by swapping back the two random cells
        temp = board[random_row1][random_col1];
        board[random_row1][random_col1] = board[random_row2][random_col2];
        board[random_row2][random_col2] = temp;
    }

    printf("Game over! The civilization has lasted for 100 generations.\n");

    return 0;
}