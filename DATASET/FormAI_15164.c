//FormAI DATASET v1.0 Category: Game of Life ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40

int world[ROWS][COLS];
int new_world[ROWS][COLS];

void print_world();

int main() {
    printf("Welcome to the Game of Life!\n");

    srand(time(0));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            world[i][j] = rand() % 2;
        }
    }

    print_world();

    for (int iter = 1; 1; iter++) {
        printf("Iteration #%d:\n", iter);

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                int alive_neighbors = 0;
                for (int m = -1; m <= 1; m++) {
                    for (int n = -1; n <= 1; n++) {
                        if (m == 0 && n == 0) continue;
                        if (world[(i + m + ROWS) % ROWS][(j + n + COLS) % COLS]) {
                            alive_neighbors += 1;
                        }
                    }
                }
                if (world[i][j]) {
                    if (alive_neighbors < 2 || alive_neighbors > 3) {
                        new_world[i][j] = 0;
                    } else {
                        new_world[i][j] = 1;
                    }
                } else {
                    if (alive_neighbors == 3) {
                        new_world[i][j] = 1;
                    } else {
                        new_world[i][j] = 0;
                    }
                }
            }
        }

        int is_stable = 1;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (world[i][j] != new_world[i][j]) {
                    is_stable = 0;
                    world[i][j] = new_world[i][j];
                }
            }
        }

        if (is_stable) {
            printf("World has stabilized! Press any key to exit.\n");
            getchar();
            return 0;
        }

        print_world();

        printf("Press any key to continue.\n");
        getchar();
    }

    return 0;
}

void print_world() {
    printf("+");
    for (int j = 0; j < COLS; j++) {
        printf("-");
    }
    printf("+\n");

    for (int i = 0; i < ROWS; i++) {
        printf("|");
        for (int j = 0; j < COLS; j++) {
            if (world[i][j]) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("|\n");
    }

    printf("+");
    for (int j = 0; j < COLS; j++) {
        printf("-");
    }
    printf("+\n");
}