//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 25
#define HEIGHT 25

// Function declarations
void generateMaze(char maze[HEIGHT][WIDTH]);
void printMaze(char maze[HEIGHT][WIDTH]);

int main() {
    char maze[HEIGHT][WIDTH];

    // Set maze to all walls
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i % 2 == 0 || j % 2 == 0) {
                maze[i][j] = '#';
            } else {
                maze[i][j] = ' ';
            }
        }
    }

    srand(time(NULL));
    generateMaze(maze);
    printMaze(maze);

    return 0;
}

void generateMaze(char maze[HEIGHT][WIDTH]) {
    // Set start and end locations
    int startX = 1;
    int startY = 1;
    int endX = HEIGHT - 2;
    int endY = WIDTH - 2;
    int currentX = startX;
    int currentY = startY;

    // Create stack for backtracking
    int stackX[WIDTH * HEIGHT];
    int stackY[WIDTH * HEIGHT];
    int stackIndex = 0;

    // Mark start as visited
    maze[currentX][currentY] = 'S';

    // Loop until end is found
    while (currentX != endX || currentY != endY) {
        // Check neighbors
        int neighbors[4][2] = {{currentX - 2, currentY}, {currentX, currentY + 2},
                               {currentX + 2, currentY}, {currentX, currentY - 2}};
        int unvisitedNeighbors[4][2];
        int numUnvisitedNeighbors = 0;
        for (int i = 0; i < 4; i++) {
            int neighborX = neighbors[i][0];
            int neighborY = neighbors[i][1];
            if (neighborX >= 0 && neighborX < HEIGHT &&
                neighborY >= 0 && neighborY < WIDTH && maze[neighborX][neighborY] == ' ') {
                unvisitedNeighbors[numUnvisitedNeighbors][0] = neighborX;
                unvisitedNeighbors[numUnvisitedNeighbors][1] = neighborY;
                numUnvisitedNeighbors++;
            }
        }

        // If there are unvisited neighbors, choose one at random and remove wall
        if (numUnvisitedNeighbors > 0) {
            int randomIndex = rand() % numUnvisitedNeighbors;
            int neighborX = unvisitedNeighbors[randomIndex][0];
            int neighborY = unvisitedNeighbors[randomIndex][1];
            maze[(currentX + neighborX) / 2][(currentY + neighborY) / 2] = ' ';
            stackX[stackIndex] = currentX;
            stackY[stackIndex] = currentY;
            stackIndex++;
            currentX = neighborX;
            currentY = neighborY;
            maze[currentX][currentY] = '.';
            // If no unvisited neighbors, backtrack
        } else {
            stackIndex--;
            currentX = stackX[stackIndex];
            currentY = stackY[stackIndex];
        }
    }

    // Mark end
    maze[endX][endY] = 'E';
}

void printMaze(char maze[HEIGHT][WIDTH]) {
    printf("\nDetective, the maze has been generated!\n\n");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
    printf("\nEnd of maze, Sherlock!\n");
}