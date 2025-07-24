//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: multivariable
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 25    // Define the size of the maze
#define EMPTY ' '       // Define the empty space character
#define WALL '#'        // Define the wall character

// Procedurally generates a maze
void generateMaze(char maze[MAZE_SIZE][MAZE_SIZE])
{
    int i, j;
    int row = 1, col = 1;
    int visited[MAZE_SIZE][MAZE_SIZE] = { 0 };
    int cellsVisited = 1;

    // Set all the walls
    for (i = 0; i < MAZE_SIZE; i++) {
        for (j = 0; j < MAZE_SIZE; j++) {
            maze[i][j] = WALL;
        }
    }

    // Mark the starting cell as visited
    visited[row][col] = true;

    // Loop until all cells have been visited
    while (cellsVisited < MAZE_SIZE * MAZE_SIZE) {
        // Create an array of the unvisited neighbors
        int neighbors[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
        int numNeighbors = 4;

        if (row == 1) {
            neighbors[0][0] = neighbors[0][1] = -1;
            numNeighbors--;
        }
        if (row == MAZE_SIZE - 2) {
            neighbors[2][0] = neighbors[2][1] = -1;
            numNeighbors--;
        }
        if (col == 1) {
            neighbors[3][0] = neighbors[3][1] = -1;
            numNeighbors--;
        }
        if (col == MAZE_SIZE - 2) {
            neighbors[1][0] = neighbors[1][1] = -1;
            numNeighbors--;
        }

        // Remove visited neighbors from the array
        for (i = 0; i < numNeighbors; i++) {
            int x = row + neighbors[i][0];
            int y = col + neighbors[i][1];
            if (visited[x][y]) {
                numNeighbors--;
                neighbors[i][0] = neighbors[numNeighbors][0];
                neighbors[i][1] = neighbors[numNeighbors][1];
                i--;
            }
        }

        // If there are unvisited neighbors, select one at random
        if (numNeighbors > 0) {
            int r = rand() % numNeighbors;
            int x = row + neighbors[r][0];
            int y = col + neighbors[r][1];

            // Carve a path to the selected neighbor
            if (neighbors[r][0] == -1) {
                maze[x+1][y] = EMPTY;
            } else if (neighbors[r][1] == 1) {
                maze[x][y-1] = EMPTY;
            } else if (neighbors[r][0] == 1) {
                maze[x-1][y] = EMPTY;
            } else if (neighbors[r][1] == -1) {
                maze[x][y+1] = EMPTY;
            }

            // Mark the selected neighbor as visited
            visited[x][y] = true;
            cellsVisited++;

            // Update the current cell
            row = x;
            col = y;
        } else {
            // Backtrack to a cell with unvisited neighbors
            int found = false;
            for (i = 1; i < MAZE_SIZE - 1 && !found; i += 2) {
                for (j = 1; j < MAZE_SIZE - 1; j += 2) {
                    if (visited[i][j]) {
                        int num = 0;
                        if (!visited[i-1][j])
                            num++;
                        if (!visited[i][j+1])
                            num++;
                        if (!visited[i+1][j])
                            num++;
                        if (!visited[i][j-1])
                            num++;
                        if (num > 1) {
                            row = i;
                            col = j;
                            found = true;
                            break;
                        }
                    }
                }
            }
        }
    }

    // Set the start and end points
    maze[1][0] = EMPTY;
    maze[MAZE_SIZE-2][MAZE_SIZE-1] = EMPTY;
}

int main()
{
    char maze[MAZE_SIZE][MAZE_SIZE];
    int i, j;

    // Seed the random number generator
    srand(time(NULL));

    // Generate the maze
    generateMaze(maze);

    // Print the maze
    for (i = 0; i < MAZE_SIZE; i++) {
        for (j = 0; j < MAZE_SIZE; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }

    return 0;
}