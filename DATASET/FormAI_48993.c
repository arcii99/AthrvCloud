//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

int main() {
    srand(time(NULL));
    int board[ROWS][COLS];
    int nums[75];
    int numCount = 0;
    int bingo = 0;
    int lastCall;

    // Initialize Board
    for(int r = 0; r < ROWS; r++) {
        for(int c = 0; c < COLS; c++) {
            board[r][c] = 0;
        }
    }

    // Initialize Num Array
    for(int i = 0; i < 75; i++) {
        nums[i] = i + 1;
    }

    // Shuffle Num Array
    for(int i = 0; i < 74; i++) {
        int j = rand() % 75;
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    // Bingo Game Loop
    while(!bingo) {
        // Clear Screen
        system("clear");

        // Print Board
        printf("   B  I  N  G  O\n");
        for(int r = 0; r < ROWS; r++) {
            for(int c = 0; c < COLS; c++) {
                if(board[r][c]) {
                    printf("| X ");
                } else {
                    printf("| %2d", nums[lastCall]);
                }
                lastCall = nums[lastCall] == 0 ? lastCall + 1 : lastCall;
            }
            printf("|\n");
        }

        // Get Next Number
        printf("\nPress Enter to call next number.");
        getchar();
        if(numCount == 75) {
            break;
        }
        lastCall = numCount++;
        int numIndex = nums[lastCall] - 1;

        // Check for Bingo
        for(int r = 0; r < ROWS; r++) {
            for(int c = 0; c < COLS; c++) {
                if(board[r][c]) {
                    continue;
                }
                if((r == 2 && c == 2) || (r == c && r + c == 4)) {
                    continue;
                }
                if(nums[numIndex] == (r * 15) + (c + 1)) {
                    board[r][c] = 1;
                    goto foundNum;
                }
            }
        }
        foundNum:

        // Check for Bingo
        for(int r = 0; r < ROWS; r++) {
            int rowSum = 0;
            for(int c = 0; c < COLS; c++) {
                rowSum += board[r][c];
            }
            if(rowSum == 5) {
                bingo = 1;
                break;
            }

            int colSum = 0;
            for(int c = 0; c < COLS; c++) {
                colSum += board[c][r];
            }
            if(colSum == 5) {
                bingo = 1;
                break;
            }
        }

        // Diagonal Bingo Check
        if(board[0][0] && board[1][1] && board[3][3] && board[4][4]) {
            bingo = 1;
        }
        if(board[0][4] && board[1][3] && board[3][1] && board[4][0]) {
            bingo = 1;
        }
    }

    // Print Final Board and Message
    system("clear");
    printf("   B  I  N  G  O\n");
    for(int r = 0; r < ROWS; r++) {
        for(int c = 0; c < COLS; c++) {
            if(board[r][c]) {
                printf("| X ");
            } else {
                printf("| %2d", nums[lastCall]);
            }
            lastCall = nums[lastCall] == 0 ? lastCall + 1 : lastCall;
        }
        printf("|\n");
    }

    if(bingo) {
        printf("\nBINGO! Congratulations, you won!\n");
    } else {
        printf("\nSorry, you have no more numbers left.\n");
    }

    return 0;
}