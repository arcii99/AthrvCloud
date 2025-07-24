//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: statistical
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROWS 5  // number of rows in the bingo card
#define COLS 5  // number of columns in the bingo card
#define MAX_NUM 75  // maximum possible number in the game

int main() {
    // initialize the bingo card
    int card[ROWS][COLS] = {0};

    // fill in the bingo card with random numbers
    srand( time(NULL) );
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int num;
            do {
                num = rand() % MAX_NUM + 1;
            } while (card[i][j] == num);
            card[i][j] = num;
        }
    }

    // print out the bingo card
    printf("BINGO CARD:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%2d ", card[i][j]);
        }
        printf("\n");
    }

    // initialize the game counter
    int count = 0;

    // play the game until someone wins
    while (1) {
        int num;
        do {
            num = rand() % MAX_NUM + 1;
        } while (num < 1 || num > MAX_NUM);
        printf("Number called: %2d\n", num);
        count++;

        // check if any number on the card matches the called number
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (card[i][j] == num) {
                    card[i][j] = 0;
                }
            }
        }

        // check for bingo
        int bingo = 0;
        // check rows
        for (int i = 0; i < ROWS; i++) {
            int row_sum = 0;
            for (int j = 0; j < COLS; j++) {
                row_sum += card[i][j];
            }
            if (row_sum == 0) {
                bingo = 1;
                break;
            }
        }
        if (bingo) {
            printf("BINGO after %d numbers called!\n", count);
            break;
        }
        // check columns
        for (int i = 0; i < COLS; i++) {
            int col_sum = 0;
            for (int j = 0; j < ROWS; j++) {
                col_sum += card[j][i];
            }
            if (col_sum == 0) {
                bingo = 1;
                break;
            }
        }
        if (bingo) {
            printf("BINGO after %d numbers called!\n", count);
            break;
        }
        // check diagonals
        int diag1_sum = 0, diag2_sum = 0;
        for (int i = 0; i < ROWS; i++) {
            diag1_sum += card[i][i];
            diag2_sum += card[i][COLS-i-1];
        }
        if (diag1_sum == 0 || diag2_sum == 0) {
            bingo = 1;
        }
        if (bingo) {
            printf("BINGO after %d numbers called!\n", count);
            break;
        }
    }

    return 0;
}