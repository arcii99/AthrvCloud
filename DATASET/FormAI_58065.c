//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 15

int main()
{
    int maze[HEIGHT][WIDTH];
    
    // srand() function sets the seed value for our random number generator
    srand(time(NULL));
    
    // Initialize the maze to all walls
    for (int i = 0; i < HEIGHT; ++i)
        for (int j = 0; j < WIDTH; ++j)
            maze[i][j] = 1;
    
    // Choose a random starting point
    int startX = rand() % WIDTH;
    int startY = rand() % HEIGHT;
    
    // Make the starting point the entrance
    maze[startY][startX] = 0;
    
    // Carve out the maze using a recursive function
    // Pass in the starting point and the maze array
    generateMaze(startX, startY, maze);
    
    // Print out the maze
    for (int i = 0; i < HEIGHT; ++i)
    {
        for (int j = 0; j < WIDTH; ++j)
        {
            if (maze[i][j] == 1)
                printf("#");
            else if (maze[i][j] == 0)
                printf(" ");
        }
        printf("\n");
    }
    
    return 0;
}

// Recursive function to generate the maze
void generateMaze(int x, int y, int maze[][WIDTH])
{
    // Four directions to move in
    int directions[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    // Shuffle the directions array randomly
    shuffle(directions, 4);
    
    // For each direction, check if we can move there
    for (int i = 0; i < 4; ++i)
    {
        int newX = x + directions[i][0] * 2;
        int newY = y + directions[i][1] * 2;
        
        if (newX > 0 && newX < WIDTH - 1 && newY > 0 && newY < HEIGHT - 1 && maze[newY][newX] == 1)
        {
            // Carve a path to the new location
            maze[y + directions[i][1]][x + directions[i][0]] = 0;
            maze[newY][newX] = 0;
            
            // Recursively call the function with the new location
            generateMaze(newX, newY, maze);
        }
    }
}

// Function to shuffle an array randomly
void shuffle(int arr[][2], int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        int j = rand() % (size - i) + i;
        int temp[2] = {arr[j][0], arr[j][1]};
        arr[j][0] = arr[i][0];
        arr[j][1] = arr[i][1];
        arr[i][0] = temp[0];
        arr[i][1] = temp[1];
    }
}