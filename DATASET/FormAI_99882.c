//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 5
#define COL 5
#define MAX_NUM 25

int main() {
    // Initialize the game board
    int board[ROW][COL] = { { 0 } };

    // Initialize the random number generator
    srand((unsigned int)time(NULL));

    // Generate unique numbers for each cell
    int nums[MAX_NUM] = { 0 };
    for (int i = 0; i < MAX_NUM; i++) {
        nums[i] = i + 1;
    }
    for (int i = MAX_NUM - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    // Populate the board with unique numbers
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            board[i][j] = nums[i * COL + j];
        }
    }

    // Print the game board
    printf("B I N G O\n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }

    // Play the game
    int count = 0;
    int nums_picked[MAX_NUM] = { 0 };
    while (count < MAX_NUM) {
        // Pick a number randomly
        int num = rand() % MAX_NUM + 1;

        // Check if the number has been picked before
        int found = 0;
        for (int i = 0; i < count; i++) {
            if (nums_picked[i] == num) {
                found = 1;
                break;
            }
        }
        if (found) {
            continue;
        }

        // Mark the cell if it contains the picked number
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                if (board[i][j] == num) {
                    board[i][j] = 0;
                    count++;
                    nums_picked[count - 1] = num;
                    break;
                }
            }
        }

        // Print the picked number and the updated board
        printf("The picked number is %d.\n", num);
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                if (board[i][j] == 0) {
                    printf("   ");
                } else {
                    printf("%2d ", board[i][j]);
                }
            }
            printf("\n");
        }

        // Check if any row, column, or diagonal is complete
        for (int i = 0; i < ROW; i++) {
            int row_sum = 0;
            int col_sum = 0;
            for (int j = 0; j < COL; j++) {
                row_sum += board[i][j];
                col_sum += board[j][i];
            }
            if (row_sum == 0) {
                printf("Row %d is complete!\n", i + 1);
            }
            if (col_sum == 0) {
                printf("Column %d is complete!\n", i + 1);
            }
        }
        int diag_sum1 = board[0][0] + board[1][1] + board[2][2] + board[3][3] + board[4][4];
        int diag_sum2 = board[0][4] + board[1][3] + board[2][2] + board[3][1] + board[4][0];
        if (diag_sum1 == 0) {
            printf("Diagonal 1 is complete!\n");
        }
        if (diag_sum2 == 0) {
            printf("Diagonal 2 is complete!\n");
        }
    }

    // End the game
    printf("BINGO!\n");
    return 0;
}