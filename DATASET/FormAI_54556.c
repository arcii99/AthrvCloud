//FormAI DATASET v1.0 Category: Memory Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

int main() {

    int gameBoard[ROWS][COLS];
    int randomNumbers[ROWS * COLS / 2];
    int row, col, index, count, matches;
    char playAgain;

    srand(time(NULL));

    printf("\t\tC Memory Game\n\n");
    printf("The objective of the game is to match all the pairs of numbers\n");
    printf("You will be shown the game board with numbers hidden\n");
    printf("You can select two cells at a time to reveal the numbers\n");
    printf("If the numbers match, they will remain revealed\n");
    printf("If they don't match, they will be hidden again\n");
    printf("You win the game when all the numbers are matched\n\n");

    do {
        // Initialize game board
        for (row = 0; row < ROWS; row++) {
            for (col = 0; col < COLS; col++) {
                gameBoard[row][col] = 0;
            }
        }

        // Generate random numbers for game board
        count = 0;
        while (count < ROWS * COLS / 2) {
            index = rand() % (ROWS * COLS / 2);
            if (randomNumbers[index] < 2) {
                randomNumbers[index]++;
                count++;
            }
        }

        // Assign random numbers to game board
        count = 0;
        for (row = 0; row < ROWS; row++) {
            for (col = 0; col < COLS; col++) {
                if (count < ROWS * COLS / 2) {
                    while (randomNumbers[count] == 0) {
                        count++;
                    }
                    gameBoard[row][col] = count + 1;
                    randomNumbers[count]--;
                }
            }
        }

        // Play game
        matches = 0;
        do {
            // Display game board
            printf("\n   1  2  3  4\n");
            printf("  -------------\n");
            for (row = 0; row < ROWS; row++) {
                printf("%c ", 'A' + row);
                for (col = 0; col < COLS; col++) {
                    if (gameBoard[row][col] == 0) {
                        printf("|  ");
                    } else {
                        printf("|%2d", gameBoard[row][col]);
                    }
                }
                printf("|\n");
                printf("  -------------\n");
            }

            // Get user input
            int r1, c1, r2, c2;
            printf("\nEnter the coordinates of the first cell: ");
            scanf("%d%d", &r1, &c1);
            printf("Enter the coordinates of the second cell: ");
            scanf("%d%d", &r2, &c2);

            // Check if cells contain matching numbers
            if (gameBoard[r1-1][c1-1] == gameBoard[r2-1][c2-1]) {
                printf("\nMatch!\n");
                gameBoard[r1-1][c1-1] = 0;
                gameBoard[r2-1][c2-1] = 0;
                matches++;
            } else {
                printf("\nNo match!\n");
                printf("Press enter to continue.\n");
                getchar();
                getchar();
            }
        } while (matches < ROWS * COLS / 2);

        printf("\nCongratulations! You won the game!\n");
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);

    } while (playAgain == 'y' || playAgain == 'Y');

    printf("\nThanks for playing! Goodbye!\n");

    return 0;
}