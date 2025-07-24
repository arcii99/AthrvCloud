//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the percolation map width and height
#define WIDTH 20
#define HEIGHT 20

// Define the symbols used to represent open and blocked cells
#define OPEN '.'
#define BLOCKED '#'

char percolation_map[WIDTH][HEIGHT];

// Method for initializing the percolation map with random values
void initialize_map() {
    srand(time(NULL)); // Seed the random number generator with the current time
    for(int i=0;i<WIDTH;i++) {
        for(int j=0;j<HEIGHT;j++) {
            double random_number = (double)rand() / (double)RAND_MAX;
            if(random_number < 0.6) {
                percolation_map[i][j] = OPEN;
            } else {
                percolation_map[i][j] = BLOCKED;
            }
        }
    }
}

// Method for printing the percolation map to the console
void print_map() {
    for(int i=0;i<WIDTH;i++) {
        for(int j=0;j<HEIGHT;j++) {
            printf("%c", percolation_map[i][j]);
        }
        printf("\n");
    }
}

// Method for checking if the percolation reaches the bottom of the map
int percolates() {
    int reached_bottom = 0;
    for(int i=0;i<WIDTH;i++) {
        if(percolation_map[HEIGHT-1][i] == OPEN) {
            reached_bottom = 1;
            break;
        }
    }
    return reached_bottom;
}

int main() {
    // Initialize the percolation map
    initialize_map();

    // Print the initial percolation map to the console
    printf("Initial Percolation Map:\n");
    print_map();

    // Loop until percolation occurs
    int steps = 0;
    while(!percolates()) {
        // Choose a random cell to open
        int i = rand() % WIDTH;
        int j = rand() % HEIGHT;

        // If the cell is blocked, open it
        if(percolation_map[i][j] == BLOCKED) {
            percolation_map[i][j] = OPEN;
        }

        // Print the updated percolation map to the console
        printf("\nStep %d:\n", ++steps);
        print_map();
    }

    // Print the final percolation map and the number of steps taken
    printf("\nFinal Percolation Map:\n");
    print_map();
    printf("\nPercolation reached in %d steps\n", steps);

    return 0;
}