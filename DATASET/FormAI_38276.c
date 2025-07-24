//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 20

void createMaze(int maze[][MAZE_SIZE], int startRow, int startCol);
void printMaze(int maze[][MAZE_SIZE]);

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Create the maze matrix
    int maze[MAZE_SIZE][MAZE_SIZE];
    
    // Initialize all cells to be "blocked"
    for (int row = 0; row < MAZE_SIZE; row++) {
        for (int col = 0; col < MAZE_SIZE; col++) {
            maze[row][col] = 1;
        }
    }
    
    // Start generating the maze from the middle cell
    createMaze(maze, MAZE_SIZE/2, MAZE_SIZE/2);
    
    // Print the maze
    printMaze(maze);
    
    return 0;
}

void createMaze(int maze[][MAZE_SIZE], int startRow, int startCol)
{
    // Mark the starting cell as "open"
    maze[startRow][startCol] = 0;

    // Create an array of directions to choose from randomly
    int directions[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
    // Shuffle the directions randomly
    for (int i = 0; i < 4; i++) {
        int randomIndex = rand() % 4;
        int tempRow = directions[i][0];
        int tempCol = directions[i][1];
        directions[i][0] = directions[randomIndex][0];
        directions[i][1] = directions[randomIndex][1];
        directions[randomIndex][0] = tempRow;
        directions[randomIndex][1] = tempCol;
    }

    // Iterate over the directions array
    for (int i = 0; i < 4; i++) {
        // Calculate the new row and column based on the current direction
        int newRow = startRow + (2 * directions[i][0]);
        int newCol = startCol + (2 * directions[i][1]);

        // Check if the new cell is within the maze boundaries and is blocked
        if (newRow >= 0 && newRow < MAZE_SIZE && newCol >= 0 && newCol < MAZE_SIZE && maze[newRow][newCol] == 1) {
            // Open the wall between the current cell and the new cell
            maze[startRow + directions[i][0]][startCol + directions[i][1]] = 0;
            maze[newRow][newCol] = 0;

            // Recursively generate the maze from the new cell
            createMaze(maze, newRow, newCol);
        }
    }
}

void printMaze(int maze[][MAZE_SIZE])
{
    for (int row = 0; row < MAZE_SIZE; row++) {
        for (int col = 0; col < MAZE_SIZE; col++) {
            // Print "X" for blocked cells and " " (space) for open cells
            printf("%c", maze[row][col] == 1 ? 'X' : ' ');
        }
        printf("\n");
    }
}