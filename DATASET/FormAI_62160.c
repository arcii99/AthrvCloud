//FormAI DATASET v1.0 Category: Game of Life ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ROWS 25
#define COLS 80

char grid[ROWS][COLS];

void init_grid() {
    // Initialize the grid with a pattern
}

void print_grid() {
    // Print the grid to the console
}

void update_grid() {
    // Update the state of the cells based on the rules
}

int main() {
    int generations = 0;
    init_grid();

    while (1) {
        system("clear"); // Clear the console
        printf("Generation: %d\n", generations);
        print_grid();
        update_grid();
        usleep(100000); // Pause for 0.1 seconds
        generations++;
    }

    return 0;
}