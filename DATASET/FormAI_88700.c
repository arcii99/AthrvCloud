//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLUMNS 5
#define MAX_NUM 75

int main() {
    int card[ROWS][COLUMNS];
    int i, j, k, num, count = 0, bingo = 0;

    srand(time(NULL));
    printf("Welcome to the Bingo Simulator!\n");

    // generate random numbers and add them to the bingo card
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            num = rand() % MAX_NUM + 1;
            // check if the number is already on the card
            for (k = 0; k < count; k++) {
                if (num == card[k / COLUMNS][k % COLUMNS]) {
                    num = rand() % MAX_NUM + 1;
                    k = -1;
                }
            }
            card[i][j] = num;
            count++;
        }
    }

    // print out the bingo card
    printf("\nHere's your bingo card:\n");
    printf("-----------------------\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            printf("%2d ", card[i][j]);
        }
        printf("\n");
    }
    printf("-----------------------\n\n");

    // simulate the bingo game
    printf("Let's simulate the bingo game!\n");
    while (bingo == 0) {
        num = rand() % MAX_NUM + 1;
        printf("The number called is: %d\n", num);
        // check if the number is on the card
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLUMNS; j++) {
                if (num == card[i][j]) {
                    card[i][j] = 0; // mark the number as called
                    printf("Match found!\n");
                }
            }
        }
        // check for bingo
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLUMNS; j++) {
                if (card[i][j] != 0) {
                    break; // not all numbers have been called yet
                }
            }
            if (j == COLUMNS) {
                printf("Bingo!\n");
                bingo = 1;
                break;
            }
        }
    }
    return 0;
}