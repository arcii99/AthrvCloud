//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX 25

int main() {
    int board[ROWS][COLS] = { { 0 } };
    int nums[MAX] = { 0 };
    int count = 0;
    int num = 0;
    srand(time(NULL));

    // Generate Unique Numbers
    for(int i=0; i<MAX; i++) {
        nums[i] = i+1;
    }
    for(int i=0; i<MAX; i++) {
        int j = rand() % MAX;
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    // Begin Game
    printf("Welcome to Bingo Simulator\n\n");
    while(count < MAX) {
        printf("Press Enter to Draw a Number\n");
        getchar();
        num = nums[count];
        for(int i=0; i<ROWS; i++) {
            for(int j=0; j<COLS; j++) {
                if(board[i][j] == num) {
                    board[i][j] = -1; // mark as called
                }
            }
        }
        printf("Number Drawn: %d\n\n", num);

        // Print Board
        printf("  B  I  N  G  O \n");
        for(int i=0; i<ROWS; i++) {
            printf("|");
            for(int j=0; j<COLS; j++) {
                if(board[i][j] == -1) {
                    printf(" X |");
                } else {
                    printf(" %2d |", board[i][j]);
                }
            }
            printf("\n");
        }
        printf("\n");

        // Check for Bingo
        int bingo = 0;
        for(int i=0; i<ROWS; i++) {
            int row_sum = 0;
            int col_sum = 0;
            for(int j=0; j<COLS; j++) {
                row_sum += board[i][j];
                col_sum += board[j][i];
            }
            if(row_sum == -5 || col_sum == -5) {
                bingo = 1;
                break;
            }
        }
        int diag_sum = 0;
        int reverse_diag_sum = 0;
        for(int i=0; i<ROWS; i++) {
            diag_sum += board[i][i];
            reverse_diag_sum += board[4-i][i];
        }
        if(diag_sum == -5 || reverse_diag_sum == -5) {
            bingo = 1;
        }
        if(bingo) {
            printf("BINGO! You've Won!\n");
            break;
        }
        count++;
    }

    if(count == MAX) {
        printf("Sorry, You've Lost!\n");
    }

    return 0;
}