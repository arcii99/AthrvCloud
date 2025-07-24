//FormAI DATASET v1.0 Category: Memory Game ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void shuffle(int *array, size_t n) {
    if (n > 1) {
        size_t i;
        for (i = 0; i < n - 1; i++) {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

int main() {
    int grid[ROWS][COLS];
    int nums[ROWS* COLS / 2];
    int matches[ROWS* COLS / 2];
    int count = 1;
    int num_of_matches = 0;

    // initialize nums array with numbers from 1 to ROWS*COLS/2
    for (int i = 0; i < ROWS* COLS / 2; i++) {
        nums[i] = count;
        count++;
    }

    // initialize matches array with zeros
    for (int i = 0; i < ROWS* COLS / 2; i++) {
        matches[i] = 0;
    }

    // shuffle nums array
    srand(time(NULL));
    shuffle(nums, ROWS*COLS/2);

    // populate grid with shuffled nums array 
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = nums[(i * COLS + j) / 2];
        }
    }

    // print grid
    printf("Welcome to Memory Game!\n");
    printf("Match pairs of numbers to win.\n");
    printf("\n");

    while (num_of_matches < ROWS* COLS / 2) {
        printf("   ");
        for (int i = 1; i <= COLS; i++) {
            printf("%d  ", i);
        }
        printf("\n");
        for (int i = 0; i <= ROWS; i++) {
            for (int j = 0; j <= COLS; j++) {
                if (i == 0 && j == 0) {
                    printf("   ");
                }
                else if (j == 0) {
                    printf("%d", i);
                    printf("  ");
                }
                else if (i == 0) {
                    printf("---");
                }
                else if (grid[i - 1][j - 1] == 0) {
                    printf("   ");
                }
                else if (matches[(grid[i - 1][j - 1]) - 1] == 1) {
                    printf(" %d ", grid[i-1][j-1]);
                }
                else {
                    printf("[ ]");
                }
            }
            printf("\n");
        }
        printf("\n");

        // ask user for two coordinates to guess for possible match
        int x1, y1, x2, y2;
        printf("Enter two coordinates to guess for a possible match.\n");
        printf("Enter first coordinate(x, y): ");
        scanf("%d %d", &x1, &y1);
        printf("Enter second coordinate(x, y): ");
        scanf("%d %d", &x2, &y2);

        if (grid[x1-1][y1-1] == grid[x2-1][y2-1]) {
            printf("Matched!\n");
            matches[grid[x1 - 1][y1 - 1] - 1] = 1;
            grid[x1 - 1][y1 - 1] = 0;
            grid[x2 - 1][y2 - 1] = 0;
            num_of_matches++;
        }
        else {
            printf("Not a match. Try again.\n");
        }
        printf("\n");
    }
    printf("Congratulations, you won!\n");
    return 0;
}