//FormAI DATASET v1.0 Category: Memory Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void printGrid(int grid[ROWS][COLS], int reveal[ROWS][COLS]) {
    printf("  1 2 3 4 \n");
    for (int i=0; i<ROWS; i++) {
        printf("%c ", 'A' + i);
        for (int j=0; j<COLS; j++) {
            if (reveal[i][j] == 1) {
                printf("%d ", grid[i][j]);
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(0));
    int grid[ROWS][COLS], reveal[ROWS][COLS];
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            grid[i][j] = 0;
            reveal[i][j] = 0;
        }
    }
    for (int k=0; k<8; k++) {
        int i, j;
        do {
            i = rand() % ROWS;
            j = rand() % COLS;
        } while (grid[i][j] != 0);
        grid[i][j] = k + 1;
        do {
            i = rand() % ROWS;
            j = rand() % COLS;
        } while (grid[i][j] != 0);
        grid[i][j] = k + 1;
    }
    int count = 0, maxCount = ROWS * COLS / 2, score = 0;
    while (count < maxCount) {
        printGrid(grid, reveal);
        printf("Enter the position of card 1 (e.g. A1): ");
        char pos1[2];
        scanf("%s", pos1);
        int row1 = pos1[0] - 'A', col1 = pos1[1] - '1';
        reveal[row1][col1] = 1;
        printGrid(grid, reveal);
        printf("Enter the position of card 2 (e.g. A1): ");
        char pos2[2];
        scanf("%s", pos2);
        int row2 = pos2[0] - 'A', col2 = pos2[1] - '1';
        reveal[row2][col2] = 1;
        if (grid[row1][col1] == grid[row2][col2]) {
            count++;
            score++;
            printf("Match found! Score: %d\n", score);
        } else {
            reveal[row1][col1] = 0;
            reveal[row2][col2] = 0;
            score--;
            printf("No match! Score: %d\n", score);
        }
    }
    printf("Congratulations! You have completed the game with a score of %d.\n", score);
    return 0;
}