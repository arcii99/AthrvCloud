//FormAI DATASET v1.0 Category: Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10  // number of rows in the board
#define COLS 10  // number of columns in the board
#define BOMBS 10 // number of bombs on the board

int main()
{
    // Initialize variables
    int board[ROWS][COLS];  // the playing board
    int visited[ROWS][COLS];  // keep track of visited cells
    int i, j, k, row, col, bombs_left, x, y;
    char action;

    // Seed random number generator
    srand(time(NULL));

    // Set all cells to zero and initialize visited array to false
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = 0;
            visited[i][j] = 0;
        }
    }

    // Place bombs randomly on board
    bombs_left = BOMBS;
    while (bombs_left > 0) {
        row = rand() % ROWS;
        col = rand() % COLS;
        if (board[row][col] != -1) {
            board[row][col] = -1;
            bombs_left--;
        }
    }

    // Set cell values adjacent to bombs
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j] == -1) {
                for (k = -1; k <= 1; k++) {
                    for (x = -1; x <= 1; x++) {
                        if (i+k >= 0 && i+k < ROWS && j+x >= 0 && j+x < COLS) {
                            if (board[i+k][j+x] != -1) {
                                board[i+k][j+x]++;
                            }
                        }
                    }
                }
            }
        }
    }

    // Print empty board for debugging purposes
    /*
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    */

    // Begin game loop
    printf("Welcome to Minesweeper!\n\n");
    while (1) {
        // Print current state of board
        printf("    ");
        for (i = 0; i < ROWS; i++) {
            printf("%d ", i+1);
        }
        printf("\n");
        printf("    ");
        for (i = 0; i < ROWS; i++) {
            printf("- ");
        }
        printf("\n");
        for (i = 0; i < ROWS; i++) {
            printf("%c | ", 'A' + i);
            for (j = 0; j < COLS; j++) {
                if (visited[i][j]) {
                    printf("%d ", board[i][j]);
                } else {
                    printf(". ");
                }
            }
            printf("\n");
        }

        // Prompt player for action
        printf("Enter an action (r = reveal, f = flag, q = quit): ");
        scanf(" %c", &action);

        // Handle player action
        if (action == 'q') {
            printf("Goodbye!\n");
            break;
        } else if (action == 'f') {
            printf("Enter row and column (e.g. A1): ");
            scanf(" %c%d", &row, &col);
            visited[row-'A'][col-1] = 1;
        } else if (action == 'r') {
            printf("Enter row and column (e.g. A1): ");
            scanf(" %c%d", &row, &col);
            if (board[row-'A'][col-1] == -1) {
                printf("You lose!\n");
                break;
            } else {
                visited[row-'A'][col-1] = 1;
            }
        } else {
            printf("Invalid action. Please enter r, f, or q.\n");
        }
    }

    return 0;
}