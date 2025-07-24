//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

// function to print the system
void print_system(int system[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (system[i][j] == 1)
                printf("# ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

// function to set all values to 0
void clear_system(int system[SIZE][SIZE], int value) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            system[i][j] = value;
        }
    }
}

// function to check if a point is valid
int is_valid_point(int x, int y) {
    return x >= 0 && x < SIZE && y >= 0 && y < SIZE;
}

// recursive function to perform percolation
void percolate(int system[SIZE][SIZE], int x, int y) {
    if (!is_valid_point(x, y)) {
        return;
    }

    if (system[x][y] != 1) {
        return;
    }

    // change the site to "percolated"
    system[x][y] = 2;

    // check all neighbors
    percolate(system, x+1, y);
    percolate(system, x-1, y);
    percolate(system, x, y+1);
    percolate(system, x, y-1);
}

int main() {
    // seed the random number generator
    srand(time(NULL));

    // create the initial system
    int system[SIZE][SIZE];
    clear_system(system, 0);

    // randomly set some values to 1
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (rand() % 2 == 0) {
                system[i][j] = 1;
            }
        }
    }

    // print the initial system
    printf("Initial system:\n");
    print_system(system);

    // perform percolation
    percolate(system, 0, 0);

    // print the final system
    printf("Final system:\n");
    print_system(system);

    return 0;
}