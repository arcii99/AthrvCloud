//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLUMNS 5
#define MAX_NUM 25

// Function to check if number already exists in array
int check_number(int num, int arr[][COLUMNS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            if (arr[i][j] == num) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int i, j, num, count = 0;
    int bingo[ROWS][COLUMNS];

    // Initialize random number generator
    srand(time(NULL));

    // Initialize bingo array with zeros
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            bingo[i][j] = 0;
        }
    }

    // Draw random numbers and fill in bingo array
    while (count < MAX_NUM) {
        num = rand() % MAX_NUM + 1;
        if (!check_number(num, bingo)) {
            printf("Drawing number: %d\n", num);
            for (i = 0; i < ROWS; i++) {
                for (j = 0; j < COLUMNS; j++) {
                    if (bingo[i][j] == 0 && num == ((i * COLUMNS) + j + 1)) {
                        bingo[i][j] = num;
                        count++;
                        break;
                    }
                }
            }
        }
    }

    // Print out bingo array
    printf("\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            printf("%d\t", bingo[i][j]);
        }
        printf("\n");
    }

    return 0;
}