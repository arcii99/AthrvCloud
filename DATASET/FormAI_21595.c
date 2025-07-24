//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time
    int nums[ROWS][COLS] = {0};

    // Generate random numbers for the game board
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            if (i == 2 && j == 2) { // Skip center cell of board
                continue;
            }
            int num = rand() % 15 + j*15 + 1; // Generate number according to column
            nums[i][j] = num;
            // Check for duplicate numbers and regenerate if necessary
            for (int x=0; x<i; x++) {
                for (int y=0; y<COLS; y++) {
                    if (nums[x][y] == num) {
                        num = rand() % 15 + j*15 + 1;
                        nums[i][j] = num;
                        x = 0; // Restart check for duplicates
                        break;
                    }
                }
            }
        }
    }

    // Print out the game board
    printf("     B   I   N   G   O\n");
    for (int i=0; i<ROWS; i++) {
        printf("%d  ", i+1);
        for (int j=0; j<COLS; j++) {
            printf("%2d  ", nums[i][j]);
        }
        printf("\n");
    }

    // Play the game
    printf("\n");
    printf("Let's play Bingo!\n");
    int picked[ROWS*COLS-1] = {0};
    int num_picked = 0;
    while (num_picked < ROWS*COLS-1) {
        printf("Pick a number: ");
        int pick;
        scanf("%d", &pick);
        if (pick < 1 || pick > 75) {
            printf("Invalid number.\n");
            continue;
        }
        for (int i=0; i<ROWS; i++) {
            for (int j=0; j<COLS; j++) {
                if (nums[i][j] == pick) {
                    nums[i][j] = 0;
                    picked[num_picked] = pick;
                    num_picked++;
                    break;
                }
            }
        }
        if (num_picked == ROWS*COLS-1) {
            printf("You've got Bingo!\n");
            return 0;
        }
        printf("No match, try again.\n");
    }

    return 0;
}