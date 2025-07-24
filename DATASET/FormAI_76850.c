//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

// Function to check if a number is already present in the Bingo board
int checkDuplicate(int arr[ROWS][COLS], int num)
{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (arr[i][j] == num) {
                return 1;
            }
        }
    }
    return 0;
}

// Function to check if any row, column or diagonal is completed
int checkBingo(int arr[ROWS][COLS])
{
    int count = 0;

    // Check rows
    for (int i = 0; i < ROWS; i++) {
        count = 0;
        for (int j = 0; j < COLS; j++) {
            if (arr[i][j] == -1) {
                count++;
            }
        }
        if (count == COLS) {
            printf("BINGO! You have completed row %d\n", i+1);
            return 1;
        }
    }

    // Check columns
    for (int i = 0; i < COLS; i++) {
        count = 0;
        for (int j = 0; j < ROWS; j++) {
            if (arr[j][i] == -1) {
                count++;
            }
        }
        if (count == ROWS) {
            printf("BINGO! You have completed column %d\n", i+1);
            return 1;
        }
    }

    // Check diagonal 1 (top-left to bottom-right)
    count = 0;
    for (int i = 0; i < ROWS; i++) {
        if (arr[i][i] == -1) {
            count++;
        }
    }
    if (count == ROWS) {
        printf("BINGO! You have completed diagonal 1\n");
        return 1;
    }

    // Check diagonal 2 (top-right to bottom-left)
    count = 0;
    for (int i = 0; i < ROWS; i++) {
        if (arr[i][COLS-i-1] == -1) {
            count++;
        }
    }
    if (count == ROWS) {
        printf("BINGO! You have completed diagonal 2\n");
        return 1;
    }

    return 0;
}

int main()
{
    int nums[75];
    for (int i = 0; i < 75; i++) {
        nums[i] = i+1;
    }

    srand(time(NULL));
    int board[ROWS][COLS];
    int index;

    // Initialize the Bingo board with -1
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = -1;
        }
    }

    while (!checkBingo(board)) {
        // Generate a random number between 1 and 75
        index = rand() % 75;
        while (checkDuplicate(board, nums[index])) {
            index = rand() % 75;
        }

        // Mark the number on the Bingo board
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == nums[index]) {
                    board[i][j] = -1;
                }
            }
        }

        // Add the number to the board
        int added = 0;
        while (!added) {
            index = rand() % 25;
            if (board[index/5][index%5] == -1) {
                board[index/5][index%5] = nums[index];
                added = 1;
            }
        }

        // Print the updated Bingo board
        printf("\n");
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == -1) {
                    printf("   ");
                } else {
                    printf("%2d ", board[i][j]);
                }
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}