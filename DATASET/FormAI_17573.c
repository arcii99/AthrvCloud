//FormAI DATASET v1.0 Category: Game of Life ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 60

int space[ROWS][COLS];

void print_board() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (space[i][j])
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    usleep(50000);
    system("clear");
}

int count_live_neighbors(int row, int col) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (!(i == 0 && j == 0) && row+i >= 0 && col+j >= 0 && row+i < ROWS && col+j < COLS && space[row+i][col+j])
                count++;
        }
    }
    return count;
}

void update_board() {
    int new_space[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int live_neighbors = count_live_neighbors(i, j);
            if (space[i][j] && (live_neighbors == 2 || live_neighbors == 3))
                new_space[i][j] = 1;
            else if (!space[i][j] && live_neighbors == 3)
                new_space[i][j] = 1;
            else
                new_space[i][j] = 0;
        }
    }
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            space[i][j] = new_space[i][j];
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            space[i][j] = rand() % 2;

    while (1) {
        print_board();
        update_board();
    }
    return 0;
}