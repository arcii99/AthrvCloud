//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define TOTAL_NUMS 25

int main() {
    int bingo[ROWS][COLS] = { 0 };
    int nums[TOTAL_NUMS] = { 0 };
    int chosen_nums[TOTAL_NUMS] = { 0 };
    int count = 0;

    // Initialize srand with current time to generate random numbers
    srand(time(NULL));

    // Initialize the array with random numbers
    for (int i = 0; i < TOTAL_NUMS; i++) {
        nums[i] = i + 1;
    }

    // Shuffle the array
    for (int i = 0; i < TOTAL_NUMS; i++) {
        int j = rand() % TOTAL_NUMS;
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    // Print the shuffled array
    for (int i = 0; i < TOTAL_NUMS; i++) {
        printf("%2d ", nums[i]);
        if ((i + 1) % 5 == 0) printf("\n");
    }

    // Start the game
    printf("\n\nGame started!\n");
    while (count < TOTAL_NUMS) {
        int num = nums[count];
        printf("\n\nCurrent number: %d\n", num);
        
        // Find the location of the number in the array
        int row = -1, col = -1;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (bingo[i][j] == num) {
                    row = i;
                    col = j;
                    break;
                }
            }
        }

        // If number is found in the array, mark it as chosen
        if (row != -1 && col != -1) {
            chosen_nums[count] = num;
            printf("Number %d found in row %d, column %d!\n", num, row+1, col+1);
            count++;
        }
        else {
            printf("Number %d not found in the array!\n", num);
        }

        // Check if any row, column or diagonal is complete
        int complete = 0;
        for (int i = 0; i < ROWS; i++) {
            int row_complete = 1;
            int col_complete = 1;
            for (int j = 0; j < COLS; j++) {
                if (bingo[i][j] && !chosen_nums[bingo[i][j]-1]) {
                    row_complete = 0;
                }
                if (bingo[j][i] && !chosen_nums[bingo[j][i]-1]) {
                    col_complete = 0;
                }
            }
            if (row_complete) {
                printf("\n***** Row %d complete! *****\n", i+1);
                complete = 1;
                break;
            }
            if (col_complete) {
                printf("\n***** Column %d complete! *****\n", i+1);
                complete = 1;
                break;
            }
        }
        if (!complete) {
            int diagonal1_complete = 1;
            int diagonal2_complete = 1;
            for (int i = 0; i < ROWS; i++) {
                if (bingo[i][i] && !chosen_nums[bingo[i][i]-1]) {
                    diagonal1_complete = 0;
                }
                if (bingo[i][ROWS-i-1] && !chosen_nums[bingo[i][ROWS-i-1]-1]) {
                    diagonal2_complete = 0;
                }
            }
            if (diagonal1_complete) {
                printf("\n***** Diagonal 1 complete! *****\n");
                complete = 1;
            }
            if (diagonal2_complete) {
                printf("\n***** Diagonal 2 complete! *****\n");
                complete = 1;
            }
        }
        if (complete) break;

        // Mark the number in the array
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (bingo[i][j] == num) {
                    bingo[i][j] = 0;
                    break;
                }
            }
        }
    }
    // Print the final array
    printf("\n\nFinal array:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%2d ", bingo[i][j]);
        }
        printf("\n");
    }
    return 0;
}