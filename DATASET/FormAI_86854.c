//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 20

// Definition of Cell struct that represents each individual cell in the maze
typedef struct {
    int visited;    // Flag to check if the cell has been visited or not
    int walls[4];   // Array to keep track of the walls (up, down, left, right)
} Cell;

// Function to randomly shuffle an integer array
void shuffle(int *arr, int n)
{
    srand(time(NULL));
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
    }
}

// Function to recursively generate the maze
void generateMaze(Cell maze[][MAZE_SIZE], int currX, int currY)
{
    maze[currX][currY].visited = 1;

    // Define an array of all possible directions (up, down, left, right) 
    int directions[] = {0, 1, 2, 3};
    shuffle(directions, 4);

    // Loop through all possible directions and visit the neighboring cell if possible
    for (int i = 0; i < 4; i++) {
        int nextX = currX, nextY = currY;

        // Condition to move up
        if (directions[i] == 0 && currY > 0) {
            nextY = currY - 1;
            if (!maze[nextX][nextY].visited) {
                maze[currX][currY].walls[0] = 0;    // Remove the upper wall of the current cell
                maze[nextX][nextY].walls[1] = 0;    // Remove the lower wall of the neighbor cell
                generateMaze(maze, nextX, nextY);
            }
        }

        // Condition to move down
        else if (directions[i] == 1 && currY < MAZE_SIZE - 1) {
            nextY = currY + 1;
            if (!maze[nextX][nextY].visited) {
                maze[currX][currY].walls[1] = 0;    // Remove the lower wall of the current cell
                maze[nextX][nextY].walls[0] = 0;    // Remove the upper wall of the neighbor cell
                generateMaze(maze, nextX, nextY);
            }
        }

        // Condition to move left
        else if (directions[i] == 2 && currX > 0) {
            nextX = currX - 1;
            if (!maze[nextX][nextY].visited) {
                maze[currX][currY].walls[2] = 0;    // Remove the left wall of the current cell
                maze[nextX][nextY].walls[3] = 0;    // Remove the right wall of the neighbor cell
                generateMaze(maze, nextX, nextY);
            }
        }

        // Condition to move right
        else if (directions[i] == 3 && currX < MAZE_SIZE - 1) {
            nextX = currX + 1;
            if (!maze[nextX][nextY].visited) {
                maze[currX][currY].walls[3] = 0;    // Remove the right wall of the current cell
                maze[nextX][nextY].walls[2] = 0;    // Remove the left wall of the neighbor cell
                generateMaze(maze, nextX, nextY);
            }
        }
    }
}

// Function to print the maze
void printMaze(Cell maze[][MAZE_SIZE])
{
    for (int i = 0; i < MAZE_SIZE; i++) {
        printf(" _");    // Print the top wall of each cell in the first row
    }
    printf("\n");

    for (int i = 0; i < MAZE_SIZE; i++) {
        printf("|");    // Print the left wall of each cell in the first column
        for (int j = 0; j < MAZE_SIZE; j++) {
            if (maze[i][j].walls[0]) {
                printf("_");    // Print the top wall of the current cell if it exists
            } else {
                printf(" ");
            }

            if (maze[i][j].walls[3]) {
                printf("|");    // Print the right wall of the current cell if it exists
            } else {
                printf(" ");
            }
        }
        printf("\n");

        // Print the bottom wall of each cell
        printf("|");
        for (int j = 0; j < MAZE_SIZE; j++) {
            if (maze[i][j].walls[1]) {
                printf("_");    // Print the bottom wall of the current cell if it exists
            } else {
                printf(" ");
            }

            printf("|");    // Print the right wall of the neighboring cell (i, j+1) if it exists
        }
        printf("\n");
    }
}

int main()
{
    Cell maze[MAZE_SIZE][MAZE_SIZE];

    // Initialize each cell with all four walls
    for(int i = 0; i < MAZE_SIZE; i++) {
        for(int j=0; j < MAZE_SIZE; j++) {
            maze[i][j].visited = 0;
            for(int k=0; k < 4; k++) {
                maze[i][j].walls[k] = 1;
            }
        }
    }

    // Call the generateMaze function to generate the maze
    generateMaze(maze, 0, 0);

    // Call the printMaze function to print the maze
    printMaze(maze);

    return 0;
}