//FormAI DATASET v1.0 Category: Memory Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void print_board(int board[ROWS][COLS], int reveal[ROWS][COLS]) {
    printf("   1  2  3  4\n");
    printf(" _____________\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%c |", 'A' + i);
        for (int j = 0; j < COLS; j++) {
            if (reveal[i][j]) {
                printf(" %2d", board[i][j]);
            } else {
                printf("  X");
            }
        }
        printf("\n");
    }
}

int main(void) {
    int board[ROWS][COLS];
    int reveal[ROWS][COLS] = {0};
    int pairs_found = 0;
    srand(time(NULL));

    // Generate random pairs of numbers
    for (int i = 1; i <= ROWS * COLS / 2; i++) {
        for (int j = 0; j < 2; j++) {
            int row, col;
            do {
                row = rand() % ROWS;
                col = rand() % COLS;
            } while (board[row][col] != 0);
            board[row][col] = i;
        }
    }

    printf("Welcome to the Memory Game!\n\n");
    printf("The objective of the game is to find all the pairs of numbers in the least attempts possible.\n");
    printf("Enter two coordinates (e.g. A1 B2) to reveal the numbers at those positions.\n");
    printf("If the numbers match, they will both remain revealed.\n");
    printf("If not, they will be covered again.\n");
    printf("The game ends when all pairs have been found.\n\n");

    // Game loop
    while (pairs_found < ROWS * COLS / 2) {
        print_board(board, reveal);

        // Get user input
        char row1, row2;
        int col1, col2;
        printf("Enter two coordinates: ");
        scanf(" %c%d %c%d", &row1, &col1, &row2, &col2);
        int r1 = row1 - 'A';
        int r2 = row2 - 'A';
        int c1 = col1 - 1;
        int c2 = col2 - 1;

        // Check if coordinates are valid
        if (r1 < 0 || r1 >= ROWS || r2 < 0 || r2 >= ROWS ||
            c1 < 0 || c1 >= COLS || c2 < 0 || c2 >= COLS) {
            printf("Invalid coordinates. Try again.\n");
            continue;
        }

        // Check if coordinates are not already revealed
        if (reveal[r1][c1] || reveal[r2][c2]) {
            printf("Those coordinates have already been revealed. Try again.\n");
            continue;
        }

        // Reveal numbers at coordinates
        reveal[r1][c1] = 1;
        reveal[r2][c2] = 1;
        print_board(board, reveal);

        // Check if numbers match
        if (board[r1][c1] == board[r2][c2]) {
            pairs_found++;
            printf("Match! You found %d/%d pairs.\n", pairs_found, ROWS * COLS / 2);
        } else {
            reveal[r1][c1] = 0;
            reveal[r2][c2] = 0;
            printf("No match. Try again.\n");
        }
    }

    printf("Congratulations! You found all the pairs in %d attempts.\n", pairs_found * 2);

    return 0;
}