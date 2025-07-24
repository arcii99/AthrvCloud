//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_NUM 75

int main() {

    srand(time(0)); // Initializing random seed

    int board[ROWS][COLS] = {0}; // Initializing board with zeros
    int nums[MAX_NUM] = {0}; // Initializing array to keep track of called numbers
    int num_count = 0; // Initializing the count of called numbers to zero

    // Printing header
    printf("---------------------------------------------------\n");
    printf("\t\tBINGO SIMULATOR\n");
    printf("---------------------------------------------------\n\n");

    printf("Instructions:\nNumbers from 1 to %d will be called randomly.\nMark the numbers on your board as they are called.\nThe first person to have a row, column, or diagonal marked wins.\n\n", MAX_NUM);

    // Randomly calling numbers
    while (num_count < MAX_NUM) {

        int num = (rand() % MAX_NUM) + 1; // Generating random number
        int repeated = 0; // Initializing repeated flag to zero

        // Checking if the number has already been called
        for (int i = 0; i < num_count; i++) {
            if (nums[i] == num) {
                repeated = 1;
                break;
            }
        }

        // If number is not repeated, calling it and marking it on the board
        if (!repeated) {

            printf("Number called: %d\n", num); // Printing called number

            nums[num_count] = num; // Adding number to called numbers array
            num_count++; // Updating count of called numbers

            // Marking number on the board
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                    if (board[i][j] == num) {
                        board[i][j] = -num;
                        break;
                    }
                }
            }

            // Checking for winning conditions
            for (int i = 0; i < ROWS; i++) {
                int row_sum = 0, col_sum = 0, diag_sum_1 = 0, diag_sum_2 = 0;
                for (int j = 0; j < COLS; j++) {
                    row_sum += board[i][j];
                    col_sum += board[j][i];
                    if (i == j) diag_sum_1 += board[i][j];
                    if (i + j == ROWS - 1) diag_sum_2 += board[i][j];
                }
                if (row_sum == -5*num || col_sum == -5*num || diag_sum_1 == -5*num || diag_sum_2 == -5*num) {
                    printf("\n\nBINGO!!!\n\n");
                    return 0;
                }
            }
        }
    }

    // If all numbers are called and no one wins, announcing the game as a tie
    printf("\n\nNo one wins, it's a tie!\n\n");

    return 0;
}