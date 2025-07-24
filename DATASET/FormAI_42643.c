//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

// Function to check if a number is present in the Bingo Board
int checkNumber(int number, int board[ROWS][COLS]) {
    int row, col;
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            if (board[row][col] == number) {
                return 1;
            }
        }
    }
    return 0;
}

// Function to generate a random Bingo number
int generateNumber(int min, int max, int board[ROWS][COLS]) {
    int number;
    do {
        number = (rand() % (max - min + 1)) + min;
    } while (checkNumber(number, board));
    return number;
}

// Function to display the Bingo Board
void displayBoard(int board[ROWS][COLS]) {
    int row, col;
    printf("\tB\tI\tN\tG\tO\n");
    for (row = 0; row < ROWS; row++) {
        printf("%d", (row + 1));
        for (col = 0; col < COLS; col++) {
            printf("\t%d", board[row][col]);
        }
        printf("\n");
    }
}

int main() {
    int board[ROWS][COLS];
    int row, col;
    int min, max;
    int number;
    int count = 0;

    // Initialize the random number generator
    srand(time(NULL));

    // Fill the Bingo Board with random numbers
    min = 1;
    max = 15;
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            board[row][col] = generateNumber(min, max, board);
        }
        min += 15;
        max += 15;
    }

    // Display the Bingo Board
    displayBoard(board);

    // Play the Bingo game
    printf("\nLet's play Bingo!\n");
    while (count < 25) {
        printf("\nEnter a number between 1 and 75: ");
        scanf("%d", &number);
        if (number < 1 || number > 75) {
            printf("Invalid input. Please enter a number between 1 and 75.\n");
            continue;
        }
        if (checkNumber(number, board)) {
            for (row = 0; row < ROWS; row++) {
                for (col = 0; col < COLS; col++) {
                    if (board[row][col] == number) {
                        board[row][col] = -1;
                    }
                }
            }
            displayBoard(board);
            count++;
            if (count == 25) {
                printf("\nBINGO! You win!\n");
                break;
            }
            printf("\n%d is on the board! Keep going!\n", number);
        } else {
            printf("\n%d is not on the board. Try again.\n", number);
        }
    }

    return 0;
}