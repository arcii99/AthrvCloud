//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

int grid[N][N];
int filled[N][N];

int do_percolation(int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= N) {
        return 0;
    }
    if (filled[x][y] || grid[x][y] == 0) {
        return 0;
    }
    filled[x][y] = 1;
    do_percolation(x+1, y);
    do_percolation(x-1, y);
    do_percolation(x, y+1);
    do_percolation(x, y-1);
    return 1;
}

int is_percolating() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            filled[i][j] = 0;
        }
    }
    for (int i = 0; i < N; i++) {
        if (do_percolation(0, i)) {
            return 1;
        }
    }
    return 0;
}

void print_grid() {
    printf("+");
    for (int i = 0; i < N; i++) {
        printf("-");
    }
    printf("+\n");
    for (int i = 0; i < N; i++) {
        printf("|");
        for (int j = 0; j < N; j++) {
            if (grid[i][j]) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("|\n");
    }
    printf("+");
    for (int i = 0; i < N; i++) {
        printf("-");
    }
    printf("+\n");
}

void generate_grid() {
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if ((rand() % 100) < 40) {
                grid[i][j] = 1;
            } else {
                grid[i][j] = 0;
            }
        }
    }
}

int main() {
    generate_grid();
    print_grid();
    printf("Is percolating: %d\n", is_percolating());
    return 0;
}