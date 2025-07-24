//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_NUM 75

int main() {
    int i, j, num, row, col;
    int bingo[ROWS][COLS] = {0};
    int nums[MAX_NUM] = {0};

    srand(time(NULL));

    // Generate unique numbers between 1 and 75
    for (i = 0; i < MAX_NUM; i++) {
        num = rand() % MAX_NUM + 1;
        while (nums[num-1]) {
            num = rand() % MAX_NUM + 1;
        }
        nums[num-1] = 1;
    }

    // Set the center cell as 'FREE'
    bingo[ROWS/2][COLS/2] = -1;

    // Print out the Bingo Board
    printf("\tB\tI\tN\tG\tO\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (bingo[i][j] == -1) {
                printf("\tFREE");
            } else {
                printf("\t%d", bingo[i][j]);
            }
        }
        printf("\n");
    }

    // Start the Bingo Game
    printf("\nPress enter to play BINGO!\n");
    getchar();

    // Generate random numbers until there is a Bingo
    while (1) {
        num = nums[rand() % MAX_NUM];
        printf("\n\nThe next number is... %d\n", num);

        // Check for the number in the Bingo Board
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                if (bingo[i][j] == num) {
                    bingo[i][j] = -1;
                }
            }
        }

        // Print out the updated Bingo Board
        printf("\tB\tI\tN\tG\tO\n");
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                if (bingo[i][j] == -1) {
                    printf("\tFREE");
                } else {
                    printf("\t%d", bingo[i][j]);
                }
            }
            printf("\n");
        }

        // Check for a win
        // Check Horizontal Rows
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                if (bingo[i][j] != -1) {
                    break;
                }
            }
            if (j == COLS) {
                printf("\nBINGO! You won on row %d!\n", i+1);
                return 0;
            }
        }

        // Check Vertical Columns
        for (j = 0; j < COLS; j++) {
            for (i = 0; i < ROWS; i++) {
                if (bingo[i][j] != -1) {
                    break;
                }
            }
            if (i == ROWS) {
                printf("\nBINGO! You won on column %d!\n", j+1);
                return 0;
            }
        }

        // Check Diagonal Cells
        if ((bingo[0][0] == -1 && bingo[1][1] == -1 && bingo[2][2] == -1 && bingo[3][3] == -1 && bingo[4][4] == -1)
            || (bingo[4][0] == -1 && bingo[3][1] == -1 && bingo[2][2] == -1 && bingo[1][3] == -1 && bingo[0][4] == -1)) {
            printf("\nBINGO! You won on a diagonal!\n");
            return 0;
        }

        printf("\nPress enter for the next number...\n");
        getchar();
    }

    return 0;
}