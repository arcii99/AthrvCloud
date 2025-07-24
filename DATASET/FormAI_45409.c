//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

int main() {
    int board[ROWS][COLS];
    int i, j, k, l;
    int nums[76];
    int temp;

    srand(time(NULL));

    //initialize board with zeros
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            board[i][j] = 0;
        }
    }

    //initialize nums array with numbers 1-75
    for(i = 0; i < 75; i++) {
        nums[i] = i + 1;
    }

    //shuffle nums array
    for(i = 0; i < 75; i++) {
        j = rand() % 75;
        k = nums[i];
        nums[i] = nums[j];
        nums[j] = k;
    }

    //game loop
    while(1) {
        printf("Press Enter to draw a number\n");
        getchar();

        //draw a number and mark matching spots on board
        temp = nums[0];
        for(i = 0; i < ROWS; i++) {
            for(j = 0; j < COLS; j++) {
                if(board[i][j] == temp) {
                    board[i][j] = -temp;
                }
            }
        }

        //print board
        printf("\n B   I   N   G   O\n");
        for(i = 0; i < ROWS; i++) {
            for(j = 0; j < COLS; j++) {
                if(board[i][j] < 0) {
                    printf(" X ");
                } else if(board[i][j] == 0) {
                    printf(" - ");
                } else {
                    printf("%2d ", board[i][j]);
                }
            }
            printf("\n");
        }

        //check for win
        for(i = 0; i < ROWS; i++) {
            //check row
            if(board[i][0] < 0 && board[i][1] < 0 && board[i][2] < 0 && board[i][3] < 0 && board[i][4] < 0) {
                printf("\nBingo! Row %d\n", i+1);
                return 0;
            }
            //check column
            if(board[0][i] < 0 && board[1][i] < 0 && board[2][i] < 0 && board[3][i] < 0 && board[4][i] < 0) {
                printf("\nBingo! Column %d\n", i+1);
                return 0;
            }
            //check diagonal
            if(i == 0) {
                if(board[i][i] < 0 && board[i+1][i+1] < 0 && board[i+2][i+2] < 0 && board[i+3][i+3] < 0 && board[i+4][i+4] < 0) {
                    printf("\nBingo! Diagonal from top-left to bottom-right\n");
                    return 0;
                }
                if(board[i][i+4] < 0 && board[i+1][i+3] < 0 && board[i+2][i+2] < 0 && board[i+3][i+1] < 0 && board[i+4][i] < 0) {
                    printf("\nBingo! Diagonal from top-right to bottom-left\n");
                    return 0;
                }
            }
        }

        //remove drawn number from nums array
        for(i = 0; i < 75; i++) {
            if(nums[i] == temp) {
                for(j = i; j < 74; j++) {
                    nums[j] = nums[j+1];
                }
                nums[74] = 0;
                break;
            }
        }

        //check for end of game
        if(nums[0] == 0) {
            printf("\nGame over\n");
            return 0;
        }
    }

    return 0;
}