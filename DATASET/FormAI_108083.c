//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_NUM 25

int main() {
    int bingo_board[ROWS][COLS];
    int nums_drawn[MAX_NUM];
    int num_drawn, num_checks;

    srand(time(NULL));

    // initialize board
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            bingo_board[i][j] = i * COLS + j + 1;
        }
    }
    
    // shuffle board
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int rand_row = rand() % ROWS;
            int rand_col = rand() % COLS;
            int temp = bingo_board[i][j];
            
            bingo_board[i][j] = bingo_board[rand_row][rand_col];
            bingo_board[rand_row][rand_col] = temp;
        }
    }

    // game loop
    while(1) {
        // draw a number
        num_drawn = rand() % MAX_NUM + 1;
        num_checks = 0;

        // check if number already drawn
        while (num_checks < MAX_NUM) {
            if (nums_drawn[num_checks] == num_drawn) {
                // number already drawn, draw again
                num_drawn = rand() % MAX_NUM + 1;
                num_checks = 0;
            }
            num_checks++;
        }
        
        // update drawn numbers array
        nums_drawn[num_checks] = num_drawn;

        // check if number is on board
        int bingo_found = 0;
        for (int i = 0; i < ROWS && !bingo_found; i++) {
            for (int j = 0; j < COLS; j++) {
                if (bingo_board[i][j] == num_drawn) {
                    // number found on board
                    bingo_board[i][j] = -1;
                    bingo_found = 1;
                    break;
                }
            }
        }

        // print current board
        printf("\nBINGO BOARD:\n");
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (bingo_board[i][j] == -1) {
                    printf("  ");
                } else {
                     printf("%2d ", bingo_board[i][j]);
                }
            }
            printf("\n");
        }

        // check for bingo
        int row_sum, col_sum;
        // check rows
        for (int i = 0; i < ROWS; i++) {
            row_sum = 0;
            for (int j = 0; j < COLS; j++) {
                row_sum += bingo_board[i][j];
            }
            if (row_sum == -COLS) {
                printf("\nBINGO! Row %d\n", i+1);
                return 0;
            }
        }
        // check columns
        for (int j = 0; j < COLS; j++) {
            col_sum = 0;
            for (int i = 0; i < ROWS; i++) {
                col_sum += bingo_board[i][j];
            }
            if (col_sum == -ROWS) {
                printf("\nBINGO! Column %d\n", j+1);
                return 0;
            }
        }
    }

    return 0;
}