//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define N 10    // Number of rows and columns
#define MAX_SPEED 5 // Maximum speed of vehicle

// Arrays to keep track of vehicle positions and speeds
int x_positions[N], y_positions[N], speeds[N];

// Function to populate starting positions and speeds of vehicles
void initial_positions()
{
    srand(time(NULL));  // Seed random number generator

    for(int i=0; i<N; i++)
    {
        // Random starting position
        x_positions[i] = rand() % N;
        y_positions[i] = rand() % N;

        // Random speed
        speeds[i] = rand() % (MAX_SPEED + 1);
    }
}

// Function to display current positions and speeds of vehicles
void display_positions()
{
    printf("\nCurrent Positions and Speeds:\n\n");

    for(int i=0; i<N; i++)
    {
        printf("Vehicle %d: x=%d, y=%d, speed=%d\n", i+1, x_positions[i], y_positions[i], speeds[i]);
    }
}

// Function to update positions of vehicles based on their speeds
void update_positions()
{
    // Loop through each vehicle
    for(int i=0; i<N; i++)
    {
        // Calculate new position based on speed
        x_positions[i] += speeds[i];
        y_positions[i] += speeds[i];

        // If the vehicle goes off the grid, reset its position
        if(x_positions[i] < 0 || x_positions[i] >= N || y_positions[i] < 0 || y_positions[i] >= N)
        {
            x_positions[i] = rand() % N;
            y_positions[i] = rand() % N;
        }
    }
}

int main()
{
    // Initialize starting positions and speeds
    initial_positions();

    // Display starting positions and speeds
    display_positions();

    // Loop through 10 time steps and update positions
    for(int time=1; time<=10; time++)
    {
        printf("\nTime Step %d:\n", time);

        // Update positions
        update_positions();

        // Display new positions and speeds
        display_positions();
    }

    return 0;
}