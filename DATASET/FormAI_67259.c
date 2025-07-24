//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
void printMap(char map[10][10]);
void initMap(char map[10][10]);
void placeObstacles(char map[10][10], int num_obstacles);

int main()
{
    char rc_map[10][10]; // Map to simulate RC vehicle movement
    
    // Set seed for random function
    srand(time(NULL));
    
    // Initialize the map
    initMap(rc_map);
    
    // Place obstacles randomly on the map
    placeObstacles(rc_map, 10);
    
    // Print the initial state of the map
    printMap(rc_map);
    
    return 0;
}

// Function to print the map
void printMap(char map[10][10])
{
    printf("RC Vehicle Simulation\n");
    printf("---------------------\n\n");
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to initialize the map
void initMap(char map[10][10])
{
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            map[i][j] = '_'; // Empty space
        }
    }
}

// Function to randomly place obstacles on the map
void placeObstacles(char map[10][10], int num_obstacles)
{
    int x, y;
    for(int i = 0; i < num_obstacles; i++)
    {
        x = rand() % 10; // Generate a random x coordinate
        y = rand() % 10; // Generate a random y coordinate
        if(map[x][y] != 'O')
        {
            map[x][y] = 'O'; // Place obstacle at (x,y) if empty
        }
        else
        {
            i--; // Try again if (x,y) already has an obstacle
        }
    }
}