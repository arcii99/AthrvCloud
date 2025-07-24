//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: genious
// GPS Navigation Simulation Program
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10 // Size of grid for navigation

// Function to display navigation grid
void display_grid(int grid[][GRID_SIZE], int x, int y)
{
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (i == x && j == y)
                printf("X "); // Current position marker
            else
                printf("%d ", grid[i][j]); // Display grid values
        }
        printf("\n");
    }
}

// Function to simulate movement
void move(int grid[][GRID_SIZE], int* x, int* y)
{
    int direction = rand() % 4; // Choose random direction to move

    // Update position based on direction
    switch (direction) {
        case 0:
            if (*x > 0) (*x)--; // Move up
            break;
        case 1:
            if (*x < GRID_SIZE - 1) (*x)++; // Move down
            break;
        case 2:
            if (*y > 0) (*y)--; // Move left
            break;
        case 3:
            if (*y < GRID_SIZE - 1) (*y)++; // Move right
            break;
    }

    // Update grid value at new position
    grid[*x][*y]++;
}

int main()
{
    srand(time(NULL)); // Seed random number generator

    int grid[GRID_SIZE][GRID_SIZE] = {0}; // Initialize grid values to zero
    int x = 0, y = 0; // Initialize starting position to (0,0)

    printf("Starting navigation...\n");

    // Simulate movement for 50 steps
    for (int i = 0; i < 50; i++) {
        move(grid, &x, &y);
        display_grid(grid, x, y);
        printf("\n");
    }

    printf("Navigation complete!\n");

    return 0;
}