//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

int main() {
    int nums[ROWS][COLS], visited[ROWS][COLS];
    int i, j, num, row, col, count, is_bingo;
    char option;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Generate the nums array with random numbers from 1 to 75
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            nums[i][j] = rand() % 75 + 1;
        }
    }

    // Set all elements of visited array to 0
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            visited[i][j] = 0;
        }
    }

    printf("Welcome to the Bingo simulator!\n");
    printf("Press any key to start the game.\n");
    getchar();

    do {
        count = 0;
        is_bingo = 0;

        // Generate a random number from 1 to 75
        num = rand() % 75 + 1;

        // Check if the number is in the nums array
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                if (nums[i][j] == num) {
                    visited[i][j] = 1;
                    count++;
                }
            }
        }

        // Print the number that was called
        printf("The number called is: %d\n", num);

        // Check if any row, column or diagonal has all 5 cells marked
        for (i = 0; i < ROWS; i++) {
            row = 1;
            col = 1;
            for (j = 0; j < COLS; j++) {
                row *= visited[i][j];
                col *= visited[j][i];
            }
            if (row || col) {
                is_bingo = 1;
            }
        }
        if (visited[0][0] && visited[1][1] && visited[2][2] && visited[3][3] && visited[4][4]) {
            is_bingo = 1;
        }
        if (visited[0][4] && visited[1][3] && visited[2][2] && visited[3][1] && visited[4][0]) {
            is_bingo = 1;
        }

        if (is_bingo) {
            printf("BINGO!! You have won the game in %d calls!\n", count);
        }
        else {
            printf("No bingo yet! Press any key for next call.\n");
            getchar();
        }

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &option);
        while (option != 'y' && option != 'n') {
            printf("Please enter valid option (y/n): ");
            scanf(" %c", &option);
        }

        // Reset the visited array if user wants to play again
        if (option == 'y') {
            for (i = 0; i < ROWS; i++) {
                for (j = 0; j < COLS; j++) {
                    visited[i][j] = 0;
                }
            }
        }

    } while (option == 'y');

    return 0;
}