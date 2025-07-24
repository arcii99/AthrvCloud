//FormAI DATASET v1.0 Category: Game of Life ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the world
#define WORLD_SIZE 20

// Define the maximum number of generations for our simulation
#define MAX_GENERATIONS 50

// Define the number of random initial live cells
#define INITIAL_LIVE_CELLS 30

// Function to initialize the world randomly
void initialize_world(int world[WORLD_SIZE][WORLD_SIZE])
{
    // Initialize the random number generator
    srand(time(NULL));
    
    // Randomly assign the initial live cells
    int i, j, live_cells = 0;
    while (live_cells < INITIAL_LIVE_CELLS)
    {
        i = rand() % WORLD_SIZE;
        j = rand() % WORLD_SIZE;
        if (world[i][j] != 1)
        {
            world[i][j] = 1;
            live_cells++;
        }
    }
}

// Function to print the current state of the world
void print_world(int world[WORLD_SIZE][WORLD_SIZE])
{
    int i, j;
    for (i = 0; i < WORLD_SIZE; i++)
    {
        for (j = 0; j < WORLD_SIZE; j++)
        {
            if (world[i][j] == 0)
            {
                printf(".");
            }
            else
            {
                printf("O");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Function to count the number of live cells in the neighborhood (Moore's neighborhood)
int count_live_cells(int i, int j, int world[WORLD_SIZE][WORLD_SIZE])
{
    int count = 0;
    count += world[(i-1+WORLD_SIZE)%WORLD_SIZE][(j-1+WORLD_SIZE)%WORLD_SIZE];
    count += world[(i-1+WORLD_SIZE)%WORLD_SIZE][j];
    count += world[(i-1+WORLD_SIZE)%WORLD_SIZE][(j+1)%WORLD_SIZE];
    count += world[i][(j-1+WORLD_SIZE)%WORLD_SIZE];
    count += world[i][(j+1)%WORLD_SIZE];
    count += world[(i+1)%WORLD_SIZE][(j-1+WORLD_SIZE)%WORLD_SIZE];
    count += world[(i+1)%WORLD_SIZE][j];
    count += world[(i+1)%WORLD_SIZE][(j+1)%WORLD_SIZE];
    return count;
}

// Function to simulate one generation
void simulate_generation(int world[WORLD_SIZE][WORLD_SIZE])
{
    int new_world[WORLD_SIZE][WORLD_SIZE] = {0};
    int i, j;
    for (i = 0; i < WORLD_SIZE; i++)
    {
        for (j = 0; j < WORLD_SIZE; j++)
        {
            int live_cells = count_live_cells(i, j, world);
            if (world[i][j] == 1) // If the cell is alive
            {
                if (live_cells == 2 || live_cells == 3) // It stays alive
                {
                    new_world[i][j] = 1;
                }
            }
            else // If the cell is dead
            {
                if (live_cells == 3) // It becomes alive
                {
                    new_world[i][j] = 1;
                }
            }
        }
    }
    // Update the world
    for (i = 0; i < WORLD_SIZE; i++)
    {
        for (j = 0; j < WORLD_SIZE; j++)
        {
            world[i][j] = new_world[i][j];
        }
    }
}

int main()
{
    int world[WORLD_SIZE][WORLD_SIZE] = {0};
    initialize_world(world);
    int generation;
    for (generation = 1; generation <= MAX_GENERATIONS; generation++)
    {
        printf("Generation %d:\n", generation);
        print_world(world);
        simulate_generation(world);
    }
    return 0;
}