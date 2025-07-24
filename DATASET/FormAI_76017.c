//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10
#define NUM_ITERATIONS 1000

char world[GRID_SIZE][GRID_SIZE];

void generate_initial_world() {
    srand(time(NULL));
    for(int i = 0; i < GRID_SIZE; i++) {
        for(int j = 0; j < GRID_SIZE; j++) {
            if(rand() % 2 == 0) {
                world[i][j] = '#'; // Wall
            } else {
                world[i][j] = '.'; // Empty space
            }
        }
    }
}

void print_world() {
    for(int i = 0; i < GRID_SIZE; i++) {
        for(int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", world[i][j]);
        }
        printf("\n");
    }
}

int count_neighbors(int i, int j) {
    int count = 0;
    for(int x = i-1; x <= i+1; x++) {
        for(int y = j-1; y <= j+1; y++) {
            if(x == i && y == j) continue;
            if(x < 0 || x >= GRID_SIZE || y < 0 || y >= GRID_SIZE) continue;
            if(world[x][y] == '#') count++;
        }
    }
    return count;
}

void update_world() {
    char new_world[GRID_SIZE][GRID_SIZE];
    for(int i = 0; i < GRID_SIZE; i++) {
        for(int j = 0; j < GRID_SIZE; j++) {
            int neighbors = count_neighbors(i, j);
            if(world[i][j] == '#') {
                if(neighbors < 2 || neighbors > 3) {
                    new_world[i][j] = '.'; // Wall dies due to under- or over-population
                } else {
                    new_world[i][j] = '#'; // Wall lives to see another day
                }
            } else {
                if(neighbors == 3) {
                    new_world[i][j] = '#'; // Wall is born due to reproduction
                } else {
                    new_world[i][j] = '.'; // Wall remains empty
                }
            }
        }
    }
    // Update world with new state
    for(int i = 0; i < GRID_SIZE; i++) {
        for(int j = 0; j < GRID_SIZE; j++) {
            world[i][j] = new_world[i][j];
        }
    }
}

int main() {
    generate_initial_world();

    printf("Initial world:\n");
    print_world();

    for(int i = 0; i < NUM_ITERATIONS; i++) {
        update_world();
    }

    printf("Final world:\n");
    print_world();

    return 0;
}