//FormAI DATASET v1.0 Category: Memory Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void printBoard(char board[ROWS][COLS], int flipped[ROWS][COLS]) {
    printf("    1   2   3   4\n");
    printf("  +---+---+---+---+\n");
    char rowChar = 'A';
    for (int row = 0; row < ROWS; row++) {
        printf("%c |", rowChar++);
        for (int col = 0; col < COLS; col++) {
            if (flipped[row][col] == 1) {
                printf(" %c |", board[row][col]);
            } else {
                printf("   |");
            }
        }
        printf("\n");
        printf("  +---+---+---+---+\n");
    }
}

void initializeBoard(char board[ROWS][COLS]) {
    // The characters to use on the board
    char characters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    // Calculate the number of pairs needed
    int numPairs = ROWS * COLS / 2;

    // Initialize the random number generator
    srand(time(0));

    // Place each character twice on the board in a random position
    for (int pairNum = 1; pairNum <= numPairs; pairNum++) {
        char pairChar = characters[pairNum - 1];
        for (int pairIndex = 0; pairIndex < 2; pairIndex++) {
            int row, col;
            do {
                row = rand() % ROWS;
                col = rand() % COLS;
            } while (board[row][col] != ' ');
            board[row][col] = pairChar;
        }
    }
}

int main() {
    char board[ROWS][COLS];
    int flipped[ROWS][COLS] = {0};
    int numFlipped = 0;

    // Initialize the board to all spaces
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            board[row][col] = ' ';
        }
    }

    // Initialize the game board
    initializeBoard(board);

    // Play the game
    char input[10];
    char rowChar1, rowChar2;
    int row1, row2, col1, col2;
    do {
        printBoard(board, flipped);
        printf("Enter the coordinates of two cards to flip (e.g. A1 B2): ");
        scanf("%s", input);

        rowChar1 = input[0];
        col1 = input[1] - '1';
        rowChar2 = input[3];
        col2 = input[4] - '1';

        row1 = rowChar1 - 'A';
        row2 = rowChar2 - 'A';

        // Flip the cards
        flipped[row1][col1] = 1;
        flipped[row2][col2] = 1;

        // Check if they match
        if (board[row1][col1] != board[row2][col2]) {
            // Wait a bit so the player can see the cards
            printf("\nSorry, those don't match.\n\n");
            for (int i = 0; i < 100000000; i++) {}
            // Flip the cards back over
            flipped[row1][col1] = 0;
            flipped[row2][col2] = 0;
        } else {
            printf("\nMatch found!\n\n");
            numFlipped += 2;
        }
    } while (numFlipped < ROWS * COLS);

    printf("Congratulations, you won!\n");
    return 0;
}