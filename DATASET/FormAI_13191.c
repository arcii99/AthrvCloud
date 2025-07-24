//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: decentralized
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define WIDTH 20
#define HEIGHT 10

// Maze cell struct
typedef struct {
    int topWall, rightWall, bottomWall, leftWall, visited;
} Cell;

// Initialize maze grid and walls
void initializeMaze(Cell maze[WIDTH][HEIGHT]) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            maze[i][j].topWall = 1;
            maze[i][j].rightWall = 1;
            maze[i][j].bottomWall = 1;
            maze[i][j].leftWall = 1;
            maze[i][j].visited = 0;
        }
    }
}

// Print out the maze
void printMaze(Cell maze[WIDTH][HEIGHT]) {
    // Print top wall of top row
    printf("+");
    for (int i = 0; i < WIDTH; i++) {
        printf("---+");
    }
    printf("\n");

    for (int j = 0; j < HEIGHT; j++) {
        printf("|"); // Initial left wall
        for (int i = 0; i < WIDTH; i++) {
            // Print bottom wall if it exists
            if (maze[i][j].bottomWall == 1) {
                printf("   |");
            } else {
                printf("    ");
            }
        }
        printf("\n+");

        for (int i = 0; i < WIDTH; i++) {
            // Print right wall if it exists
            if (maze[i][j].rightWall == 1) {
                printf("---+");
            } else {
                printf("   +");
            }
        }
        printf("\n");
    }
}

// Recursive function to generate the maze
void generateMaze(Cell maze[WIDTH][HEIGHT], int x, int y) {
    maze[x][y].visited = 1;

    // Create array of unvisited neighbors
    int neighbors[4][2] = {{x-1, y}, {x, y-1}, {x+1, y}, {x, y+1}};
    int unvisitedNeighbors[4][2];
    int numUnvisitedNeighbors = 0;

    for (int i = 0; i < 4; i++) {
        int nx = neighbors[i][0];
        int ny = neighbors[i][1];

        if (nx >= 0 && nx < WIDTH && ny >= 0 && ny < HEIGHT && maze[nx][ny].visited == 0) {
            unvisitedNeighbors[numUnvisitedNeighbors][0] = nx;
            unvisitedNeighbors[numUnvisitedNeighbors][1] = ny;
            numUnvisitedNeighbors++;
        }
    }

    while (numUnvisitedNeighbors > 0) {
        // Choose a random unvisited neighbor
        int randIndex = rand() % numUnvisitedNeighbors;
        int nx = unvisitedNeighbors[randIndex][0];
        int ny = unvisitedNeighbors[randIndex][1];

        // Remove the wall between current cell and neighbor
        if (nx == x) {
            if (ny > y) {
                maze[x][y].bottomWall = 0;
                maze[nx][ny].topWall = 0;
            } else {
                maze[x][y].topWall = 0;
                maze[nx][ny].bottomWall = 0;
            }
        } else {
            if (nx > x) {
                maze[x][y].rightWall = 0;
                maze[nx][ny].leftWall = 0;
            } else {
                maze[x][y].leftWall = 0;
                maze[nx][ny].rightWall = 0;
            }
        }
        
        // Recursively generate the maze from the neighbor cell
        generateMaze(maze, nx, ny);

        // Remove neighbor from array of unvisited neighbors
        for (int i = randIndex; i < numUnvisitedNeighbors-1; i++) {
            unvisitedNeighbors[i][0] = unvisitedNeighbors[i+1][0];
            unvisitedNeighbors[i][1] = unvisitedNeighbors[i+1][1];
        }
        numUnvisitedNeighbors--;
    }
}

int main() {
    srand(time(NULL));

    // Create maze
    Cell maze[WIDTH][HEIGHT];
    initializeMaze(maze);
    generateMaze(maze, 0, 0);

    // Print maze
    printMaze(maze);

    return 0;
}