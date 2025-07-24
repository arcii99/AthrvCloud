//FormAI DATASET v1.0 Category: Game of Life ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define ROWS 20
#define COLS 40

int grid[ROWS][COLS];

int neighbors(int r, int c) {
    int count = 0;
    for (int i=r-1; i<=r+1; i++) {
        for (int j=c-1; j<=c+1; j++) {
            int row = (i + ROWS) % ROWS;
            int col = (j + COLS) % COLS;
            if (grid[row][col] == 1 && (i != r || j != c)) {
                count++;
            }
        }
    }
    return count;
}

void update() {
    int next[ROWS][COLS];
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            int count = neighbors(i, j);
            if (grid[i][j] == 1 && (count < 2 || count > 3)) {
                next[i][j] = 0;
            }
            else if (grid[i][j] == 0 && count == 3) {
                next[i][j] = 1;
            }
            else {
                next[i][j] = grid[i][j];
            }
        }
    }
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            grid[i][j] = next[i][j];
        }
    }
}

void display() {
    printf("\033[2J\033[%d;%dH", 0, 0);
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            if (grid[i][j] == 1) {
                printf("\033[07m  \033[m");
            }
            else {
                printf("  ");
            }
        }
        printf("\n");
    }
    fflush(stdout);
}

int main(int argc, char *argv[]) {
    srand(time(NULL));
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            if ((rand()%100) < 20) {
                grid[i][j] = 1;
            }
            else {
                grid[i][j] = 0;
            }
        }
    }
    while (1) {
        display();
        update();
        usleep(100000);
    }
    return 0;
}