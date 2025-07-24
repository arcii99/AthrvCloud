//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_NUM 75

int main () {
    int bingo[ROWS][COLS] = {0};
    int numList[MAX_NUM] = {0};
    int numCount = 0;

    srand(time(NULL));

    // fill up numList array with numbers from 1 to 75
    for (int i = 0; i < MAX_NUM; i++) {
        numList[i] = i + 1;
    }

    // shuffle the numList array
    for (int i = 0; i < MAX_NUM; i++) {
        int j = rand() % MAX_NUM;
        int temp = numList[i];
        numList[i] = numList[j];
        numList[j] = temp;
    }

    // generate bingo card
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == 2 && j == 2) { // free space in the center
                continue;
            }
            bingo[i][j] = numList[numCount];
            numCount++;
        }
    }

    // print out bingo card
    printf("  B   I   N   G   O\n");
    for (int i = 0; i < ROWS; i++) {
        printf("-------------------\n");
        for (int j = 0; j < COLS; j++) {
            if (bingo[i][j] < 10) {
                printf("| %d ", bingo[i][j]);
            } else {
                printf("|%d ", bingo[i][j]);
            }
        }
        printf("|\n");
    }
    printf("-------------------\n");

    return 0;
}