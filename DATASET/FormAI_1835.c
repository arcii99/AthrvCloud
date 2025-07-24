//FormAI DATASET v1.0 Category: Fractal Generation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// define constants for the fractal
#define SIZE 800
#define MAX_ITERATIONS 100000
#define INITIAL_VALUE 1

// define global variables
int fractal[SIZE][SIZE] = {0};
int current_iteration = INITIAL_VALUE;
int x, y;

// function to initialize the fractal with a single point in the center
void init_fractal() {
    fractal[SIZE/2][SIZE/2] = INITIAL_VALUE;
}

// function to calculate the next iteration for a given point
int calculate_iteration(int x, int y) {
    int value = 0;
    // check if the point is within the fractal by checking the values of the surrounding points
    if (fractal[x-1][y-1] == current_iteration-1) {
        value++;
    }
    if (fractal[x-1][y] == current_iteration-1) {
        value++;
    }
    if (fractal[x-1][y+1] == current_iteration-1) {
        value++;
    }
    if (fractal[x][y-1] == current_iteration-1) {
        value++;
    }
    if (fractal[x][y+1] == current_iteration-1) {
        value++;
    }
    if (fractal[x+1][y-1] == current_iteration-1) {
        value++;
    }
    if (fractal[x+1][y] == current_iteration-1) {
        value++;
    }
    if (fractal[x+1][y+1] == current_iteration-1) {
        value++;
    }
    // if the point is surrounded by 3 or more points from the previous iteration, it is included in the new iteration
    if (value >= 3) {
        return current_iteration;
    }
    return 0;
}

// function to generate a new iteration of the fractal
void generate_iteration() {
    // loop through all points in the fractal and calculate the next iteration for each point
    for (x = 1; x < SIZE-1; x++) {
        for (y = 1; y < SIZE-1; y++) {
            fractal[x][y] = calculate_iteration(x, y);
        }
    }
    // increment the current iteration counter
    current_iteration++;
}

// function to print the fractal to the console
void print_fractal() {
    for (x = 0; x < SIZE; x++) {
        for (y = 0; y < SIZE; y++) {
            if (fractal[x][y] > 0) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// main function
int main() {
    // initialize the fractal
    init_fractal();
    while (current_iteration < MAX_ITERATIONS) {
        // generate a new iteration and print the fractal
        generate_iteration();
        print_fractal();
    }
    return 0;
}