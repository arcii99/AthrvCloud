//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_RAND 75

// Function to check if all cells are marked
int check_bingo(int arr[][COLS]) {
    int i, j, count;

    // check rows
    for (i = 0; i < ROWS; i++) {
        count = 0;
        for (j = 0; j < COLS; j++) {
            if (arr[i][j] != -1) {
                count++;
                break;
            }
        }
        if (count == 0)
            return 1;
    }

    // check columns
    for (i = 0; i < COLS; i++) {
        count = 0;
        for (j = 0; j < ROWS; j++) {
            if (arr[j][i] != -1) {
                count++;
                break;
            }
        }
        if (count == 0)
            return 1;
    }

    // check diagonal from left to right
    count = 0;
    for (i = 0; i < ROWS; i++) {
        if (arr[i][i] != -1) {
            count++;
            break;
        }
    }
    if (count == 0)
        return 1;

    // check diagonal from right to left
    count = 0;
    for (i = 0; i < ROWS; i++) {
        if (arr[i][COLS - i - 1] != -1) {
            count++;
            break;
        }
    }
    if (count == 0)
        return 1;

    return 0;
}

int main() {
    int arr[ROWS][COLS], i, j, num, count = 0, index;
    int bingo_count = 0;
    int bingo[5];

    srand(time(NULL));

    // Initialize array with all cells to -1
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            arr[i][j] = -1;
        }
    }

    // Generate random numbers until there is a bingo
    while (bingo_count < 5) {
        num = rand() % MAX_RAND + 1;

        printf("The generated random number is: %d\n", num);

        // Check if the number already exists in the array
        count = 0;
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                if (arr[i][j] == num) {
                    printf("%d already exists in the array.\n", num);
                    count = 1;
                    break;
                }
            }
            if (count == 1)
                break;
        }

        if (count == 0) {
            // update the array with the new number
            for (i = 0; i < ROWS; i++) {
                for (j = 0; j < COLS; j++) {
                    if (arr[i][j] == -1) {
                        arr[i][j] = num;
                        break;
                    }
                }
                if (j < COLS)
                    break;
            }

            // Check if there is bingo
            if (check_bingo(arr) == 1) {
                printf("BINGO! Number %d marks a bingo.\n", num);
                bingo[bingo_count] = num;
                bingo_count++;
            }
        }
    }

    // Print the bingo numbers
    printf("The bingo numbers are:\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", bingo[i]);
    }

    return 0;
}