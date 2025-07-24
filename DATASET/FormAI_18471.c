//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

// function to check if the specified bingo pattern is complete
int check_bingo(int bingo_pattern[ROWS][COLS]) {
    int i, j;
    int count = 0;

    // check rows for a complete pattern
    for (i = 0; i < ROWS; i++) {
        count = 0;
        for (j = 0; j < COLS; j++) {
            if (bingo_pattern[i][j] == 0) {
                count++;
            }
        }
        if (count == 5) {
            return 1;
        }
    }

    // check columns for a complete pattern
    for (i = 0; i < COLS; i++) {
        count = 0;
        for (j = 0; j < ROWS; j++) {
            if (bingo_pattern[j][i] == 0) {
                count++;
            }
        }
        if (count == 5) {
            return 1;
        }
    }

    // check diagonals for a complete pattern
    count = 0;
    for (i = 0, j = 0; i < ROWS && j < COLS; i++, j++) {
        if (bingo_pattern[i][j] == 0) {
            count++;
        }
    }
    if (count == 5) {
        return 1;
    }

    count = 0;
    for (i = 0, j = 4; i < ROWS && j >= 0; i++, j--) {
        if (bingo_pattern[i][j] == 0) {
            count++;
        }
    }
    if (count == 5) {
        return 1;
    }

    return 0;
}

int main() {
    int bingo_pattern[ROWS][COLS] = {0};
    int i, j;
    int num;

    srand(time(NULL));

    // randomly allocate numbers in the bingo pattern
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            num = rand() % 15 + 1 + j * 15; // generate a random number between 1 and 15, 16 and 30, 31 and 45 ...
            bingo_pattern[i][j] = num;
        }
    }

    // mark the center as free
    bingo_pattern[2][2] = 0;

    // print the bingo pattern
    printf("\tB\tI\tN\tG\tO\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("\t");
            if (bingo_pattern[i][j] == 0) {
                printf("FREE");
            } else {
                printf("%d", bingo_pattern[i][j]);
            }
        }
        printf("\n");
    }

    // play bingo
    int number;
    int flag = 0;
    int count = 0;
    while (flag == 0) {
        printf("Enter a number (1-75): ");
        scanf("%d", &number);

        if (number <= 0 || number > 75) { // validate the input
            printf("Invalid input. Enter a number between 1 and 75.\n");
            continue;
        }

        // mark the number in the bingo pattern
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                if (bingo_pattern[i][j] == number) {
                    bingo_pattern[i][j] = 0;
                    count++;
                    break;
                }
            }
        }

        // check if the pattern is complete
        if (check_bingo(bingo_pattern) == 1) {
            printf("BINGO!!\n");
            flag = 1;
            break;
        }

        // print the updated bingo pattern
        printf("\tB\tI\tN\tG\tO\n");
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                printf("\t");
                if (bingo_pattern[i][j] == 0) {
                    printf("FREE");
                } else {
                    printf("%d", bingo_pattern[i][j]);
                }
            }
            printf("\n");
        }
    }

    printf("You won the game in %d attempts!\n", count);

    return 0;
}